#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left,*right;
};

Node *new_node(int key){
    Node *newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *insert(Node *node, int key){
    //base case
    if(node == NULL){
        return new_node(key);
    }
    else if(key < node->key){
        node->left = insert(node->left, key);
    }
    else{
        node->right = insert(node->right, key);
    }
    return node;
}
Node *successor(Node *node){
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}
Node *deleteNode(Node *node, int key){
    if(node == NULL){
        return node;
    }
    else if(key < node->key){
        node->left = deleteNode(node->left, key);
    }
    else if(key > node->key){
        node->right = deleteNode(node->right, key);
    }
    else{
      //  if(node->left == NULL && node->right == NULL){
      //      delete node;
      //      node = NULL; 
      //  }
        if(node->left == NULL){         // Way 1
           Node *temp = node->right; 
           delete node;
           return temp;
        }
        else if(node->right == NULL){   // Way 2
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else{
            Node *temp = successor(node->left);
            node->key = temp->key;
            node->left =deleteNode(temp->left, temp->key);
        }
    } 
    return node;
}


int main(){
    Node *root = NULL;

}