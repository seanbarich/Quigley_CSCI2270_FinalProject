# Quigley_CSCI2270_FinalProject
Final Project for CSCI 2270

Phase 1:
My program will take infmormation about a users music library and add each song to a binary search tree. Information about each song and the entire libraby will be acsessible through user input. 

Phase 2: 

#Instructions for Starting Program:

1.) Along with this README file, 
->makefile
->Music.h
->Music.cpp
->ProjectTestDriver.cpp,
->iTunesLibrary.xml 
and a folder called "rapidxml" should be included. The .h and .cpp files are used to exucte the program. Rapid XML is a third party XML parser that I used to interpret the iTunes Library file, more information can be found @ http://rapidxml.sourceforge.net. The iTunesLibrary.xml is my personal iTunes .xml that the program parses. The makefile is what terminal uses to run the program.

2.) Open the project file in terminal: This can be done with the command "cd /example_directory/Quigley_CSCI2270_FinalProject". The simplest way to do this is to type "cd " then drag the file from Finder into terminal.

3.) Make and run the program: Utilizing the makefile, type and enter the command "make" the output from terminal should look something like:

g++ -Wall -std=c++11 -c MusicTree.cpp
g++ -Wall -std=c++11 -c ProjectDriver.cpp
g++ -o final MusicTree.o ProjectDriver.o

after the file is made type and enter the command "./final" The program should being and you should see the display menu.

NOTE: If you ever intend on changing the contents of the project and running the program again you will need to type the command “make clean” before typing and entering “make” and “./final” again.

4.) Now that the program is running you can follow the on screen instructions to manipulate items in the Music Tree:

0. Add Song
->Gives the user the option to add a unique song of variable name, artist, album to the Music Tree.
**1. Populate Tree from iTunes XML file (iTunesMusicLibrary.xml)**
->Parses the XML file and every song to the Music Tree. Once it finishes it will tell the user how many songs were added in total.
**2. Print Library**
-> prints the entire Music Tree in the form “song name by artist name”
**3. Check for an Artist**
->Asks user for artist name and prints weather or not that artist has songs in the tree.
**4. Find a Song**
->Asks user for a song name and then prints the artist name, song name and album name.
**5. Print Album Contents**
->Asks user for an album name and prints all songs within that album.
**6. Count the songs**
-> Prints the quantity of songs in the tree.
**7. Quit**
-> Ends the Program

#Using your own iTunes Library:

1.) In iTunes, go to preferences.
2.) Click on “advanced”
3.) Make sure that the “Share iTunes Library XML with other applications” is checked.
4.) In Finder click on your user (ie “tannerQuigley”) on the sidebar.
5.) Go to Music->iTunes and the ‘iTunesLibrary.xml” should be right there.
6.) You can then copy your XML into the project, overwriting my personal file.
7.) make clean, make and ./final in terminal to run the program with your iTunes file.

#Dependencies: 

The program is dependent on a third party XML Parser called rapidxml (http://rapidxml.sourceforge.net). 
I included the rapidxml folder required to run the program so nothing needs to be downloaded.

#System Requirements

The program SHOULD work properly on all operating systems but with that being said I use OS X Yosemite and the program has only been tested on OS X Yosemite so use Windows and Linux with caution.

#Open Issues
I could not figure out how to get the program to print “Song not found” when the findSong() function doesn't find a song in the tree and “Album not found” when the findAlbum() function doesn't find an album.



