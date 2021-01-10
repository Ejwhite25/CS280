//
//  Collisions.h
//  280_Collisions_EvanWhite_MAC
/*Collisions
CS280
Evan White
29 April 2020*/
//  Created by Evan White on 4/29/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#ifndef Collisions_h
#define Collisions_h
#include <string>
#include <iostream>
using namespace std;
const int MAX = 167;

class HashTable{
private:
    int collisions[MAX];
    string workspace[MAX];
    int occurences[MAX];
public:
    HashTable();
    void insert(int,string);
    void Display();
    int collsioncount();
    int SearchKey(string);
    int hashfunc(int);
    int stringtosum(string);
};
#endif /* Collisions_h */
