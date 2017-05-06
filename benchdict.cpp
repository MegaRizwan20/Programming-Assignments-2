/* 
 * Authors: Rizwan Khan, Kenton Chick
 * UCSD Email: rikhan@ucsd.edu, kchick@ucsd.edu
 * PID: A12236946, A12947178
 * CSE Login: cs100sgv, kchick
*/

#include <istream>
#include "util.h"
#include <stdio.h>
#include <chrono>
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

  // Grabbing all the arguments and assigning them to variables
  unsigned int min_size = atoi(argv[1]);
  unsigned int step_size = atoi(argv[2]);
  unsigned int num_iterations = atoi(argv[3]);
  std::filebuf fb;
  fb.open(argv[4], std::ios::in);
  std::istream dictfile(&fb);
  unsigned int i;
  unsigned int k;
  unsigned int l;
  unsigned int totalTime = 0;
  Timer timeObject;
  std::vector<std::string> findWordVect;

  // Test the DictionaryBST part
  cout << "DictionaryBST" << endl;
  DictionaryBST testBST;
  // Loop through and get the iterations and values that are needed
  for(i = 0; i < num_iterations; i++) {
    dictfile.clear();
    dictfile.seekg(0, ios::beg);
    Utils::load_dict(testBST, dictfile, (min_size + i * step_size));
    Utils::load_vector(findWordVect, dictfile, 100);
    timeObject.begin_timer();
    // Loop and find the values that are needed to get the necessary time value
    for(k = 0; k < 5; k++) {
      for(l = 0; l < 100; l++) {
        // Find the words
        testBST.find(findWordVect[l]);
      }
      totalTime += timeObject.end_timer();
    }
    // Print out the numbers
    cout << (min_size + i * step_size) << '\t' << (totalTime / 5) << endl;
  }

  // Reset the timer and test the Hashtable part
  totalTime = 0;
  cout << "DictionaryHashtable" << endl;

  // Loop and get the iterations and values that are needed
  for(i = 0; i < num_iterations; i++) {
    DictionaryHashtable testHashtable;
    dictfile.clear();
    dictfile.seekg(0, ios::beg);
    Utils::load_dict(testHashtable, dictfile, min_size + i * step_size);
    timeObject.begin_timer();
    // Loop and find the values that are needed to get the necessary time value
    for(k = 0; k < 5; k++) {
      for(l = 0; l < 100; l++) {
        // Find the words
        testHashtable.find(findWordVect[l]);
      }
      // Get all the numbers added on
      totalTime += timeObject.end_timer();
    }
    // Print out the numbers
    cout << (min_size + i * step_size) << '\t' << (totalTime / 5) << endl;
  }
  
  // Reset the timer and test the Ternary Search tree
  totalTime = 0;
  cout << "DictionaryTrie" << endl;

  // Loop through and get the iterations and values that are needed
  for(i = 0; i < num_iterations; i++) {
    DictionaryTrie testTrie;

    dictfile.clear();
    dictfile.seekg(0,ios::beg);
    Utils::load_dict(testTrie, dictfile, min_size + i * step_size);
    timeObject.begin_timer();
    // Loop through and get the necessary time values
    for(k = 0; k < 5; k++) {
      for(l = 0; l < 100; l++) {
        // Find the words
        testTrie.find(findWordVect[l]);
      }
      // Get the total time
      totalTime += timeObject.end_timer();
    }
    // Print out the numbers
    cout << (min_size + i * step_size) << '\t' << (totalTime / 5) << endl;
  }

  return 1;
}
