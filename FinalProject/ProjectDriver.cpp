#include <iostream>
#include <fstream> 
#include <string>
#include "MusicTree.h"
#include <sstream> 

using namespace std; 

//Init Function to display menu and return user input
int DisplayMenu(); 

int main(int argc, char* argv[])
{
	
	//Init Music Tree
	MusicTree *tree = new MusicTree();
	
	//bool to end while loop (check when user quits)
	bool gbye = false;
	
	//Init strings for cin in switch statment
	string findStr;
	string rentStr;
	string artStr;
	string songStr;
	string albStr;
	
	//while loop to repeat menu until the user quits
	while(gbye == false){
		
		int menu = DisplayMenu();
		
		//Switch statment to handle user input and call functions of MusicTree respectivly
		switch(menu) {
			case 0:
				cout << "Enter Artist Name:" << endl;
				cin.ignore(); 
				getline (cin, artStr);
				cin.clear();
		  	cout << "Enter Song Name:" << endl;
				getline (cin, songStr);
				cin.clear();
		  	cout << "Enter Album Name:" << endl;
				getline (cin, albStr);
				cin.clear();
				tree->addSongNode(artStr,songStr,albStr);
			break;
			case 1:
				tree->populateXML();
			break;
			case 2:
				tree->printMusicLibrary();
			break;
			case 3:
				cout << "Enter Artist name:" << endl;
				cin.ignore(); 
				getline (cin, findStr);
				cin.clear();
				tree->checkForArtist(findStr);
			break; 
			case 4:
				cout << "Enter Song Name:" << endl;
				cin.ignore(); 
				getline (cin, findStr);
				cin.clear();
				tree->findSong(findStr);
			break;
			case 5:
				cout << "Enter Album Name:" << endl;
				cin.ignore(); 
				getline (cin, albStr);
				cin.clear();
				tree->printAlbum(albStr);
			break;
			case 6:
				cout << "Tree contains: " << tree->countSongNodes() << " songs." << endl;
			break;
			case 7:
				gbye = true;
				cout << "Goodbye!" << endl;
				delete tree;
			break;
		}
	}
	return 0;
}

//function to display menu and return user input
int DisplayMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "0. Add Song" << endl;
	cout << "1. Populate Tree from iTunes XML file (iTunesMusicLibrary.xml)" << endl;
	cout << "2. Print Library" << endl;
	cout << "3. Check for an Artist" << endl;
	cout << "4. Find a Song" << endl;
	cout << "5. Print Album Contents" << endl;
	cout << "6. Count the songs" << endl;
	cout << "7. Quit" << endl;
	
	int use;
	cin >> use;
	return use;
}