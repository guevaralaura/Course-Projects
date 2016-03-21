#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

class BST
{
  public:
    // Default Constructor
    // PRE:
    // POST: root set to NULL
    BST();

    // De-allocates dynamic memory associated with tree
    // PRE:
    // POST: Value is inserted, in order, in tree
    // **NOTE: not implemented yet!
    ~BST();

    void Insert(int value);

    // Searches tree for target
    // PRE:
    // PARAM: target = value to be found
    // POST: Returns true iff target is in tree
    bool Search(int target);

    // Prints contents of tree pre, in, post order
    // PRE:
    // POST: Prints contents of tree three times:
    //       pre order, in order and post order
    void Print();

  private:
    // Node class
    class Node
    {
      public:
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(NULL), right(NULL) {};
    };

    Node* root;

    // Performs an in-order traversal of tree
    // PRE:
    // POST: Prints contents of tree in order
    void InOrderPrint(Node* nd);

    // Performs a pre-order traversal of tree
    // PRE:
    // POST: Prints contents of tree with pre order traversal
    void PreOrderPrint(Node* nd);

    // Performs an post-order traversal of tree
    // PRE:
    // POST: Prints contents of tree with post order traversal
    void PostOrderPrint(Node* nd);

};