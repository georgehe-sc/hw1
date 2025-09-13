/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
#include <vector>


Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;
	
	if(!content.empty())
	{
		// create head
		head = new Node(content[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(content.cbegin());
		++nextValIter;

		for(; nextValIter != content.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}
	}

	return head;

}


void delete_list(Node* list) {
  if (list->next != NULL) {
    delete_list(list->next);
  }

  delete list;

}

int main(int argc, char* argv[])
{



  // test case 1: one egative
  Node* input = makeList({-1,0,1,2,3});
  Node* odd = nullptr;
  Node* even = nullptr;

  split(input, odd, even);

  Node* looper = odd;

  do {
    std::cout << looper->value << std::endl;
    looper = looper->next;
  } while (looper->next != NULL);

  std::cout << looper->value << "\n" << std::endl;

  looper = even;

  std::cout << "evens: " << std::endl;

  do {
    std::cout << looper->value << std::endl;
    looper = looper->next;
  } while (looper->next != NULL);

  std::cout << looper->value << "\n" << std::endl;

  looper = input;

  std::cout << "input list" << std::endl;

  if (input == NULL) {
    std::cout << "yup" << std::endl;
  }

  delete_list(even);
  delete_list(odd);

  // test case 2: double inputs

  Node* input1 = makeList({0,0,1,1,2,2,3,3,4,4});
  Node* odd1 = nullptr;
  Node* even1 = nullptr;

  split(input1, odd1, even1);

  Node* looper1 = odd1;

  do {
    std::cout << looper1->value << std::endl;
    looper1 = looper1->next;
  } while (looper1->next != NULL);

  std::cout << looper1->value << "\n" << std::endl;

  looper1 = even1;

  std::cout << "evens: " << std::endl;

  do {
    std::cout << looper1->value << std::endl;
    looper1 = looper1->next;
  } while (looper1->next != NULL);

  std::cout << looper1->value << "\n" << std::endl;

  looper1 = input1;

  std::cout << "input list" << std::endl;

  if (input1 == NULL) {
    std::cout << "yup" << std::endl;
  }

  delete_list(even1);
  delete_list(odd1);
  
  // test case 3: all negative

  Node* input2 = makeList({-6,-5,-4,-3,-2,-1});
  Node* odd2 = nullptr;
  Node* even2 = nullptr;

  split(input2, odd2, even2);

  Node* looper2 = odd2;

  do {
    std::cout << looper2->value << std::endl;
    looper2 = looper2->next;
  } while (looper2->next != NULL);

  std::cout << looper2->value << "\n" << std::endl;

  looper2 = even2;

  std::cout << "evens: " << std::endl;

  do {
    std::cout << looper2->value << std::endl;
    looper2 = looper2->next;
  } while (looper2->next != NULL);

  std::cout << looper2->value << "\n" << std::endl;

  looper2 = input2;

  std::cout << "input list" << std::endl;

  if (input2 == NULL) {
    std::cout << "yup" << std::endl;
  }

  delete_list(even2);
  delete_list(odd2);

}
