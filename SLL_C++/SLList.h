#ifndef SLLLIST_H
#define SLLLIST_H

#include "SLLNode.h"

// Singly linked list class
// Defines functions to manipulate linked list

template<typename T>
class SLList {
public:
  //constructor
  SLList();

  //destructor
  ~SLList();

  //copy constructor
  SLList(const SLList <T>& other);

  //assignment constructor
  SLList<T>& operator = (const SLList<T>& other);

  unsigned size() const; // return the size of linked list
  bool empty() const; // return true if the list is empty and false if otherwise
  void push_front(const T& value); //insert at beginning of the list
  void push_back(const T& value); // insert at the end of the list
  void print() const; // print content of the list

  void pop_front(); // remove the first element of the list
  void pop_back(); // remove the last element of the list

  void clear(); // remove all elements of the list

  void insert(unsigned pos, const T& value, unsigned n = 1); //inserts new element into the list

  void erase(unsigned pos);
  void remove(const T& val);

  void rotate_right(unsigned k); // rotates list to the right k times



private:
  SLLNode<T>* head; // the first node in the linked list
  SLLNode<T>* tail; // the last node in the linked list
  unsigned listSize; // the size of the list

};

#endif