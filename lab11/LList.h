#ifndef LLIST_H
#define LLIST_H

/*
	Linked List class that store integers, with [] operator.
	Uses head pointer.
	Paul Talaga
	September 2015
*/
#include <ostream>
#include <stdexcept>

#define int int

using namespace std;

struct node_t {
  int data;
  node_t* next;
};

// This implementation will use a head pointer,
// allowing O(1) insertion on the front,
// and O(n) on the end.
class LList{

  public:
  LList(){
    head = NULL;
  }
  
  ~LList(){
		clear();
	}
	
  LList(const LList& other){
    // Do the same as the default constructor
  	head = NULL;
		// Check if the other LList is empty
		if(other.head == NULL){
			return;
		}
		// Not empty?  Iterate through the other list
		// and push_back on myself.
		node_t* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  LList& operator= (const LList& other){  
		if(this == &other){
			return *this;
		}
  	clear();
		if(other.head == NULL){
			return *this;
		}
		node_t* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
		return *this;
	}
     
  int getAt(unsigned pos) const{
		// TODO: Fill me in
		return 0;
  }

  unsigned int size() const{
    unsigned ret_size = 0;
    // Walk down the list and decrement pos.
    node_t* temp = head;
    while(temp != NULL){
      temp = temp->next;
      ret_size++;
    }
    return ret_size;
  }
 
  void push_back(int value){
    // TODO: Fill me in
  }
  
  void push_front(int value){
    // Empty list?
    if(head == NULL){
      head = new node_t;
      head->data = value;
      head->next = NULL;
    }else{// Not empty
      node_t* temp = new node_t;
      temp->data = value;
      temp->next = head;
      head = temp;
    }
  }
  
  void pop_front(){
    if(head == NULL)return;
    node_t* temp = head;
    head = head->next;
    delete temp;
  }
  
  void pop_back(){
    if(head == NULL)return; // Empty list
    if(head->next == NULL){ // One element list
      delete head;
      head = NULL;
      return;
    }
    node_t* temp = head;  // Iterate to the second to last.
    while(temp->next->next != NULL){
      temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
  }
	
	void setAt(int value, unsigned pos){
		// TODO: Fill me in
  }
	
	// Overload [] operator
	// Return logic error if index out of bounds
	int& operator[](unsigned pos){
		node_t* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    // As long as I don't have a null pointer, assign.
    if(pos == 0 && temp !=NULL){
    	return temp->data;
    }
    throw logic_error("Index invalid");
	}
	
	LList reverse() const{
		// TODO: Fill me in
		return LList(); // Remove me!
	}
	
	bool operator==(const LList& other) const{
	  // Sizes differ?
		if(size() != other.size()){
			return false;
		}
		// Now step through both lists and verify data
		node_t* temp1 = head;
		node_t* temp2 = other.head;
		while(temp1 && temp2){
			if(temp1->data != temp2->data){
				return false; // Why keep looking if we found an error?
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		// Did we pop out early because one is NULL?
		if(temp1 != temp2){ // Both should be null!
			return false;
		}
		return true;
	}
	
	bool operator!=(const LList& other) const{
		return ! operator==(other);
	}
	
	void clear(){
		node_t* last = head;
		while(head){
			head = head->next;
			delete last;
			last = head;
		}
		// Normaly you never want to change head or you'll orphan part
		// of the list, but in this case we are wiping the list,
		// so it is ok to so and saves us a variable.
		head = NULL;
	}
 
  
  private:
  node_t* head;
  
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.

ostream& operator<<(ostream& out, const LList other){
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
