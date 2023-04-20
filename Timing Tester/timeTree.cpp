#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct node {
   int data;
   struct node *leftChild, *rightChild;
};
struct node *root = NULL;
struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = item;
   temp->leftChild = temp->rightChild = NULL;
   return temp;
}
void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   
   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;
         
         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;
            
            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;
            
            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
struct node* search(int data){
   struct node *current = root;
  // printf("\nVisiting elements: ");
   while(current->data != data) {
      if(current != NULL) {
      //   printf("%d ",current->data);
         
         //go to left tree
         if(current->data > data) {
            current = current->leftChild;
         }//else go to right tree
         else {
            current = current->rightChild;
         }
         
         //not found
         if(current == NULL) {
            return NULL;
         }
      }
   }
   return current;
}
void printTree(struct node* Node){
   if(Node == NULL)
      return;
   printTree(Node->leftChild);
   printf(" --%d", Node->data);
   printTree(Node->rightChild);
}
int main(){

    for ( int x = 0; x < 50000; x++)
    {
        insert(x);
    }
   struct node* k;
   k = search(25001);
   if(k != NULL)
      cout << endl << "Found "<< endl;
   else
      cout << "not found" << endl;
   return 0;
}