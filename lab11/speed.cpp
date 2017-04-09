/*
	Speed.cpp
	Performs timing on vector, LList, and LListR over similar functions
	and prints the timings to the screen, which can be given to
	gnuplot.
	X axis will be number of elements in the container, y is time for command
	to complete.
	'make speed' will compile, run, and plot the results.
	Paul Talaga
	March 2016
	
	sudo apt-get install gnuplot-qt
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "LList.h"
#include "LListR.h"

using namespace std;

const unsigned MINN = 2;
const unsigned MAXN = 10000;
const unsigned STEPN = 200;

///   pushBack *******************************
clock_t pushBackVector(unsigned n);
clock_t pushBackLList(unsigned n);
clock_t pushBackLListR(unsigned n);

///   pushFront *******************************
clock_t pushFrontVector(unsigned n);
clock_t pushFrontLList(unsigned n);
clock_t pushFrontLListR(unsigned n);

///   popBack *******************************
clock_t popBackVector(unsigned n);
clock_t popBackLList(unsigned n);
clock_t popBackLListR(unsigned n);

///   popFront *******************************
clock_t popFrontVector(unsigned n);
clock_t popFrontLList(unsigned n);
clock_t popFrontLListR(unsigned n);

///   size *******************************
clock_t sizeVector(unsigned n);
clock_t sizeLList(unsigned n);
clock_t sizeLListR(unsigned n);

///   access 100 random elements *******************************
const int RAND_SIZE = 50;
unsigned int rand_list[RAND_SIZE];
void fillRandList();
clock_t accessVector(unsigned n);
clock_t accessLList(unsigned n);
clock_t accessLListR(unsigned n);


int main(int argc, char* argv[]){
  int test = 0; // Default to pushBack
  if(argc == 2){
    test = atoi(argv[1]);
  }
  
  // Fill rand list
  fillRandList();
  
  // Save all the function pointers so we can run
  // through them easily in a loop.
  clock_t (*fn[][3])(unsigned) =
    {{pushBackVector,pushBackLList,pushBackLListR},
     {pushFrontVector,pushFrontLList,pushFrontLListR},
     {popBackVector,popBackLList,popBackLListR},
     {popFrontVector,popFrontLList,popFrontLListR},
     {sizeVector,sizeLList,sizeLListR},
     {accessVector,accessLList,accessLListR}};
  for(unsigned n = MINN; n < MAXN; n += STEPN){
    cout << n;
    for(unsigned m = 0; m < 3; m++){
      cout << '\t' << (float)(*fn[test][m])(n);/// (float)CLOCKS_PER_SEC / (float)n ;
    }
    cout << endl;
  }
  
  return 0;
}

///   pushBack *******************************
clock_t pushBackVector(unsigned n){
  vector<int> a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  return clock() - start;
}

clock_t pushBackLList(unsigned n){
  LList a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  return clock() - start;
}

clock_t pushBackLListR(unsigned n){
  LListR a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  return clock() - start;
}

///   pushFront *******************************
clock_t pushFrontVector(unsigned n){
  vector<int> a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.insert(a.begin(),45);
  }
  return clock() - start;
}

clock_t pushFrontLList(unsigned n){
  LList a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  return clock() - start;
}

clock_t pushFrontLListR(unsigned n){
  LListR a;
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  return clock() - start;
}

///   size *******************************
clock_t sizeVector(unsigned n){
  vector<int> a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  clock_t start = clock();
  value = a.size();
  // Trick so optimizer doesn't remove value
  return clock() - start + value * 0;
}

clock_t sizeLList(unsigned n){
  LList a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  value = a.size();
  return clock() - start + value * 0;
}

clock_t sizeLListR(unsigned n){
  LListR a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  value = a.size();
  return clock() - start + value * 0;
}

///   access *******************************
void fillRandList(){
  // Don't do srand so we get the same rand every time
  for(unsigned i = 0; i < RAND_SIZE; i++){
    rand_list[i] = rand();
  }
}
clock_t accessVector(unsigned n){
  vector<int> a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_back(i);
  }
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    value += a[rand_list[i % RAND_SIZE] % n];
  }
  return clock() - start;
}
clock_t accessLList(unsigned n){
  LList a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_front(i);
  }
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    value += a[rand_list[i % RAND_SIZE] % n];
  }
  return clock() - start;
}
clock_t accessLListR(unsigned n){
  LListR a;
  unsigned value = 0;
  for(unsigned i = 0; i < n; i++){
    a.push_back(i);
  }
  clock_t start = clock();
  for(unsigned i = 0; i < n; i++){
    value += a[rand_list[i % RAND_SIZE] % n];
  }
  return clock() - start;
}

///   popBack *******************************
clock_t popBackVector(unsigned n){
  vector<int> a;
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  clock_t start = clock();
  a.erase(a.end()-1);
  return clock() - start;
}

clock_t popBackLList(unsigned n){
  LList a;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  a.pop_back();
  return clock() - start;
}

clock_t popBackLListR(unsigned n){
  LListR a;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  a.pop_back();
  return clock() - start;
}

///   popFront *******************************
clock_t popFrontVector(unsigned n){
  vector<int> a;
  for(unsigned i = 0; i < n; i++){
    a.push_back(45);
  }
  clock_t start = clock();
  a.erase(a.begin());
  return clock() - start;
}

clock_t popFrontLList(unsigned n){
  LList a;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  a.pop_front();
  return clock() - start;
}

clock_t popFrontLListR(unsigned n){
  LListR a;
  for(unsigned i = 0; i < n; i++){
    a.push_front(45);
  }
  clock_t start = clock();
  a.pop_front();
  return clock() - start;
}
