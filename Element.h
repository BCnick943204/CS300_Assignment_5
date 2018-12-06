/* Nick Passantino 
 * CS300 Assignment 4
 * Professor Serce
 */
#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
using namespace std;

struct Element{
  Element(){}
  Element(string key, string value){
    this->key = key;
    this->value = value;
  }
  void set(string, string);
  bool operator<(const Element&);
  bool operator>(const Element&);
  string key ;
  string value;
};

void Element::set(string key, string value)
{
  this->key = key;
  this->value = value;
}

bool Element::operator<(const Element& e2)
{
  if((this->key).length() < e2.key.length())
    return true;
    
  try{
  if(stod(this->key) < stod(e2.key))
    {
    return true;
  }else
    {
        return false;
    }
  }catch(exception)
     {
       return true;
     }
  return false;
  
}

bool Element::operator>(const Element& e2)
{
  if((this->key).length() > e2.key.length())
    return true;
    
  try{
  if(stod(this->key) > stod(e2.key))
    {
    return true;
  }else
    {
      //     cout << "returned false" << endl;
        return false;
    }
  }catch(exception)
     {
       return true;
     }
  return 0;
  
}
bool operator==(const Element& e, string s)
{
  if(!(e.key.compare(s)))
    return true;
  else
    return false;
}

bool operator!=(const Element& e1, const Element& e2)
{
    if(!(e1.key.compare(e2.key)))
    return false;
  else
    return true;
}

#endif /*ELEMENT_H*/ 
