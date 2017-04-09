#ifndef LLISTR_TEST_H
#define LLISTR_TEST_H

#include <LListR.h>
#include <stdexcept>
// Needed for space removal.
#include <sstream>
#include <algorithm>
#include <cxxtest/TestSuite.h>

#undef LIST
#define LIST LListR
using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

class LListRConCopyAssign : public CxxTest::TestSuite {
   
public:
  
  // Constructor tests
  void testEmpty() {
    LIST a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  // Copy Constructor
	void testCopy() {
    LIST a;
    a.push_back(5);
    LIST b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy1() {
    LIST a;
    a.push_back(5);
    LIST b(a);
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    a.push_front(10);
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 1);
  }

  void testCopy2() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    LIST b(a);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(3), 8);
    TS_ASSERT_EQUALS(b.getAt(3), 8);
  }	
	
	// Assignment
	
	void testAssign() {
    LIST a;
    a.push_back(5);
    LIST b;
    b.push_back(10);
    a = b;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
    TS_ASSERT_EQUALS(b.getAt(0), 10);
  }

  void testAssign1() {
    LIST a;
    a.push_back(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
};

class LListRPushes : public CxxTest::TestSuite {
public:

  void testPushBack1() {
    LIST a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  void testPushBack2() {
    LIST a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  

  void testPushFront2() {
    LIST a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testPushFront3() {
    LIST a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push_front(6);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.push_front(7);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
};

class LListRPops : public CxxTest::TestSuite {
public:

  void testPopBack1() {
    LIST a;
    TS_ASSERT_EQUALS(a.size(), 0);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPopBack2() {
    LIST a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPopBack3() {
    LIST a;
    a.push_front(5);
    a.push_front(4);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.pop_back();
    TS_ASSERT_EQUALS(a.getAt(0), 4);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testPopBack4() {
    LIST a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    TS_ASSERT_EQUALS(a.size(), 4);
    a.pop_back();
    TS_ASSERT_THROWS_ANYTHING(a.getAt(3));
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testPopBack5() {
    LIST a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    TS_ASSERT_EQUALS(a.size(), 4);
    a.pop_back();
    TS_ASSERT_THROWS_ANYTHING(a.getAt(3));
    TS_ASSERT_EQUALS(a.size(), 3);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 2);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 0);
    a.pop_back();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
    void testPopFront1() {
    LIST a;
    TS_ASSERT_EQUALS(a.size(), 0);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPopFront2() {
    LIST a;
    a.push_front(5);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPopFront3() {
    LIST a;
    a.push_front(5);
    a.push_front(4);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.pop_front();
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testPopFront4() {
    LIST a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    TS_ASSERT_EQUALS(a.size(), 4);
    a.pop_front();
    TS_ASSERT_THROWS_ANYTHING(a.getAt(3));
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.getAt(0), 2);
  }
  
  void testPopFront5() {
    LIST a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(0), 1);
    a.pop_front();
    TS_ASSERT_THROWS_ANYTHING(a.getAt(3));
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.getAt(0), 2);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 3);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 4);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 0);
    a.pop_front();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
};


class LListRSetAt : public CxxTest::TestSuite {
public:

  void testSet1() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
		a.setAt(10,0);
    TS_ASSERT_EQUALS(a.getAt(0), 10);
		TS_ASSERT_EQUALS(a.getAt(1), 6);
  }
	
  void testSet2() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,2));
  }
	
  void testSet3() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a.setAt(99,-3));
  }
		

  void testGetAt1() {
    LIST a;
		TS_ASSERT_THROWS_ANYTHING(a.getAt(0));
  }
  
  void testGetAt2() {
    LIST a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(2));
  }
  
  void testGetAt3() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_THROWS_ANYTHING(a.getAt(5));
  }
};

class LListRBrackets : public CxxTest::TestSuite {
public:

  void testSet1() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
		a[0] = 10;
    TS_ASSERT_EQUALS(a.getAt(0), 10);
		TS_ASSERT_EQUALS(a.getAt(1), 6);
  }
	
  void testSet2() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    TS_ASSERT_THROWS_ANYTHING(a[2] =2);
  }
		
  void testGetAt1() {
    LIST a;
		TS_ASSERT_THROWS_ANYTHING(a[0]);
  }
  
  void testGetAt2() {
    LIST a;
    a.push_back(5);
    TS_ASSERT_EQUALS(a[0], 5);
    TS_ASSERT_THROWS_ANYTHING(a[2]);
  }
  
  void testGetAt3() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    TS_ASSERT_EQUALS(a[0], 5);
    TS_ASSERT_EQUALS(a[1], 6);
    TS_ASSERT_EQUALS(a[2], 7);
    TS_ASSERT_THROWS_ANYTHING(a[5]);
  }
};


