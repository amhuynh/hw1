#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string* ULListStr::getValAtLoc(size_t loc) const {
  // Base case.
  if (loc >= size_) {
    return nullptr;
  }

  // Declaration.
  Item* curr = head_;
  size_t index = loc;

  // Traverse items to find correct node.
  while (curr != NULL) {
    size_t range = curr->last - curr->first;
    if (index < range) {
      return &(curr->val[curr->first + index]);
    }
    index -= range;
    curr = curr->next;
  }

  // Return.
  return nullptr;
}

void ULListStr::push_back(const std::string& val) {
  // Add value to back of list

  if (tail_ == nullptr || tail_->last == ARRSIZE) {
    Item* newNode = new Item();
    if (tail_ != nullptr) {
      tail_->next = newNode;
      newNode->prev = tail_;
    } else {
      head_ = newNode;
    }
    tail_ = newNode;
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back() {
  // Remove value from back of list

  if (size_ == 0) {
    return;
  }

  tail_->last--;

  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    delete temp;
  }

  size_--;
}

void ULListStr::push_front(const std::string& val) {
  // Add value to front of list.

  if (head_ == nullptr || head_->first == 0) {
    Item* newNode = new Item();
    newNode->val[ARRSIZE - 1] = val;
    newNode->first = ARRSIZE - 1;
    newNode->last = ARRSIZE;

    if (head_ != nullptr) {
      newNode->next = head_;
      head_->prev = newNode;
    } else {
      tail_ = newNode;
    }
    head_ = newNode;
  } else {
    head_->val[--head_->first] = val;
  }

  size_++;
}

void ULListStr::pop_front() {
  // Remove value from front of list.

  if (empty()) {
    return;
  }

  head_->first++;
  size_--;

  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    }
    else{
      tail_ = nullptr;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const {
  // Get value at back of list.
  if(empty()) {
    throw std::out_of_range("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  // Get value at front of list.
  if(empty()) {
    throw std::out_of_range("List is empty");
  }
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
