#include <iostream>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "MusicTree.h"
#include <sstream> 

using namespace std;
using namespace rapidxml;

//Constructor Class. Makes a new Tree with a NULL root
MusicTree::MusicTree()
{
	roo = NULL;
}

 
void MusicTree::addSongNode(string artist, string name, string album)
{
	SongNode *temp = roo;
  SongNode *node = new SongNode(artist, name, album);
	SongNode *parent = temp;
	 
	while(temp != NULL)
	{
		parent = temp;
		string str1 = node->artist;
		string str2 = temp->artist;
		
		if(str1.compare(str2) < 0)
	  {
	  	temp = temp->left;
	  }
	  else  
	  {
	  	temp = temp->right;
	  }
	}

	if(parent == NULL)
	{
		//cout << "new root" << endl;
	  roo = node;
	}
	else if (node->artist.compare(parent->artist) < 0) {
	    parent->left = node;
	    node->parent = parent;
	    //cout << "inserted: " << node->name << " left child of: " << parent->name <<endl;
	} 
	else {
	    parent->right = node; 
	    node->parent = parent;
	    //cout << "inserted: " << node->name << " right child of: " << parent->name <<endl;
	}
	
}

//Checks for a specific Artist in the Tree by comparing the search str to each node then continuing left or right after comparison until found
void MusicTree::checkForArtist(string artist)
{
	SongNode *node = roo;
	while(node != NULL)
  {
		if(node->artist.compare(artist) < 0)
		{
		  node = node->right;
    }
		else if (node->artist.compare(artist) > 0)
		{
		  node = node->left;
		} 
		else 
		{
			cout << "Songs by " << node->artist << " found in the Music Tree"<< endl;
			return;
		}
	}
	cout << "Artist not found." << endl;
}

//Public method that calls the private recursive method
void MusicTree::printMusicLibrary()
{
	printMusicLibrary(roo);
}

//Private function that goes through and counts each element of the Tree Recursivly starting at the paramater node.
int MusicTree::countSongNodes(SongNode *node)
{
	if(node == NULL) { 
		return 0;
	} else { 
		return countSongNodes(node->left) + countSongNodes(node->right) + 1;
	}
}

//Public Function that calls the root
int MusicTree::countSongNodes()
{
	return countSongNodes(roo);
}

//Private recursive method that goes through the entire Tree and prints data from each node
//It only prints the song and artist because I found the contents to difficult to read with the album too
void MusicTree::printMusicLibrary(SongNode *node)
{
	if (node) {
	  printMusicLibrary(node->left);
		cout<<node->name<<" by "<<node->artist<<endl;
    printMusicLibrary(node->right);
	}
}

//Pulic Function to find song with root as param
void MusicTree::findSong(string name)
{
	findSong(roo,name);
}

//Recursive Private function to find song in Tree, looks at entire tree
void MusicTree::findSong(SongNode *node, string name)
{
	if(node)
	{
		if(node->name == name)
		{
			cout << "Song Info:" << endl;
			cout << "===========" << endl;
			cout << "Artist:" << node->artist << endl;
			cout << "Name:" << node->name << endl;
			cout << "Album:" << node->album << endl;
			return;
		}
		else
		{
			findSong(node->left, name);
			findSong(node->right, name);
		}
	}
}

//Pulic Function that calls the private with root as node param
void MusicTree::printAlbum(string album)
{
	printAlbum(roo,album);
}

//Private recursive function to search entire Tree for nodes with matching album name
void MusicTree::printAlbum(SongNode *node, string album)
{
	if(node)
	{
		if(node->album == album)
		{			
			cout << "-> " << node->name << " by ";
			cout << node->artist << endl;
			printAlbum(node->left, album);
			printAlbum(node->right, album);
		}
		else
		{
			printAlbum(node->left, album);
			printAlbum(node->right, album);
		}
	}
}

//Uses Rapid XML to parse XML Library File into individual Song Nodes before adding them to the Tree
void MusicTree::populateXML()
{
	//Accsess Document using RAPIDXML	
  xml_document<> doc; 
  file<> xmlFile("iTunesMusicLibrary.xml"); 
  doc.parse<0>(xmlFile.data());
		
	//Gets through level of Nodes to get to media data
	xml_node<> *lib = doc.first_node("plist");
	xml_node<> *dict = lib->first_node("dict");
	xml_node<> *dict1 = dict->first_node("dict");
	
	//Counts number of songs added
	int count = 0;
	
	//Loops through elements containting indvidual media items
	for (xml_node<> *mediaDict = dict1->first_node("dict"); mediaDict; mediaDict = mediaDict->next_sibling("dict"))
	{
		//set the first and last key of the media items meta data
		xml_node<> *key = mediaDict->first_node("key");
		xml_node<> *lastkey = mediaDict->last_node("key");
		
		//Initilize media variables
		SongNode *song = new SongNode();
		
		//Loops through intantces of media item
		bool check = true;
		while(check == true)
		{
			xml_node<> *printkey = key->next_sibling("key"); 
		
			string keyValue = printkey->value();
		
			//Ends the loop if it a TV SHOW or MOVIE
			if(keyValue.compare("TV Show") == 0 || keyValue.compare("Movie") == 0)
			{
				check = false;
			}
			//Checking Artist Node for Music
			else if (keyValue.compare("Artist") == 0)
			{
				xml_node<> *artist = printkey->next_sibling("string");
				song->artist = artist->value();
			}
			//Checking Name Node for Music
			else if (keyValue.compare("Name") == 0)
			{
				xml_node<> *name = printkey->next_sibling("string");
				song->name = name->value();
			}
			//Checking Album Node for Music
			else if (keyValue.compare("Album") == 0)
			{
				xml_node<> *name = printkey->next_sibling("string");
				song->album = name->value();
			}
			
			//Ends Loop adds to Vector
			if(keyValue == lastkey->value())
			{
				//Adds to number of Songs addeds
				count++;
				//Adds a Song node to the Tree from parsed XML data
				addSongNode(song->artist,song->name,song->album);
				//Ends the Loop
				check = false;
			}
			//Makes the old key the current key so the next loop continues through
			key = key->next_sibling("key");
		}
	}
	
	cout << "Added " << count << " songs to the Music Tree from iTunesMusicLibrary.xml" << endl;
	
}

//decontructor class
MusicTree::~MusicTree()
{
	//decontructor
}


