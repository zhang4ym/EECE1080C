#ifndef LLIST_RECURSE_H
#define LLIST_RECURSE_H

/*
	Linked List class that store integers, with [] operator.
	Uses head pointer.
	Uses recursion as much as possible.
	Paul Talaga
*/
#include <ostream>
#include <stdexcept>

using namespace std;

struct nodeR_t {
  int data;
  nodeR_t* next;
};

// This implementation will use a head pointer,
// allowing O(1) insertion on the front,
// and O(n) on the end.
class LListR{

  public:
  LListR(){
    head = NULL;
  }
  
  ~LListR(){
		clear();
	}
	
  LListR(const LListR& other){
    // Do the same as the default constructor
  	head = NULL;
		// Check if the other LList is empty
		if(other.head == NULL){
			return;
		}
		assignment(other.head);
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  LListR& operator= (const LListR& other){  
		if(this == &other){
			return *this;
		}
  	clear();
		if(other.head == NULL){
			return *this;
		}
		assignment(other.head);
		return *this;
	} 
	
	// Recursive helper for assignment operator
	void assignment(nodeR_t* node){
	  if(node == NULL)return;
	  push_back(node->data);
	  assignment(node->next);
	}
     
  int getAt(unsigned pos) const{
		if(head == NULL) throw logic_error("Index invalid");
		return getAt(pos, head);
  }
  
  int getAt(unsigned pos, nodeR_t* node) const{
    if(pos == 0){
      return node->data;
    }
    if( node->next == NULL){
      throw logic_error("Index invalid");
    }
    return getAt(pos-1, node->next);
  }


  unsigned int size() const{
    // TODO: Fill me in.  You will likely need to create another
   // function!
    return 0;
  }
 
 
  void push_back(int value){
    // Empty list?
    if(head == NULL){
      push_front(value);
    }else{
      push_back(value, head);
    }
  }
  
  void push_back(int value, nodeR_t* node){
    if(node->next == NULL){
      nodeR_t* n = new nodeR_t;
      n->data = value;
      n->next = NULL;
      // Tack it on the end
      node->next = n;
    }else{
      push_back(value, node->next);
    }
  }
  
  void push_front(int value){
    // Empty list?
    if(head == NULL){
      head = new nodeR_t;
      head->data = value;
      head->next = NULL;
    }else{// Not empty
      nodeR_t* temp = new nodeR_t;
      temp->data = value;
      temp->next = head;
      head = temp;
    }
  }
  
  void pop_front(){
    if(head == NULL)return;
    nodeR_t* temp = head;
    head = head->next;
    delete temp;
  }
  
  void pop_back(){
   // TODO: Fill me in. You will likely need to create another
   // function!
  }
	
	void setAt(int value, unsigned pos){
		setAt(value, pos, head);
  }
  
  void setAt(int value, unsigned pos, nodeR_t* node){
    if(node == NULL){
      throw logic_error("Index invalid");
    }else if(pos == 0){
      node->data = value;
    }else{
      setAt(value, pos-1, node->next);
    }
  }
	
	// Overload [] operator
	// Return logic error if index out of bounds
	int& operator[](unsigned pos){
		return bracket(pos, head);
	}
	
	int& bracket(unsigned pos, nodeR_t* node){
	  if(node == NULL){
      throw logic_error("Index invalid");
    }else if(pos == 0){
      return node->data;
    }else{
      return bracket(pos-1, node->next); 
    }
	}
	
	
	LListR reverse() const{
		LListR ret;
		reverseHelp(head, ret);
		return ret;
	}
	
	void reverseHelp(nodeR_t* node, LListR& other)const{
	  if(node == NULL)return;
	  other.push_front(node->data);
	  reverseHelp(node->next, other);
	}
	
	
	
	bool operator==(const LListR& other) const{
	 // TODO: Fill me in.  You will likely need to create another
   // function!
   return true;
	}
	
	bool operator!=(const LListR& other) const{
		return ! operator==(other);
	}
	
	
	void clear(){
		clear(head);
		head = NULL;
	}
	
	// Recusively return all memory to system.
	void clear(nodeR_t* node){
	  if(node == NULL)return;
	  clear(node->next);  // Order is important!
	  delete node;
	}
 
  
  private:
  nodeR_t* head;
  
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.

ostream& operator<<(ostream& out, const LListR other){
	out << "[";
	for(unsigned int i = 1; i < other.size(); i++){
		out << other.getAt(i-1) << ", ";
	}
	if(other.size() > 0){
		out << other.getAt(other.size() - 1);
	}
	out << "]";
	return out;
}


#endif
