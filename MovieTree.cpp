#include <iostream>
#include <fstream> 
#include <string>
#include "MovieTree.h"
#include <sstream> 
using namespace std;

MovieTree::MovieTree()
{
	root = NULL;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
	MovieNode *temp = root;
  MovieNode *node = new MovieNode(ranking, title, releaseYear, quantity);
	MovieNode *parent = temp;
	 
	while(temp != NULL)
	{
		parent = temp;
		string str1 = node->title;
		string str2 = temp->title;
		
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
	    root = node;
	}
	else if (node->title.compare(parent->title) < 0) {
	    parent->left = node;
	    node->parent = parent;
	    //cout << "inserted: " << node->title << " left child of: " << parent->title <<endl;
	} 
	else {
	    parent->right = node; 
	    node->parent = parent;
	    //cout << "inserted: " << node->title << " right child of: " << parent->title <<endl;
	}
	
}

void MovieTree::findMovie(string title)
{
	MovieNode *node = root;
	while(node != NULL)
  {
		if(node->title.compare(title) < 0)
		{
		  node = node->right;
    }
		else if (node->title.compare(title) > 0)
		{
		  node = node->left;
		} 
		else 
		{
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << node->ranking << endl;
			cout << "Title:" << node->title << endl;
			cout << "Year:" << node->year << endl;
			cout << "Quantity:" << node->quantity << endl;
			return;
		}
	}
	cout << "Movie not found." << endl;
}

void MovieTree::rentMovie(string title)
{
	MovieNode *node = root;
	while(node != NULL)
  {
		if(node->title.compare(title) < 0)
		{
		  node = node->right;
    }
		else if (node->title.compare(title) > 0)
		{ 
		  node = node->left;
		}  
		else 
		{
			if(node->quantity > 0){
				cout << "Movie has been rented." << endl;
				cout << "Movie Info:" << endl;
				cout << "===========" << endl;
				cout << "Ranking:" << node->ranking << endl;
				cout << "Title:" << node->title << endl;
				cout << "Year:" << node->year << endl;
				node->quantity = node->quantity-1;
				cout << "Quantity:" << node->quantity << endl;
				if(node->quantity == 0)
				{
					cout << "rentdelete" << endl;
					deleteMovieNode(title);
				}
			}
			else {
				cout << "Movie out of stock." << endl;
			}
			return;
		}
	}
	cout << "Movie not found." << endl;
}

void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

void MovieTree::deleteMovieNode(string title)
{
	MovieNode *node = root;
	while(node != NULL)
	{
		if(node->title.compare(title) < 0)
		{
		  node = node->right;
    }
		else if (node->title.compare(title) > 0)
		{
		  node = node->left;
		}  
		else
		{
			//cout << "Deleting: " << node->title << endl;
			deleteMovieNode(node,title);
			return;
		}
	}
	cout << "Movie not found." << endl;
}

MovieNode* MovieTree::deleteMovieNode(MovieNode *node,string title)
{
  if(node == NULL){
    return node;
 	}
  else if(node->title.compare(title) > 0){
  	node->left = deleteMovieNode(node->left, title);
  } 
  else if(node->title.compare(title) < 0){
  	node->right = deleteMovieNode(node->right, title);
  } 
  else 
	{
    //No Child
    if(node->left == NULL && node->right == NULL){
      //cout << "one" << endl;
			if(node == node->parent->right)
			{
				node->parent->right = NULL;
			}
			else
			{
				node->parent->left = NULL;
			}
			node = NULL;
			delete node;
		 //one child
		 }
		 else if(node->left == NULL)
		 {
			 
       MovieNode *temp = node;
       node = node->right;
       delete temp;
     } 
		 else if(node->right == NULL)
		 {
       MovieNode *temp = node;
       node = node->left;
       delete temp;
     } 
		 else
		 {
       MovieNode *temp = treeMinimum(node->right);
       node->title = temp->title;
       node->right = deleteMovieNode(node->right, temp->title);
     }
   }
   return node;
}

MovieNode* MovieTree::treeMinimum(MovieNode *node)
{
	while(node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

int MovieTree::countMovieNodes(MovieNode *node)
{
	if(node == NULL) { 
		return 0;
	} else { 
		return countMovieNodes(node->left) + countMovieNodes(node->right) + 1;
	}
}

int MovieTree::countMovieNodes()
{
	return countMovieNodes(root);
}

void MovieTree::printMovieInventory(MovieNode * node)
{
	if (node) {
	  printMovieInventory(node->left);
		cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    printMovieInventory(node->right);
	}
}

void MovieTree::DeleteAll(MovieNode * node)
{
	if (node) {
		DeleteAll(node->left);
		DeleteAll(node->right);
	  cout << "Deleting: " << node->title << endl;
		deleteMovieNode(node->title);
	}
}

MovieTree::~MovieTree()
{
	DeleteAll(root);
}


