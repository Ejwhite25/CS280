//
//  Graph.cpp
//  280_Graph_EvanWhite_MAC
//
//  Created by Evan White on 4/14/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include "Graph.h"
#include <iostream>
#include <fstream>
using namespace std;
Graph::Graph(){
    size = 0;
    vertex = 0;
    workspace = new int*[MAX];
   for(int i = 0; i < MAX; i++) {
      workspace[i] = new int[MAX];
      for(int j = 0; j < MAX; j++) workspace[i][j] = 0;
   }
}
void Graph::add(string c,int x, int y){
    if(c == "<>"){
        workspace[x][y] = 1;
        workspace[y][x] = 1;
    }
    else{
        workspace[x-1][y-1] = 1;
        workspace[y-1][x-1] = 0;
    }
    vertex++;
   
}

void Graph::DisplayMatrix(){
    cout<<"\n\n"<<setw(10)<<"";
    for(int i = 0; i < size-1; i++)
        cout<<setw(3)<<"("<<SymbolTable[i+1]<<")";
       cout<<"\n\n";
    for(int i = 0; i < size-1; i++) {
       cout<<setw(3)<<"("<<SymbolTable[i+1]<<")";
       for(int j = 0; j < vertex; j++) {
          cout<<setw(10)<<workspace[i][j];
       }
       cout<<"\n\n";
    }
    }


int Graph::lsutil(string v){
    for(int i = 0; i < size; i++){
        if(SymbolTable[i] == v)
            return i;
            i++;
    }
    return -1;
}
void Graph::load(string c){
    if(lsutil(c) == -1){
        for(int i = 0; i < MAX; i++){
            SymbolTable[i] = c;
        }
        size++;
    }
    else{
        return;
    }
}
void Graph::dfsutil(int x){
    visited[x] = true;
    cout <<  "Vertex:" << SymbolTable[x] << " " << endl;
    for(int i = 0; i < size; i++){
        if(!visited[i]){
            dfsutil(i);
        }
    }
    
}
void Graph::dfs(int v){
    for(int i =0; i < v; i++){
        visited[i] = false;
    }
    dfsutil(v);
}
void Graph::ArrayDisplay(){
    for(int i = 0; i < size; i++){
        cout << SymbolTable[i] << endl;
    }
}

void Graph::adjacency(int d){
    for(int i = 0; i < d; i++){
        cout << "Vertex:" << SymbolTable[d] << endl;
    }
}

