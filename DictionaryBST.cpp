#include "util.h"
#include "DictionaryBST.h"
#include <set>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
  //DictionaryBST dict = new DictionaryBST();
  /*std::set<std::string> dictBST;
  std::set<std::string>::iterator dictBSTIter;
  std::pair<std::set<std::string>::dictBSTIter, bool> dictBSTReturn;
  */

}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  
  return dictBST.insert(word).second;
  //return dictBSTReturn.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
    return(dictBST.end() == dictBST.find(word));}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
