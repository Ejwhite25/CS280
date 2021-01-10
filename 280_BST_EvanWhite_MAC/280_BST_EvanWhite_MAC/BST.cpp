//
//  BST.cpp
//  280_BST_EvanWhite_MAC
//
//  Created by Evan White on 2/10/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include "BST.h"
#include <iostream>
#include <stdio.h>
using namespace std;

BST::BST(){
    root = nullptr;
}
Node* BST::Find(Node* r, int v){
    while(r != nullptr){
    if(r->data == v){
        return r;
    }
    else if(v  < r->data){
        return Find(r->left,v);
    }
    else if(v > r->data){
        return Find(r->right , v);
    
    }
}
cout << v << " " <<  "not found" << endl;
return nullptr;

}
Node* BST::Find(int v){
    return Find(root, v);
    
}
bool BST::DeleteValue(Node* r,Node* target, Node* parent){
    Node* runner;
    Node* subtree;
    while(target != nullptr){
    if(target->left != nullptr && target->right != nullptr){
        runner = target->right;
        parent = target;
        while(runner->left != nullptr){
            parent = runner;
            runner = runner->left;
        }
        target->data = runner->data;
        target = runner;
    }
    subtree = target->left;
    if(subtree == nullptr){
        subtree = target->right;
    }
    if(parent == nullptr){
        root = subtree;
    }
    else if(parent->left == target){
        parent->left = subtree;
    }
    else{
        parent->right = subtree;
    }
    delete target;
    target = nullptr;
    return true;
    }
    cout << "Value is not deleted" << endl;
    return false;
    
}
void BST::DeleteValue(int v){
    Node* parent = nullptr;
    Node* target = root;
    while(target != nullptr && target->data != v){
        if(v < target->data){
            parent = target;
            target = target->left;
        }
        else{
            parent = target;
            target = target->right;
        }
        
        
    }
    DeleteValue(root,target,parent);
    
}
Node* BST::insert(int v, Node *r){
    if(r == nullptr){
        r = new Node;
        r->left = r->right = nullptr;
        r->data = v;
        return r;
    }
    else if(v < r->data){
        r->left = insert(v,r->left);
        return r;
    }
    else{
        r->right = insert(v, r->right);
        return r;
    }
}

int BST::getsize(Node *r){
    if(r == nullptr){
        return 0;
    }
    else{
        return 1 + getsize(r->left) + getsize(r->right);
    }
}

int BST::getSize(){
    return getsize(root);
}


void BST::insert(int v){
    root = insert(v,root);
}

void BST::displayInOrder(){
    displayInOrder(root);
}
int BST::countLeaves(Node* r){
    if(r == nullptr){
           return 0;
       }
       
       int left = countLeaves(r->left);
       int right = countLeaves(r->right);
       
       if(left > right){
           return left + 1;
       }
       else return right + 1;
}
int BST::countLeaves(){
    return countLeaves(root);
}
void BST::displayInOrder(Node* r) {
    if (r != nullptr)
    {
         displayInOrder(r->left);
        cout.width(4); cout << r->data << "";
        displayInOrder(r->right);
    }
}//helper
void BST::displayPreOrder(){
    displayPreOrder(root);
}
void BST::displayPreOrder(Node* r ){
    if(r != nullptr){
        cout.width(4); cout << r->data << "";
        displayPreOrder(r->left);
        displayPreOrder(r->right);
    }
}//helper
void BST::displayPostOrder(){
    displayPostOrder(root);
}

void BST::displayPostOrder(Node* r){
    if(r != nullptr){
        displayPostOrder(r->left);
        displayPostOrder(r->right);
        cout.width(4); cout << r->data << "";
        
    }
}//helper
int BST::height(Node* r){
   if(r == nullptr){
       return 0;
   }
   if(r->left == nullptr && r->right == nullptr){
       return 1;
   }
   else{
       return  height(r->left) + height(r->right);
   }
}
int BST::height(){
    return height(root);
}


