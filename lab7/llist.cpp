#include "llist.h"

template <typename T>
LList<T>::Item::Item(const T& v, Item* p, Item* n)
: val(v), prev(p), next(n)
{
}

template <typename T>
LList<T>::LList() {
  mHead = new Item(T(), nullptr, nullptr);
  mTail = new Item(T(), mHead, nullptr);
  mHead->next = mTail;
  mSize = 0;
}

template <typename T>
LList<T>::LList(const LList& other) {
  mHead = new Item(T(), nullptr, nullptr);
  mTail = new Item(T(), mHead, nullptr);
  mHead->next = mTail;
  mSize = 0;

  Item* temp = other.mHead->next;
  while(temp != other.mTail){
    push_back(temp->val);
    temp = temp->next;
  }
}

template <typename T>
LList<T>& LList<T>::operator=(const LList& other) {
  if(this == &other) return *this;

  clear();

  Item* temp = other.mHead->next;
  while(temp != other.mTail){
    push_back(temp->val);
    temp = temp->next;
  }

  return *this;
}

template <typename T>
LList<T>::~LList() {
  clear();
  delete mHead;
  delete mTail;
}

template <typename T>
int LList<T>::size() const {
  return mSize;
}

template <typename T>
bool LList<T>::empty() const {
  return mSize == 0;
}

template <typename T>
void LList<T>::push_back(const T& val) {
  Item* n = new Item(val, mTail->prev, mTail);
  mTail->prev->next = n;
  mTail->prev = n;
  ++mSize;
}

template <typename T>
T& LList<T>::get(int pos) {
  return getNodeAt(pos)->val;
}

template <typename T>
void LList<T>::clear() {
  Item* curr = mHead->next;

  while(curr != mTail){
    Item* next = curr->next;
    delete curr;
    curr = next;
  }

  mHead->next = mTail;
  mTail->prev = mHead;
  mSize = 0;
}

template <typename T>
typename LList<T>::Item* LList<T>::getNodeAt(int pos) const {
  Item* curr = mHead->next;
  while(pos--) curr = curr->next;
  return curr;
}