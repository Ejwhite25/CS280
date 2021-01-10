//
//  main.cpp
//  280_Collisions_EvanWhite_MAC
/*Collisions
CS280
Evan White
29 April 2020*/
//  Created by Evan White on 4/29/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include <iostream>
#include "Collisions.h"
#include <string>
#include <fstream>
using namespace std;

int main(){
    HashTable h1 = HashTable();
    string value;
    string v;
    int c;
    string v2;
    fstream ifile("names.txt");
    while(!ifile.eof()){
        ifile >> value;
        h1.insert(h1.stringtosum(value),value);
    }
    h1.Display();
    ifile.close();
    while(1){
        cout << "1. Insert value into table" << endl;
        cout << "2. Search for value in table" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> c;
        switch(c) {
            case 1:
                cout << "Enter value you'd like to insert:" << endl;
                cin >> v;
                h1.insert(h1.stringtosum(v),v);
                h1.Display();
                break;
            case 2:
                cout << "Enter value you'd like to find:" << endl;
                cin >> v2;
                if(h1.SearchKey(v2) == -1){
                    cout << "Value not found in table" << endl;
                    continue;
                }
                else{
                    cout << " " << v2 << " " << "Found at:" << h1.SearchKey(v2) << endl;
                }
                break;
            case 3:
                exit(1);
                
                
        }
    }
    return 0;
    
    
}
