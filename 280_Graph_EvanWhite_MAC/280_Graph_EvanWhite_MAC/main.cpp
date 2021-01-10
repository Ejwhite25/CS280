//
//  main.cpp
//  280_Graph_EvanWhite_MAC
//
//  Created by Evan White on 4/14/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Graph.h"
using namespace std;

const char identifier = '*';
int main(){
    Graph g1 = Graph();
    string command;
    string line;
    string str;
    string city1;
    string city;
    string type;
    string city2;
    string city3;
    ifstream ifile("Test1.txt");
    do {
        ifile >> command;
        cout << "Command:" << command << endl;
        if(command == "*graph"){
            cout << "Graph" << endl;
            do {
                getline(ifile,line);
                if(line[0] != identifier){
                    istringstream ss(line);
                    ss >> city1;
                    ss >> type;
                    ss >> city2;
                    ss >> city3;
                    if(ss){
                        g1.load(city1);
                        g1.load(city2);
                        g1.load(city3);
                        g1.add(type,g1.lsutil(city1),g1.lsutil(city2));
                        g1.add(type,g1.lsutil(city1),g1.lsutil(city3));
                    }
                    else{
                        g1.load(city1);
                        g1.load(city2);
                        g1.add(type,g1.lsutil(city1),g1.lsutil(city2));
                        }
                }
            }while(line[0] != identifier);
            command = line;
        }
        if(command == "*matrix"){
            g1.DisplayMatrix();
        }
    }while(!ifile.eof());
    ifile.close();
}
    
