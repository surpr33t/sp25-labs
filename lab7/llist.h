#ifndef LLIST_H
#define LLIST_H

template <typename T>
class LList{
private:
  struct Item {
    Item(const T& v, Item* p, Item* n);
    T val;
    Item *prev;
    Item *next;
  };

public:
  LList();
  LList(const LList& other);
  LList& operator=(const LList& other);
  ~LList();

  int size() const;
  bool empty() const;
  void push_back(const T& val);
  T& get(int pos);
  void clear();

private:
  Item* getNodeAt(int pos) const;

  Item* mHead;
  Item* mTail;
  int mSize;
};

#include "llist.cpp"

#endif