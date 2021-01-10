//
//  Collisions.cpp
//  280_Collisions_EvanWhite_MAC
/*Collisions
 CS280
 Evan White
 29 April 2020*/
//  Created by Evan White on 4/29/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iomanip>
#include "Collisions.h"
#include <iostream>

int HashTable::hashfunc(int v){
    return v % MAX;
}

HashTable::HashTable(){
    for(int i = 0; i < MAX; i++){
        workspace[i] = "";
        collisions[i] = 0;
        occurences[i] = 0;
        
    }
}

void HashTable::insert(int k, string v){
    int h = hashfunc(k);
    while(workspace[h] != "" && workspace[h] != v){
        h = hashfunc(h+1);
    }
    workspace[h] = v;
    occurences[h]++;
    if(occurences[h] > 1){
        collisions[h]++;
    }
}

int HashTable::SearchKey(string v){
    int h = hashfunc(stringtosum(v));
    while(workspace[h] != "" && workspace[h] != v ){
        h = hashfunc(h+1);
    }
    if(workspace[h] == ""){
        return -1;
    }
    else{
        return h;
    }
}

int HashTable::collsioncount(){
    int sum = 0;
    for(int i = 0; i < MAX; i++){
        if(collisions[i] >= 1){
            sum+=collisions[i];
        }
    }
    return sum;
}

void HashTable::Display(){
    for(int i = 0; i < MAX; i++){
    cout << setw(10) << "Hash" << " " <<
           setw(10) << "# of times hashed" << " " <<
           setw(10) << "Collisions" << '\n';
           cout <<  setw(10) << i <<
           setw(10) << occurences[i] <<
           setw(10) << collisions[i] << '\n';
           }
    cout << "There are" << " " <<  collsioncount() <<  " " << "Collisions" << endl;

}




int HashTable::stringtosum(string v){
    int sum = 0;
    for(int i =0; i < v.size(); i++){
        sum+=v[i];
    }
    return sum;
}
