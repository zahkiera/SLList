#include "SLList.h"
#include <iostream>

template <typename T> // constructor

SLList<T>::SLList() {
  head = tail = nullptr;
  listSize = 0;
}

template <typename T> // destructor
SLList<T>::~SLList() {
  clear();
}

template <typename T> // copy constructor
SLList<T>::SLList(const SLList<T>& other) {
  head = tail = nullptr;
  listSize = 0;
  SLLNode<T>* cur = other.head;
  while (cur) {
    push_back(cur->data);
    cur = cur->next;
  }
}

template <typename T> // assignment operator
SLList<T>& SLList<T>::operator = (const SLList<T>& other) { 
  clear(); // clear the list you had
  SLLNode<T> *cur = other.head;
  while (cur) {
    push_back(cur->data); // assign values of other list to new one
    cur = cur->next;
  }
  return *this;
}

template <typename T>
bool SLList<T>::empty() const{
  if (head) {
    return false;
  }
  return true;
}

// push front creates a new node at the front of the linked list
template <typename T>
void SLList<T>::push_front(const T& val) {
  head = new SLLNode<T>(val, head); // create new node (which will be the new head), add value and make it point to the old head
  listSize++;
  if (listSize == 1) {
    tail = head;
  }
}

template <typename T>
void SLList<T>::push_back(const T& val) {
  if (empty()) {
    push_front(val);
  }
  /* if no tail and you needed to traverse the list
  SLLNode<T>* cur = head;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new SLLNode<T>(val);
  listSize++;*/

  /* 
  SLLNode<T>* cur = tail;
  SLLNode<T>* temp = new SLLNode<T>(val);
  cur->next = temp;
  tail = temp;
  delete temp;
  delete cur;*/
  else {
  tail->next = new SLLNode<T>(val);
  tail = tail->next;
  listSize++;
  }
}

template <typename T>
void SLList<T>::pop_front() {
  if (empty()) {
    return;
  }
  SLLNode<T>* temp = head;
  head = head->next;
  temp = nullptr;
  delete temp;
  listSize--;
}

template <typename T>
void SLList<T>::pop_back() {
  if(empty()) {
    return;
  }
  if (listSize == 1) {
    pop_front();
  }
  
  SLLNode<T>* cur = head;

  while (cur->next && cur->next->next) { // while there are two nodes in front
    cur = cur->next; // go to next node
  }
  cur->next = nullptr; // delete old tail
  tail = cur; // make cur the new tail
  listSize--; // reduce size
}

template <typename T>
void SLList<T>::print() const {
  if (listSize == 0) {
    std::cout << "Empty list\n";
    return;
  }
  SLLNode<T>* cur = head;
  for (int i = 0; i < listSize; i++) {
    std::cout << cur->data << ' ';
    cur = cur->next;
  }
}

template <typename T>
void SLList<T>::clear() {
  if (empty()) {
    return;
  }
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
void SLList<T>::insert(unsigned pos, const T& value, unsigned n) {
  if (pos > listSize || pos < 0) {
    std::cout << "Invalid position, cannot insert\n";
    return;
  }
  else if (pos == listSize) {
    for (int i = 0; i < n ; i++) {
      push_back(value);
    }
  }
  else if (pos == 0) {
    for (int i = 0; i < n; i++) {
      push_front(value);
    }
  }
  else {
    SLLNode<T>* cur = head;
    
    for (int i = 0; i < pos-1; i++) {
      cur = cur->next;
    }
    for (int j = 0; j < n; j++) {
      cur->next = new SLLNode<T>(value, cur->next); // right side performed first and then assigned to left, that's why it's ok for the pointer of the new node to be the current cur->next and then you assign a new cur->next
      listSize++; // MUST HAVE FOR IT TO WORK. Other functions such as print depened on a correct listSize
      /*
      or you can use a pointer: 
      SLLNode<T>*newNode = new SLLNode<T>(val,cur->next)
      cur->next = newNode
      */
    }
  }   
}

template <typename T>
void SLList<T>::erase(unsigned pos) {
  if (empty()) {
    std::cout << "Empty list\n";
    return;
  }
  else if (pos >= listSize || pos < 0) {
    std::cout << "Invalid position, cannot erase\n";
    return;
  }
  else if (pos == 0) {
    pop_front();
  }
  else if (pos == listSize - 1) {
    pop_back();
  }
  else {
    SLLNode<T>* cur = head;
    for (int i = 0; i < pos - 1; i++) {
      cur = cur->next;
    }
    SLLNode<T>* to_delete = cur->next;
    cur->next = cur->next->next;
    delete to_delete;
    listSize--;
  }
}

template <typename T>
void SLList<T>::remove(const T& val) {
  if (empty()) {
    std::cout << "Empty list\n";
    return;
  }
  else {
    SLLNode<T>* cur = head;
    SLLNode<T>* prev = nullptr;
    while (cur) {
      if (cur->data == val) {
        if (cur == head) {
          pop_front();
          cur = head;
        }
          else if (cur == tail) { // necessary so tail doesnt contain junk data
            pop_back();
            cur = tail;
          }
        else {
          SLLNode<T>* to_delete = cur;
          prev->next = cur->next;
          delete to_delete;
          cur = prev->next;
          listSize--;
        }
      }
      else {
        prev = cur;
        cur = cur->next;
      }
    }
  }
}

template <typename T>
void SLList<T>::rotate_right(unsigned k) {
  if (empty()) {
    std::cout << "Empty list\n";
    return;
  }
  else if (k == 0) {
    return;
  }
  else {
    for (int i = 0; i < k; i++) {
      push_front(tail->data);
      pop_back();
    }
  }
}
