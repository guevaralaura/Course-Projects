#include "bst.h"
using namespace std;

// Default Constructor
// PRE:
// POST: root set to NULL
BST::BST()
{
  root = NULL;
}

// De-allocates dynamic memory associated with tree
// PRE:
// POST:
BST::~BST()
{
    Node* nd = root;
    
    while(nd)
    {
        nd = nd->left;
        
        if(!nd)
            
            
    }
}

// Insert value in tree maintaining bst property
// PRE:
// PARAM: value = value to be inserted
// POST: Value is inserted, in order, in tree
void BST::Insert(int value)
{
    cout << value << ", ";
  Node* newNode = new Node(value);
  Node* parent = root;
  Node* pos = root;
  bool isLeft = true;
  // Set new root if tree is empty
  if (root == NULL)
  {
    root = newNode;
  }
  else
  {
    // Find parent of new node
    while (pos != NULL)
    {
      parent = pos;
      if (value < parent->data)
      {
        pos = parent->left;
        isLeft = true;
      }
      else
      {
        pos = parent->right;
        isLeft = false;
      }
    }
    // Insert new node
    if (isLeft)
    {
      parent->left = newNode;
    }
    else
    {
      parent->right = newNode;
    }
  }
}

// Searches tree for target
// PRE:
// PARAM: target = value to be found
// POST: Returns true iff target is in tree
bool BST::Search(int target)
{
    Node* searcher = root;
    
    
    while(searcher)
    {
        if(searcher->data == target)
            return true;
        
        if(target < searcher->data)
            searcher = searcher->left;
        else
            searcher = searcher->right;
    }
    
    
  return false;
}

// Prints contents of tree pre, in, post order
// PRE:
// POST: Prints contents of tree three times:
//       pre order, in order and post order
void BST::Print()
{
    cout << endl;
  cout << "Pre Order" << endl;
  PreOrderPrint(root);
    cout << endl;
  cout << endl << "In Order" << endl;
  InOrderPrint(root);
    cout << endl;
  cout << endl << "Post Order" << endl;
  PostOrderPrint(root);
}

// Performs an in-order traversal of tree
// PRE:
// POST: Prints contents of tree in order
void BST::InOrderPrint(Node* nd)
{
    if(!nd)
        return;
    
    InOrderPrint(nd->left); //goes all the way to the left
    cout << nd->data << ", ";
    InOrderPrint(nd->right);

}

// Performs a pre-order traversal of tree
// PRE:
// POST: Prints contents of tree with pre order traversal
void BST::PreOrderPrint(Node* nd)
{
    if(!nd)
        return;
    
    cout << nd->data << ", ";
    PreOrderPrint(nd->left);
    PreOrderPrint(nd->right);


}

// Performs an post-order traversal of tree
// PRE:
// POST: Prints contents of tree with post order traversal
void BST::PostOrderPrint(Node* nd)
{
    if(!nd)
        return;
    
    PostOrderPrint(nd->left);
    PostOrderPrint(nd->right);
    cout << nd->data << ", ";

}




