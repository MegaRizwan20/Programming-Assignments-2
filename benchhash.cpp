/* 
 * Authors: Rizwan Khan, Kenton Chick
 * UCSD Email: rikhan@ucsd.edu, kchick@ucsd.edu
 * PID: A12236946, A12947178
 * CSE Login: cs100sgv, kchick
 */
#include <istream>
#include "util.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <numeric>

using namespace std;


unsigned int hashFunction1(std::string hashString, unsigned int size) {
	int hitVal;
	int hashToInt;

	hashToInt = std::accumulate(hashString.begin(), hashString.end(), 0);
	hitVal = hashToInt % (size * 13 / 7);

	return hitVal;
}

unsigned int hashFunction2(std::string hashString, unsigned int size) {
	int hitVal;
	int hashToInt;

	hashToInt = std::accumulate(hashString.begin(), hashString.end(), 0);
	hitVal = hashToInt % (size * 5 / 3);

	return hitVal;
}


/*
   hashFunction2(vector, int size) {
   std::vector hits[size * 2];
   int i;
   int hitVal;
   std::vector slotsWithHits;

   for(i = 0; i < size; i++) {
   hitVal = dictVector[i] % (size * 5 / 3);
   hits[hitVal] += 1;
   }

   cout << "Printing the statistics for hashFunction2" << endl;

   cout << "#hits        #slots receiving the #hits" << endl;
   for(i = 0; i < hits.size(); i++) {
   cout << i << "        " << hits[i] << endl;
   average += (i * hits[i]);
   }
   cout << "The average number of steps for a successful search  for hash" << 
   " function 2 would be " << average << endl;
   cout << "The worst case steps that would be needed to find a word is " <<
   hits.size() << endl;
   }*/

int main(int argc, char* argv[]) {
	unsigned int i;
	unsigned int j;
	//std::vector hashTable1; //size num_word*2
	//std::vector hashTable2;
	//std::vector dictionary;
	unsigned int numSize = atoi(argv[2]);
	unsigned int hashValue;
	unsigned int hitValue;
	vector<unsigned int>::iterator iter;

	std::filebuf fb;
	fb.open(argv[1], std::ios::in);
	std::istream dictStream(&fb);
	std::vector<std::string> dictionary;

	std::vector<unsigned int> hits(numSize * 2);

	//  int hitVal;
	std::vector<unsigned int> slotsWithHits(1);
	float average;
	unsigned int averageAdded;
	//istream

	Utils::load_vector(dictionary, dictStream, numSize);

	//for(i = 0; i < num_words; i++) {

	// cout << "numSize is " << numSize << endl;

	for(i = 0; i < numSize; i++) {
		//  cout << "hashValue" << endl;

		hashValue = hashFunction1(dictionary[i], numSize);
		iter = hits.begin();
		for(j = 0; j < hashValue; j++, iter++) {}
		(*iter)++;

		//  vectorVal = hits[hashValue];
		//hitVal = dictVector[i] % (size * 5 / 3);
		//  hits[hashValue] = vectorVal + 1;
	}
	iter = slotsWithHits.begin();
	for( i = 0; i < hits.size(); i ++) {
		hitValue = hits[i];
		
		//cout << "asdf" << hitValue << endl;
		iter = slotsWithHits.begin();
		for(j = 0; j < hitValue; j++, iter++) {
		//if((slotsWithHits[j] == slotsWithHits.back()))
		 // cout << "j is " << j << endl;
		 // cout << "back is" << slotsWithHits.size() << endl;

		if(j == slotsWithHits.size()-1)
			slotsWithHits.push_back(0);
		}
		(*iter)++;
	}

	cout << "Printing the statistics for hashFunction1" << endl;

	cout << "#hits        #slots receiving the #hits" << endl;
	for(i = 0; i < slotsWithHits.size(); i++) {
		cout << i << "        " << slotsWithHits[i] << endl;
		average += (i * slotsWithHits[i]);
	}

	cout << " slots size is " << slotsWithHits.size() << endl;

	for(i = slotsWithHits.size() - 1; i > 0; i--) {
		averageAdded += slotsWithHits[i];

		average += i * averageAdded;
	}
	cout << "The average number of steps for a successful search  for hash" << 
		" function 1 would be " << average/numSize << endl;
	cout << "The worst case steps that would be needed to find a word is " <<
		slotsWithHits.size() - 1 << endl;



	for(i = 0; i < numSize; i++) {
		//  cout << "hashValue" << endl;

		hashValue = hashFunction2(dictionary[i], numSize);
		iter = hits.begin();
		for(j = 0; j < hashValue; j++, iter++) {}
		(*iter)++;

		//  vectorVal = hits[hashValue];
		//hitVal = dictVector[i] % (size * 5 / 3);
		//  hits[hashValue] = vectorVal + 1;
	}
	iter = slotsWithHits.begin();
	for( i = 0; i < hits.size(); i ++) {
		hitValue = hits[i];
		
		//cout << "asdf" << hitValue << endl;
		iter = slotsWithHits.begin();
		for(j = 0; j < hitValue; j++, iter++) {
		//if((slotsWithHits[j] == slotsWithHits.back()))
		 // cout << "j is " << j << endl;
		 // cout << "back is" << slotsWithHits.size() << endl;

		if(j == slotsWithHits.size()-1)
			slotsWithHits.push_back(0);
		}
		(*iter)++;
	}

	average = 0;
	cout << "Printing the statistics for hashFunction2" << endl;

	cout << "#hits        #slots receiving the #hits" << endl;
	for(i = 0; i < slotsWithHits.size(); i++) {
		cout << i << "        " << slotsWithHits[i] << endl;
		average += (i * slotsWithHits[i]);
	}

	for(i = slotsWithHits.size() - 1; i > 0; i--) {
		averageAdded += slotsWithHits[i];

		average += i * averageAdded;
	}
	cout << "The average number of steps for a successful search  for hash" << 
		" function 2 would be " << average/numSize << endl;
	cout << "The worst case steps that would be needed to find a word is " <<
		slotsWithHits.size() - 1 << endl;

	/*

	   for(i = 0; i < numSize; i++) {
	   hashValue = hashFunction2(dictionary[i], numSize);
	   iter = hits.begin();
	   for(j = 0; j < hashValue; j++, iter++) {}
	   (*iter)++;

	//  hashFunction2(dictionary, numSize); 
	cout << "Printing the statistics for hashFunction2" << endl;

	cout << "#hits        #slots receiving the #hits" << endl;
	for(i = 0; i < hits.size(); i++) {
	cout << i << "        " << hits[i] << endl;
	average += (i * hits[i]);
	}
	cout << "The average number of steps for a successful search  for hash" << 
	" function 2 would be " << average << endl;
	cout << "The worst case steps that would be needed to find a word is " <<
	hits.size() << endl;

	}*/
	return 0;
}


