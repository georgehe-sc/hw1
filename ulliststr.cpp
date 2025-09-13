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

std::string* ULListStr::getValAtLoc(size_t loc) const {

  int tot = loc;

  Item* current = head_;
  int offset = current->first;
  unsigned int counter = current->first;


  for (int i = 0; i <= tot; ++i) {

    if (counter == current->last) {
      

      if (counter != 10) {
        return NULL;
      } else if (counter == 10 && current->next == NULL) {
        return NULL;
      } else if ((tot+offset) % 10 == 0 && tot == i && tot != 0 and current->next != NULL) {
        return &current->next->val[0];
      } else {
        current = current->next;
        counter = 1;
        continue;
      }
    }

    if (i == tot) {
      return &current->val[(tot + offset) % 10];
    }

    ++counter;

  }

  return NULL;

};

void ULListStr::push_back(const std::string& val) {

  if (tail_ == NULL and head_ == NULL) {

    tail_ = new Item();
    head_ = tail_;

  } else if (tail_->last == 10) {

    Item* new_tail = new Item();
    tail_->next = new_tail;
    new_tail->prev = tail_;
    tail_ = new_tail;

  }

    tail_->val[tail_->last] = val;
    tail_->last += 1;

  size_ += 1;

}

void ULListStr::push_front(const std::string&val) {

  if (tail_ == NULL and head_ == NULL) {

    head_ = new Item();
    tail_ = head_;

    head_->first = 9;
    head_->last = 10;
    head_->val[9] = val;


  } else if (head_->first == 0) {

    Item* new_head = new Item();
    new_head->next = head_;
    head_->prev = new_head;
    head_ = new_head;

    head_->first = 9;
    head_->last = 10;
    head_->val[9] = val;
    
  } else {

    head_->first -= 1;
    head_->val[head_->first] = val;

  }

  size_ += 1;

}

void ULListStr::pop_back() {
  if (tail_ != NULL) {
    tail_->val[tail_->last-1] = "";
    tail_->last -= 1;

    if (tail_->last == tail_->first) {

      if (tail_->prev == NULL) {
        delete tail_;
        tail_ = NULL;
        head_ = NULL;
      } else {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = NULL;
      }

    }
  }


  size_ -= 1;
}

void ULListStr::pop_front() {
  if (head_ != NULL) {
    head_->val[head_->first] = "";
    head_->first += 1;

    if (head_->first == head_->last) {
      
      if (head_->next == NULL) {
        delete head_;
        head_ = NULL;
        tail_ = NULL;
      } else {

        head_ = head_->next;
        delete head_->prev;
        head_->prev = NULL;

      }

    }

    size_ -= 1;
  }
}

std::string const & ULListStr::back() const {

  return tail_->val[tail_->last-1];

}

std::string const & ULListStr::front() const {

  return head_->val[head_->first];

}

