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


  Node* input = makeList({2,5,6,7,8,10,72,256,300,9009,1111});
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

}
