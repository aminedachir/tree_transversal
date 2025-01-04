#include <iostream>
#include <queue>
#include "linkedLists.h"
#include <random>

using namespace std;

struct Node {
  int value;
  Node *left;
  Node *right;
};

void insert(Node *&root, int value) {
  if (root == nullptr)
     root = new Node{value, nullptr, nullptr};
  else
     if (value < root->value)
        insert(root->left, value);
      else
        insert(root->right, value);

}

bool rechercheElement(Node* arbre, int v) {
    if (arbre == nullptr)
        return false;
    if (arbre->value == v)
         return true;
    if (v < arbre->value)
          return rechercheElement(arbre->left, v);
     else
         return rechercheElement(arbre->right, v);
}


void preorderTraversal(Node* node) {
  if (node != nullptr) {
    cout << setw(6) << node->value  ;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }
}

void inorderTraversal(Node* node) {
  if (node != nullptr) {
    inorderTraversal(node->left);
    cout << setw(6) <<node->value  ;
    inorderTraversal(node->right);
  }
}

void postorderTraversal(Node* node) {
  if (node != nullptr) {
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout <<setw(6) << node->value  ;
  }
}

void breadthFirstTraversal(Node* node) {
  queue<Node*> q;
  q.push(node);

  while (!q.empty()) {
    Node* currentNode = q.front();
    q.pop();

    cout << setw(6) <<currentNode->value  ;

    if (currentNode->left != nullptr) {
      q.push(currentNode->left);
    }

    if (currentNode->right != nullptr) {
      q.push(currentNode->right);
    }
  }
}


int random(int min, int max)
{

return((rand() % (max - min + 1)) + min);

}
int main() {

 for(int j =0; j<30; j++)   {

    Node *root = nullptr;
    /******************/

     Nd* myList = nullptr;

    // Inserting elements at the end of the list
    int n ;


   /* cout<<"Number of elemnrs : ";
    cin>> n;


    cout<<"List : " <<endl;
    for(int i = 0; i<n; i++){
       int s;
       cin>> s;
       insertAtEnd(myList, s);
    }*/

 int min= 2;
 int max= 15;

     n = random(min, max);

n = 20;
    //cout<<"List : " <<endl;
    for(int i = 0; i<n; i++){
            min = -5; max = 200;
       int s = random(min, max);
      insertAtEnd(myList, s);
    }
    // Displaying the elements of the list
    cout << " \nList : ";
    displayList(myList);



   Nd* current = myList;
    while (current != nullptr) {
        insert(root, current->data );
        current = current->next;
    }

  // List of elements to insert into the tree


   /* int values[] = {10, 5, 15, 3, 8, 12, 18};
 cout<<" {10, 5, 15, 3, 8, 12, 18}"<<endl;
    // Insert each element into the tree
    for (int value : values) {
         insert(root, value);
    }*/






  // Create a binary search tree

  /* Recherche*/

  int t;
  cout<<" Find the number : ";
   cin>>t;
  bool resultat = rechercheElement(root, t);
   if (resultat) {
         cout << " exist" <<  endl;
    } else {
       cout << "not exist" <<  endl;
    }

/*************************************************/


   cout << "\nTransvarsal (parcours) : " <<endl;;
   // Preorder traversal
  cout << "   preorder (prefixe)        : ";
  preorderTraversal(root);
  cout << endl;

  cout << "   inorder (infixe )         : ";
  // Inorder traversal
  inorderTraversal(root);
  cout << endl;

  // Postorder traversal
  cout << "   postorderorder (Postfixe) : ";
  postorderTraversal(root);
  cout << endl;

  // Breadth-first traversal
  cout << "   breadth-First (Largeur)   : ";
  breadthFirstTraversal(root);

  cout<<" \n\n****************************************\n";

 }
  cout << "  \n\n\n";





  return 0;
}

