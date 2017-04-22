#include "util.h"
#include "DictionaryTrie.h"

using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie() : root(NULL) {}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  TSTNode* curr;
  // If root does not exist, we make a root
  if (!root)
  {
    //if (word[1] != '\0')
    if (word.length() > 1)
    {
      root = new TSTNode(word[0], 0);
    }
    else
    {
      root = new TSTNode(word[0], freq);
    }
    curr = root;
    /* Checks if there is more than one letter in the word, so we can insert
     * in a whole word down the middle */
    //if (word[1] != '\0')
    if (word.length() > 1)
    {
      unsigned int i = 1;
      /* Checking if we are pointing to the null character or not */
      //while (word[i] != '\0')
      while (i != word.length())
      {
        /* Make a new TSTNode and set it equal to the letter and point
         * to the appropriate parents */
        TSTNode* newNode = new TSTNode(word[i], 0);
        //if (word[i+1] == '\0')
        if (word.length() - 1 == i)
        {
          newNode->freq = freq;
          newNode->nodeCheck = true;
        }
        curr->middle = newNode;
        newNode->parent = curr;
        curr = curr->middle;
        i++;
      }
    }
    return true;
  }

  // TODO NEED TO FIX THIS INSERT METHOD
  //return false;
  unsigned int j = 0;
  curr = root;
  while (true)
  {
//cout << "Word char: " << word[j] << " curr: " << curr->data << " j is: " << j << endl;
    // Checks if there is no middle child
    if (curr->middle == NULL)
    {
      TSTNode* newNode = new TSTNode(word[j], 0);
      curr->middle = newNode;
      newNode->parent = curr;
      //if (word[j+1] == '\0')
      if (word.length() -1 == j)
      {
        newNode->freq = freq;
        newNode->nodeCheck = true;
        break;
      }
      curr = curr->middle;
      j++;
      continue;
    }
    // If trying to insert something that is less than
    if (word[j] < curr->data)
    {
      if (curr->left == NULL)
      {
        TSTNode* newNode = new TSTNode(word[j], 0);
        curr->left = newNode;
        newNode->parent = curr;
        // This means we got to the last letter of the word
        //if (word[j+1] == '\0')
        if (word.length() == j)
        {
          newNode->freq = freq;
          newNode->nodeCheck = true;
          break;
        }
        curr = curr->left;
        j++;
      }
      else
      {
        curr = curr->left;
      }
    }
    // If what we are trying to insert is bigger than current node
    else if (curr->data < word[j])
    {
      if (curr->right == NULL)
      {
        TSTNode* newNode = new TSTNode(word[j], 0);
        curr->right = newNode;
        newNode->parent = curr;
        //if (word[j+1] == '\0')
        if (word.length() == j)
        {
          newNode->freq = freq;
          newNode->nodeCheck = true;
          break;
        }
        curr = curr->right;
        j++;
      }
      else
      {
        curr = curr->right;
      }
    }
    else if (word[j] == curr->data)
    {
      //if (word[j+1] == '\0' && curr->nodeCheck == true)
      if (curr->middle == NULL)
      {
        TSTNode* newNode = new TSTNode(word[j], 0);
        curr->middle = newNode;
        newNode->parent = curr;
        //if (word[j+1] == '\0')
        if (word.length() - 1 == j)
        {
          newNode->freq = freq;
          newNode->nodeCheck = true;
          break;
        }
        curr = curr->middle;
        j++;
      }
      else
      {
        curr = curr->middle;
        j++;
      }
      if (word.length() - 1 == j && curr->nodeCheck == true)
      {
        return false;
      }
    }
    else
    {
      curr->freq = freq;
      curr->nodeCheck = false;
      return false;
    }
  }
  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  if (!root)
  {
    return false;
  }
  TSTNode* curr = root;
  unsigned int i = 0;
  while (curr)
  {
    cout << "CURR IS " << curr->data << endl;
    cout << "THE WORD IS " << word[i] << endl;
    if (word[i] == curr->data)
    {
      if (word.length() - 1 == i && curr->nodeCheck == true)
      {
        return true;
      }
      else if (word.length() - 1 == i && curr->nodeCheck == false)
      {
        return false;
      }
      else
      {
        curr = curr->middle;
        i++;
      }
      //i++;
    }
    else if (word[i] < curr->data)
    {
      //cout << "The 
      curr = curr->left;
      i++;
    }
    else if (curr->data < word[i])
    {
      curr = curr->right;
      i++;
    }
  }
  return false;
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, 
unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}

/* Constructor for the Nodes in the TST */
//TSTNode::TSTNode(char & c) : left(NULL), middle(NULL), right(NULL), parent(NULL), data(c) {}
