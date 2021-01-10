//
//  Graph.h
//  280_Graph_EvanWhite_MAC
//
//  Created by Evan White on 4/14/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#ifndef Graph1_h
#define Graph1_h
#include <string>
using namespace std;

const int MAX = 8;
class Graph{
private:
    int **workspace;
    bool visited[MAX];
    string SymbolTable[MAX];
    int vertex;
    int size;
public:
    Graph();
    void add(string,int,int);
    void DisplayMatrix();
    int lsutil(string);
    void load(string);
    void ArrayDisplay();
    void adjacency(int);
    void dfsutil(int);
    void dfs(int);


};

#endif /* Graph1_h */