class LListRReverse : public CxxTest::TestSuite {
public:
  void testRev0() {
    LIST a;
    LIST b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_EQUALS(b.size(), 0);
  }
  
  void testRev1() {
    LIST a;
    a.push_back(5);
    LIST b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(b.size(), 1);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 5);
  }
  
  void testRev2() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    LIST b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 6);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 5);
  }
  
  void testRev3() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    LIST b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(b.size(), 3);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 7);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 6);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_EQUALS(b.getAt(2), 5);
  }
  
  void testRev4() {
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    LIST b = a.reverse();
    TS_ASSERT_EQUALS(a.size(), 4);
    TS_ASSERT_EQUALS(b.size(), 4);
    TS_ASSERT_EQUALS(a.getAt(0), 5);
    TS_ASSERT_EQUALS(b.getAt(0), 8);
    TS_ASSERT_EQUALS(a.getAt(1), 6);
    TS_ASSERT_EQUALS(b.getAt(1), 7);
    TS_ASSERT_EQUALS(a.getAt(2), 7);
    TS_ASSERT_EQUALS(b.getAt(2), 6);
    TS_ASSERT_EQUALS(a.getAt(3), 8);
    TS_ASSERT_EQUALS(b.getAt(3), 5);
  }
  
};



class LListREq : public CxxTest::TestSuite {
public:
  void testEq0() {
    LIST a;
    LIST b;
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq1() {
    LIST a;
    a.push_back(6);
    LIST b;
    b.push_front(6);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }
  
  void testEq2() {
    LIST a;
    a.push_back(6);
    LIST b;
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq3() {
    LIST a;
    LIST b;
    b.push_front(6);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq4() {
    LIST a;
    a.push_back(6);
    LIST b;
    a.push_front(7);
    TS_ASSERT( a != b);
    TS_ASSERT( !(a == b));
  }
  
  void testEq5() {
    LIST a;
    a.push_front(5);
    a.push_back(6);
    LIST b;
    b.push_front(6);
    b.push_front(5);
    TS_ASSERT( a == b);
    TS_ASSERT( !(a != b));
  }

  void testEq6() {
    LIST a;
    a.push_front(5);
    LIST b;
    b.push_front(5);
    b.push_front(5);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq7() {
    LIST a;
    a.push_front(5);
    a.push_front(5);
    LIST b;
    b.push_front(5);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq8() {
    LIST a;
    a.push_front(5);
    a.push_front(6);
    LIST b;
    b.push_front(5);
    b.push_front(5);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq9() {
    LIST a;
    LIST b;
    for(int i = 0; i < 100; i++){
      a.push_front(i);
      b.push_front(i);
    }
    TS_ASSERT( (a == b));
    TS_ASSERT( !(a != b));
  }
  
  void testEq10() {
    LIST a;
    LIST b;
    for(int i = 0; i < 100; i++){
      a.push_front(i);
      b.push_front(i);
    }
    b.push_front(0);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq11() {
    LIST a;
    LIST b;
    for(int i = 0; i < 100; i++){
      a.push_front(i);
      b.push_front(i);
    }
    a.push_front(0);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq12() {
    LIST a;
    LIST b;
    for(int i = 0; i < 100; i++){
      a.push_front(i);
      b.push_front(100 - i);
    }
    b.push_front(0);
    TS_ASSERT( !(a == b));
    TS_ASSERT( (a != b));
  }
  
  void testEq13() {
    LIST a;
    LIST b;
    for(int i = 0; i < 100; i++){
      a.push_front(i);
      b.push_back(99 - i);
    }
    TS_ASSERT( (a == b));
    TS_ASSERT( !(a != b));
  }
};

class LListRClear : public CxxTest::TestSuite {
public:
  void testClear0() {
    LIST a;
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear1() {
    LIST a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testClear2() {
    LIST a;
    a.push_back(6);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.clear();
    TS_ASSERT_EQUALS(a.size(), 0);
    a.push_back(7);
    TS_ASSERT_EQUALS(a.getAt(0), 7);
  }
};

class LListRStream : public CxxTest::TestSuite {
public:
  void testStream1(){
    LIST a;
    a.push_back(5);
    a.push_back(6);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6]");
  }
  
  void testStream2(){
    LIST a;
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[]");
  }
  
  
  void testStream5(){
    LIST a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    // To test we stream to a stringstream, then remove spaces, then test
    // the result.
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "[5,6,7]");
  }
};





#endif
