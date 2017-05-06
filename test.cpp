/* 
 * Authors: Rizwan Khan, Kenton Chick
 * UCSD Email: rikhan@ucsd.edu, kchick@ucsd.edu
 * PID: A12236946, A12947178
 * CSE Login: cs100sgv, kchick
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;
  bool findCheck;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  words.push_back("the cat");

  words.push_back("basketball");
  words.push_back("asterisk");
  words.push_back("basket");
  words.push_back("application");
  words.push_back("a");
  words.push_back("app");
  words.push_back("gugglebee");
  words.push_back("waldos");
  words.push_back("are you not entertained");
  words.push_back("never gonna give you up");

  words.push_back("a a");
  words.push_back("aa");
  words.push_back("aaa");
  words.push_back("aa a");
  
  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      //findCheck = dt.find("autocomplete");
      //cout << "NONSENSE " << *wit << endl;
      //if (findCheck == true) 
      //{
      //  cout << "the word " << *wit << endl;
      //}
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << "TESTING FIND METHOD " << endl;
  findCheck = dt.find("a");

  if (findCheck == true)
  {
    cout << "Found a " << endl;
  }
  else
  {
    cout << "did not find a " << endl;
  }



  findCheck = d_bst.find("a a");

  if (findCheck == true)
  {
    cout << "Found harry a a" << endl;
  }
  else
  {
    cout << "did not find harry a a" << endl;
  }





  findCheck = d_ht.find("aa");

  if (findCheck == true)
  {
    cout << "Found harry aa" << endl;
  }
  else
  {
    cout << "did not find harry aa" << endl;
  }














  findCheck = dt.find("aaa");
  //if (findCheck == false)
  if (findCheck == true)
  {
    cout << "Passed for aaa" << endl;
  }
  else
  {
    cout << "Failed aaa " << endl;
  }



  findCheck = dt.find("aa a");
  if (findCheck == true)
  {
    cout << "Passed for aa a" << endl;
  }
  else
  {
    cout << "Failed aa a " << endl;
  }

  std::vector<string> printVector;
  printVector = dt.predictCompletions("harry", 1);
 // int i;
//  for(i = 0; i < 2; i++) {
    cout << printVector[0] << endl;
    //cout << printVector[1] << endl;

  //}//cout << 

  /*findCheck = dt.find("the cat");
  if (findCheck == true)
  {
    cout << "Passed for 'the cat' "<< endl;
  }
  else
  {
    cout << "failed for 'the cat' " << endl;
  } 

  findCheck = dt.find("cat");
  if (findCheck == false)
  {
    cout << "Passed for not finding 'cat' " << endl;
  }
  else
  {
    cout << "Failed 'cat' " << endl;
  }
*/
  cout << endl;

  
/*You are supposed to add more test cases in this file */
  
  return 0;
}
