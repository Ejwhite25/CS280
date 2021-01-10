//
//  main.cpp
//  280_BST_EvanWhite_MAC
//
//  Created by Evan White on 2/10/20.
//  Copyright © 2020 Evan White. All rights reserved.
//
#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << boolalpha;
    BST b1 = BST();
    cout << "Inserting 30 50 10 70 5 35 20 35 15 0 40 65" << endl;
    b1.insert(30);
    b1.insert(50);
    b1.insert(10);
    b1.insert(70);
    b1.insert(5);
    b1.insert(35);
    b1.insert(20);
    b1.insert(35);
    b1.insert(15);
    b1.insert(0);
    b1.insert(40);
    b1.insert(65);
    cout << "Displaying" << endl;
    cout << "Expected" << endl;
    cout << "in order:   0   5  10  15  20  30  35  35  40  50  65  70" << endl;
    cout << "pre order:   30  10   5   0  20  15  50  35  35  40  70  65" << endl;
    cout << "post order" << endl;
    cout << "Actual" << endl;
    b1.displayInOrder();
    cout << endl;
    cout << "Pre Order" << endl;
    b1.displayPreOrder();
    cout << endl;
    cout << "Post Order" << endl;
    b1.displayPostOrder();
    cout << endl;
    cout << "Counting Leaves" << endl;
    cout << "Expected : 5" << endl;
    cout << "Actual" << endl;
    cout << b1.countLeaves() << endl;
    cout << "Finding Height" << endl;
    cout << "Expected : 4" << endl;
    cout << "Actual" << endl;
    cout << b1.height() << endl;
    cout << "Finding 40" << endl;
    Node* f = b1.Find(40);
    cout << "expected : found" << endl;
    cout << "Actual" << endl;
    cout << "Value Found Is" << " " << f->data << endl;
    cout << "Finding 33" << endl;
    cout << "expected : not found" << endl;
    cout << "actual" << endl;
    b1.Find(33);
    cout << "Deleting 0" << endl;
    b1.DeleteValue(0);
    cout << "Expected" << endl;
    cout << "5  10  15 20  30 35 35 40  50  65 70" << endl;
    cout << "Actual" << endl;
    b1.displayInOrder();
    cout << endl;
    cout << "Deleting 50" << endl;
    b1.DeleteValue(50);
    cout << "Expected" << endl;
    cout << "5  10  15 20  30 35 35 40 65 70" << endl;
    cout << "Actual" << endl;
    b1.displayInOrder();
    cout << endl;
    cout << "Deleting 33" << endl;
    cout << "Expected : not found" << endl;
    cout << "Actual" << endl;
    b1.DeleteValue(33);
    
    
}
