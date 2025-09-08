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
    
    if (evens == NULL && odds == NULL) {
      evens = new Node(in->value, in->next);
      split(in->next, odds, evens);
      delete in;
      in = nullptr;
    } else if (evens == NULL && odds != NULL) {
      evens = in;
      split(in->next, odds, evens);
    } else {
      evens->next = in;
      split(in->next, odds, evens->next);
    }

  }

  // assign to odds
  else if (in != NULL && in->value % 2 == 1) {
  
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

  if (evens != NULL && evens->next != NULL && evens->next->value % 2 != evens->value % 2) {
    evens->next = NULL;
  }
  else if (odds != NULL && odds->next != NULL && odds->next->value % 2 != odds->value % 2) {
    odds->next = NULL;
  }

}

/* If you needed a helper function, write it here */
