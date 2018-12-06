#ifndef HASHTABLE_H
#define HASHTABLE_H
#define TABLESIZE 1000
#include <string>
#include "LinkedList.h"

using namespace std;

template <class T>
class HashTable
{
 public:
  void insert(string, T);
  T find(string, T);

 private:
  LinkedList<T> table[TABLESIZE];
  int hashFunction(string);
  
  
};

template<class T>
T HashTable<T>::find(string key, T error)
{
  T value;
  value = table[hashFunction(key)].search(key, error);
      
  if(value != error)
	{
	return value;
	}
    
  return error;
}

template<class T>
void HashTable<T>::insert(string key, T value)
{
  int index = hashFunction(key);
  if(index == -1)
    return;
  table[index].inserFirst(value);
}

template <class T>
int HashTable<T>::hashFunction(string key)
{
  //return int if it is one char
  if(key.size() < 2)
    {
      try{return stoi(key);}
      catch(exception){
	return -1;}
    }
  //ensure string is appropriate length
  if(key.size() > 7)
    key = key.substr(0,7);

  //ensure string is positive
  if(key.at(0) == '-')
    key = key.substr(1); //remove first char
  
  //split the string in half
  int length = (key.size() / 2);
  string s1 = key.substr(0,length); //get first half
  string s2 = key.substr(length); //get second half

  int hash = 0;
  //convert the halves to integers
  // and add them
  try
    {
      hash = stoi(s1);
      hash += stoi(s2);
    } catch(exception)
  {
    cerr << "Wrong key format: " << key <<endl;
  }
  
  return hash % 1000;
}


#endif /* HASHTABLE_H */
