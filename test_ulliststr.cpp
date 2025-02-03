#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;

  // Test push_back and push_front.
  test.push_back("Hello");
  test.push_back("World");
  test.push_front("First");
  cout << test.get(0) << " " << test.get(1) << " " << test.get(2);

  // Test back and front.
  cout << "Front: " << test.front();
  cout << " Back: " << test.back() << endl;

  // Test pop_back and pop_front.
  test.pop_back();
  test.pop_front();
  cout << "Front: " << test.front();
  cout << "Back: " << test.back() << endl;
  
  // Output size.
  cout << "Size: " << test.size() << endl;

  test.pop_front();

  return 0;
}