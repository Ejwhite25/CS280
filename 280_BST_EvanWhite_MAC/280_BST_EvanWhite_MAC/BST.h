//
//  BST.h
//  280_BST_EvanWhite_MAC
//
//  Created by Evan White on 2/10/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#ifndef BST_h
#define BST_h
struct Node{
    int data;
    Node* left, * right;
};

class BST{
private:
    Node* root;
    Node* insert(int, Node*);
    int getsize(Node*);
    void displayInOrder(Node*);
    void displayPreOrder(Node*);
    void displayPostOrder(Node*);
    int countLeaves(Node*);
    bool DeleteValue(Node*, Node*, Node*);
    int height(Node*);
    Node* Find(Node* , int);
public:
    BST();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    int countLeaves();
    int height();
    Node* Find(int);
    void insert(int);
    int getSize();
    void DeleteValue(int);
};
#endif /* BST_h */
