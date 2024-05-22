
#include<iostream>
#include<string>


//   [2, 4, 3, -1, -1, 2, -1, 5, -1, 2, -1, -1, 6, -1, 4, 9, -1, -1, -1]


class Node {
 public:
 int data;
 Node * left = NULL;
 Node * right = NULL;
 
 Node(int _value) {
   data = _value;
   left = NULL;
   right = NULL;
 }

};


class Tree {

public:
  Node * root = NULL;
  int index = -1;

  Node * buildTree(int arr[]);
  int countNode(Node * _root); // calculate the number of nodes present.
  int nodeSum(Node * _root); // calculate the sum of all nodes 
  void preOrderTraversal(Node * _root);// print pre-order traversal
};

Node * Tree::buildTree(int arr[]) {
   index++;
   if(arr[index] == -1) return NULL;
   Node * newNode = new Node(arr[index]);
   newNode -> left = buildTree(arr);
   newNode -> right = buildTree(arr);
   return newNode;
}

int Tree::countNode(Node * _root) {
  if(!_root) return 0;
  return countNode( _root -> left) + countNode(_root -> right) + 1;
}

int Tree::nodeSum(Node * _root) {
  if(!_root) return 0;
  return nodeSum(_root -> left) + nodeSum(_root->right) + _root -> data;
}

void Tree::preOrderTraversal(Node * _root) {
  if(!_root) return;
   std::cout << _root -> data << "\t";
   preOrderTraversal(_root -> left);
   preOrderTraversal(_root -> right);
}

int main() {
  
 // tree preorder
 int arr[] = {2, 4, 3, -1, -1, 2, -1, 5, -1, 2, -1, -1, 6, -1, 4, 9, -1, -1, -1};
 Tree * bst = new Tree;
 bst -> root = bst -> buildTree(arr);
 bst -> preOrderTraversal(bst -> root); 
 std::cout << "\n";
 std::cout << "number of node: " << bst -> countNode(bst -> root);
 std::cout << "\n";
 std::cout << "sum of all nodes" << bst -> nodeSum(bst -> root);
 return 0;
}
