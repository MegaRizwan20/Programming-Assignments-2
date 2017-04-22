/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>

class TSTNode {

public:
  /* CODE THAT WAS ADDED IN */
  //TSTNode<char>* left;
  //TSTNode<char>* middle;
  //TSTNode<char>* right;
  //TSTNode<char>* parent;
  TSTNode* left;
  TSTNode* middle;
  TSTNode* right;
  TSTNode* parent;
  //TSTNode* root;
  int freq;
  char const data;
  bool nodeCheck = false;
  /* Constructor. Initializes a TSTNode with the given char and the frequency
   * of occurences of a word */
  TSTNode(char & c, int f) : left(NULL), middle(NULL), right(NULL), parent(NULL), data(c){};

};


/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  // CODE THAT WAS GIVEN
  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();
  // CODE THAT WE ADDED
  //DictionaryTrie() : TSTNode::root(NULL) {}

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

  static void deleteAll(TSTNode* t);

private:
  // Add your own data members and methods here
  // CODE WE ADDED
  /* Pointer to root of TST, 0 if its empty */
  TSTNode* root;

};

#endif // DICTIONARY_TRIE_H
