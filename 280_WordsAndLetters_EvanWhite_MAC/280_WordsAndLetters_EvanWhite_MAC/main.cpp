//
/*CS280
Evan White
WordsandLetters*/
//  main.cpp
//  280_WordsAndLetters_EvanWhite_MAC
//
//  Created by Evan White on 4/1/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <fstream>
#include "LinkedListsWords.h"
#include <iostream>
using namespace std;



int main(){
    LetterQueue l1 = LetterQueue();
    string str;
    string word = str.substr(str.find(""));
    ifstream ifile("Text1.txt");
    if(!ifile.is_open()){
        cout << "File failed to open" << endl;
    }
    getline(ifile,str);
    while(!ifile.eof()){
        ifile >> word;
        for(int i = 0; i < word.size(); i++){
             if(isupper(word[i])){
                 word[i] = tolower(word[i]);
         }
        
}
string letter = word.substr(0,1);
l1.append(word,letter);
}
l1.display();

}
