/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printlist(Node* head);
void deletelist(Node*& head);

int main(int argc, char* argv[])
{
  // Create sorted linked list (with odd and even numbers).
  Node* in = new Node(1, nullptr);
  in = new Node(2, in);
  in = new Node(4, in);
  in = new Node(5, in);
  in = new Node(7, in);
  in = new Node(8, in);

  // Declare odd and even linked lists.
  Node* odds = nullptr;
  Node* evens = nullptr;

  // Split first linked list into two separate linked lists  
  // (odd and even numbers) by calling function split().  
  split(in, odds, evens);

  // Output linked lists.
  cout << "Original: ";
  printlist(in);
  cout << "Odd: ";
  printlist(odds);
  cout << "Even: ";
  printlist(evens);

  // Delete.
  deletelist(odds);
  deletelist(evens);

  return 0;
}

void printlist(Node* head) {
  // Output entire linked list.
  Node* curr = head;
  while (curr != nullptr) {
    cout <<curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
}

void deletelist(Node*& head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  head = nullptr;
}