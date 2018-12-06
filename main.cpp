/* Nick Passantino 
 * CS300 Assignment 4
 * Professor Serce
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <vector>
#include <time.h>
#include <string>
#include "BinarySearchTree.h"
#include "Element.h"
#include "HashTable.h"

int main()
{
  /* Declare the data structures that will be used to 
     hold the UPC Code information */
  BinarySearchTree<Element>* bst = new BinarySearchTree<Element>();
  vector<Element>* vctr = new vector<Element>();
  HashTable<Element> hashtable;

  /* Fill the data structures */
  ifstream file("upc_corpus.txt");
  string key;
  string value;
  string line;

  clock_t t;
  t = clock();

  // Fill the BST
  while(!file.eof())
    //for(int i=0; i<5 ; i++)
  {
      getline(file, line);
      // cout << line << endl;
      
      stringstream* ss = new stringstream(line);
      getline(*ss,key, ',');
      getline(*ss, value);
      
      Element elmnt(key, value);

      bst->insert(elmnt);
    }
  //Report the time it took to fill the BST
  t = clock() - t;
  cout << "Time to fill BST: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

  //Fill the vector
  t = clock();
  file.clear();
  file.seekg (0);
  
  while(!file.eof())
  {
      getline(file, line);
      
      stringstream* ss = new stringstream(line);
      getline(*ss,key, ',');
      getline(*ss, value);
      
      
      Element elmnt(key, value);

      vctr->push_back(elmnt);
    }

  t = clock() - t;
  cout << "Time to fill Vector: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;
  
  //Fill the Hash Table
  t = clock();
  file.clear();
  file.seekg (0);

  while(!file.eof())
  {
      getline(file, line);
      
      stringstream* ss = new stringstream(line);
      getline(*ss,key, ',');
      getline(*ss, value);
      
      
      Element elmnt(key, value);
      hashtable.insert(key, elmnt);
    }

  t = clock() - t;
  cout << "Time to fill Hash Table: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

  
  
  //Ask the user for UPC codes to search
  string UPCcode;
  Element e;
  vector<Element> v;

  cout << "Enter \"Quit\" to exit" << endl;
  
  while(true) {
    bool flag = true;
    while(flag) //ensure the user inputs a valid UPC code
      {
	cout << "\nEnter a UPC Code:";
	cin >> UPCcode;
	
	if(!UPCcode.compare("Quit")) // Quit program upon user request
	   return 0;
	   
	e.key = UPCcode;
	if(bst->search(e))
	  {
	  flag = false;
	  } else
	  cout << "UPC code not found" << endl;
      }

    cout << endl;
      

  //Retrieve from BST
  t = clock();
  cout << (bst->find(e)).value << endl;
  t = clock() - t;
  cout << "time (BST): " << t << " miliseconds" << endl << endl;

  
   //Retrieve from vector
  t = clock();
   for(int i=0; i< vctr->size(); i++)
    {
      if(!(vctr->at(i)).key.compare(e.key))
      {
	cout << vctr->at(i).value << endl;
      }
    }
  t = clock() - t;
  cout << "time (Vector): " << t << " miliseconds" << endl << endl;
  
  //Retrieve from Hash Table
  Element error("", "Not Found");
  t = clock();
  cout << hashtable.find(UPCcode, error).value << endl;
  t = clock() - t;
  cout << "time (Hash Table): " << t << " miliseconds" << endl;
  

    }
  return 0;
}
