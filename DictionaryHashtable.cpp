/* 
 * Authors: Rizwan Khan, Kenton Chick
 * UCSD Email: rikhan@ucsd.edu, kchick@ucsd.edu
 * PID: A12236946, A12947178
 * CSE Login: cs100sgv, kchick
*/

#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set>

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  /*std::unordered_set<std::string> dictHash;
  std::unordered_set<std::string>::iterator dictHashIter;
  std::pair<std::set<std::string>::dictHashIter, bool> dictHashReturn;
  */
}

/* Insert a word into the dictionary */
bool DictionaryHashtable::insert(std::string word)
{
  return dictHash.insert(word).second;
  //return dictHashReturn.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  return(dictHash.end() != dictHash.find(word));
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
