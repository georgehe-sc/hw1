/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>


/* Add a prototype for a helper function here if you need */



void split(Node*& in, Node*& odds, Node*& evens)
{

  /* Add code here */

  // assign to evens
  if (in != NULL && in->value % 2 == 0) {
    
    // check if this is the head
    if (evens == NULL && odds == NULL) {
      evens = new Node(in->value, in->next);
      split(in->next, odds, evens);
      delete in;
      in = nullptr;
    } 
    
    // if not the head, then check if this is the first evens value ()
    
    else if (evens == NULL && odds != NULL) {
      evens = in;
      split(in->next, odds, evens);
    } else {
      evens->next = in;
      split(in->next, odds, evens->next);
    }

  }

  // assign to odds (same logic as assign to evens)
  else if (in != NULL && (in->value % 2 == 1 || in->value % 2 == -1)) {
  
    if (evens == NULL && odds == NULL) {
      odds = new Node(in->value, in->next);
      split(in->next, odds, evens);
      delete in;
      in = nullptr;
    } else if (odds == NULL && evens != NULL) {
      odds = in;
      split(in->next, odds, evens);
    } else {
      odds->next = in;
      split(in->next, odds->next, evens);
    }

    
  }


  // this makes sure that the last even/odd value in the list is pointing to null, and not a random value

  if (evens != NULL && evens->next != NULL && evens->next->value % 2 != evens->value % 2) {
    evens->next = NULL;
  }
  else if (odds != NULL && odds->next != NULL) {

    // odd * odd = odd, even * even = even, so this should keep the % 2 operator consisten

    int val1 = (odds->value) * (odds->value);
    int val2 = (odds->next->value) * (odds->next->value);

    if (val1 % 2 != val2 % 2) {
      odds->next = NULL;
    }
    
  }

}

/* If you needed a helper function, write it here */
