//the implementation file for the map loader class
#include "MapLoader.h"
#include "../Lib/GameSetupFunctions.h"
#include <fstream>
#include "../Lib/Exceptions/DirectoryNotFoundException.h"

std::string MapLoader::filePath = ""; //initialize filePath to an empty string
int MapLoader::nodeCount = 0; //initialize the nodeCount to 0
Graph<std::string>* MapLoader::map = NULL; //initialize the graph to NULL

void MapLoader::setFilePath(std::string path)
{
  //method to set the filepath for the map
  MapLoader::filePath = path;
}

std::string MapLoader::getFilePath()
{
  //method to get the filepath of the map
  return MapLoader::filePath;
}

void MapLoader::loadMap()
{
  //method to load the map file into a graph object
  //IMPORTANT!!! The master node, i.e. manhattan, must appear first in the file

  bool result = false;
  bool validDirectory = false;
  std::string directory = ""; //the path to the maps directory

  while(!result)
  {
    //we first need to allow the player to select a map from a list of available files in the directory of his choice
    //let's set that choice
    validDirectory = false;
    while(!validDirectory)
    {
      //while the player has not entered a valid directory, we should keep going
      //we ask the player to enter the path to a directory
      std::cout << "Please enter the name of the directory where the maps are stored: ";
      std::getline(std::cin, directory);

      try
      {
        GameSetupFunctions::setMap(directory);
      }

      catch(DirectoryNotFoundException e)
      {
        //if the directory does not exist, let the player know
        //and try again
        std::cout << e.what() << std::endl;
        validDirectory = false;
        continue;
      }

      catch(int)
      {
        //if the directory contained no files, then we are here
        std::cout << "The directory was empty." << std::endl;
        validDirectory = false;
        continue;
      }

      validDirectory = true;
    }

    if(fileIsValid())
    {
      //if the file was valid then we set up the graph object by reading all of the data in the file and assigning nodes
      std::cout << "Setting up the game board..." << std::endl;

      Graph<std::string>* graph = new Graph<std::string>(MapLoader::nodeCount);

      //we need to reopen the file

      std::ifstream input; //the input stream associated to out file
      input.open(MapLoader::filePath.c_str()); //try opening the file

      //we already know it is valid so we can start reading right away
      std::string line = "";
      std::string nodeName = "";
      std::string nodeType = "";
      int graphIndex = 0;

      //while we still have readable lines
      while(input >> line)
      {
        //first get the name of the node
        if(line == "@node")
        {
          //wipe the nodeName and nodeType clean
          nodeName = "";
          nodeType = "";

          //if the line is the node declaration
          //then go to the next line and the line after that, where the name field is
          input >> line;
          input >> line;

          //now that we are at the name field we read until we hit adjacent node
          while(input >> line && line != "type:")
          {
            nodeName = nodeName + line + " ";
          }

          //now we need to get the type of node that it is
          while(input >> line && line != "adjacent:")
          {
            nodeType = nodeType + line;
          }

          //since we add a space at the end, we need to trim the right side
          nodeName.erase(nodeName.find_last_not_of(" \n\r\t")+1);
          //now that we have the name of the node, we need to add it to our graph
          graph -> setVertexName(nodeName, graphIndex);
          graph -> setVertexData(nodeType, graphIndex);

          //now that we have added the name of the node we need to add every node it is adjacent to to its adjacency list

          std::string newNeighbor = ""; //the string that will hold the name of the new neighbor to the node

          //while we have not reached a closing brace, keep reading
          while(input >> line && line != "}")
          {
            //if the line contains the word adjacent, then skip that word
            if(line == "adjacent:")
            {
              newNeighbor.erase(newNeighbor.find_last_not_of(" \n\r\t")+1);
              graph -> addNeighbor(newNeighbor, graphIndex); //add the new neighbor
              newNeighbor = ""; //wipe the newNeighbor field and then continue the iteration
              continue;
            }

            else
            {
              newNeighbor += line + " ";
            }
          }

          graphIndex++;
        }
      }

      map = graph;
      graph = NULL;
      result = true;
    }

    else
    {
      //if the file was not valid then we need to try again
      result = false;
    }
  }

}

bool MapLoader::fileIsValid()
{
  //method to check if the file is valid

  //before doing anything, check if the file path contains a .map extension
  std::string mapExt = ".map";

  if(filePath.find(mapExt) == std::string::npos)
  {
    std::cerr << "The file requested does not contain a .map extension." << std::endl;
    return false;
  }


  //first we will attempt to open the file

  std::ifstream input; //the input stream associated to out file
  input.open(MapLoader::filePath.c_str()); //try opening the file

  if(!input)
  {
    //if the input file could not be opened, then that means that the input file is not valid
    //therefore close the stream and return false
    input.close();
    std::cerr << "The file at " << filePath << " could not be opened." << std::endl;
    return false;
  }

  //if we passed this point, it means that the file is open

  //we need to check each node to make sure that it is correctly formed
  int nodeCount = 0; //the count of the number of nodes in the file
  int lineNumber = 0; //the line we are at

  //now we need to count the number of times the word "@node" is contained in the file
  std::string line = ""; //the current line being read
  while(input >> line) //while the input stream still has lines to read keep reading
  {
    lineNumber++;

    if(line == "@node") //if the line is equal to "@node", this is the inclusion of another node
    {
      nodeCount++;
      //now we know that we are at the beginning of a node declaration
      //check the next line to see if it is a "{"
      input >> line;
      lineNumber++;
      if(line != "{")
      {
        input.close();
        std::cout << "Missing opening brace in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

      //then check if the line after that contains a name field
      input >> line;
      lineNumber++;
      if(line != "name:")
      {
        input.close();
        std::cout << "Missing node name field in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false; //if the next line does not contain a name field then we return false
      }

      //then check if the line after that contains a type field
      while(line != "type:" && !(line == "adjacent:" || line == "}"))
      {
        input >> line;
        lineNumber++;
      }

      if(line != "type:")
      {
        input.close();
        std::cout << "Missing type field in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

      //then check that the type is valid
      input >> line;
      lineNumber++;
      if(!(line == "master" || line == "inner" || line == "outer"))
      {
        input.close();
        std::cout << "Invalid type field in file " << filePath << " near line " << lineNumber << "." << std::endl;
      }

      //now we need to make sure that the node has at least one adjacent node to make sure that the graph will be a connected graph
      int adjacentCount = 0;
      while(input >> line && line != "}")
      {
        lineNumber++;
        if(line == "adjacent:")
        {
          adjacentCount ++;
        }
      }

      //if by the end of the loop the adjacent count is still zero, then the file is not valid
      if(adjacentCount == 0)
      {
        input.close();
        std::cout << "No adjacent nodes found in " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

      //now that we have reached the last adjacent node, check if the current line contains a "}"
      if(line != "}")
      {
        input.close();
        std::cout << "Missing closing brace in file " << filePath << " near line " << lineNumber << "." << std::endl;
        return false;
      }

    }

  }

  //if we made it to this point without returning, then that means the file is valid and we return true
  //as long as there is more than one node
  if(nodeCount > 0)
  {
    input.close();
    MapLoader::nodeCount = nodeCount;
    return true;
  }

  //if there was not more than one node, then return false;
  input.close();
  return false;

}

Graph<std::string>* MapLoader::getMap()
{
  return map;
}
