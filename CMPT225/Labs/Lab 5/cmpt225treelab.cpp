// cmpt225treelab.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "time.h"
#include "bst.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// forward declarations
void TreeTest();

int main()
{
    srand(static_cast <unsigned int> (time(0)));

  TreeTest();

  cout << endl << endl;
  return 0;
}

// Tests the traversal and search methods
void TreeTest()
{
  BST tree;
  int n = 20;
  int searches = 5;
  for (int i = 0; i < n; i++)
  {
    tree.Insert(rand() % (n*2));
  }

  tree.Print();
  cout << endl;
  for (int i = 0; i < searches; ++i)
  {
    int target = rand() % (n*2);
    cout <<  "search for " << target << ": " <<     tree.Search(target);
    cout << endl;
  }
}