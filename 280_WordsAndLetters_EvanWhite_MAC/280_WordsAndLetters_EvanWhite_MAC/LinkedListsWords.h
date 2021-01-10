//
/*CS280
 Evan White
 WordsandLetters*/
//  LinkedListsWords.h
//  280_WordsAndLetters_EvanWhite_MAC
//
//  Created by Evan White on 3/30/20.
//  Copyright © 2020 Evan White. All rights reserved.
//
#ifndef LinkedListsWords_h
#define LinkedListsWords_h
#include <iostream>
using namespace std;

struct WordNode{
    string word;
    WordNode* next;
    WordNode* prev;
};

class LinkedList{
private:
    WordNode* top, * bottom;
public:
    LinkedList();
    void push(string);
    void display();
    
};

struct LetterNode{
    string letter;
    LetterNode* next;
    LetterNode* prev;
    LinkedList Words;
};

class LetterQueue{
private:
    LetterNode* top, * bottom;
    int count;
public:
    LetterQueue();
    void append(string,string);
    LetterNode* remove(string);
    void display();
    
};

#endif /* LinkedListsWords_h */

