//
/*CS280
 Evan White
 WordsandLetters*/
//  LinkedListsWords.cpp
//  280_WordsAndLetters_EvanWhite_MAC
//
//  Created by Evan White on 3/30/20.
//  Copyright © 2020 Evan White. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <string>
#include "LinkedListsWords.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList(){
    top = bottom = nullptr;
}

void LinkedList::push(string v){
    WordNode* p = new WordNode;
    p->word= v;
    p->next = nullptr;
    if(top == nullptr){
        top = bottom = p;
    }
    else if(p->word <= top->word){
        p->next = top;
        top->prev = p;
        top = p;
    }
    else{
        WordNode* rear, * front;
        rear = nullptr;
        front = top;
        while(front != nullptr && front->word <= v){
            rear = front;
            front = front->next;
            
        }
        if(front == nullptr){
            bottom->next = p;
            p->prev = bottom;
            bottom = p;
        }
        else{
            rear->next = p;
            p->prev = rear;
            front->prev = p;
            p->next = front;
        }
    
    }
    
}
void LinkedList::display(){
    WordNode* runner = top;
    while(runner != nullptr){
        cout << runner->word<< " ";
        runner = runner->next;
    }
    cout << endl;
    
}
LetterQueue::LetterQueue(){
    top = bottom = nullptr;
    count = 0;
}

void LetterQueue::append(string w, string l){
    LetterNode* tmp = new LetterNode;
    tmp->letter = l;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    if(top == nullptr){
        top = bottom = tmp;
        
    }
    else if(tmp->letter <= top->letter){
        tmp->next = top;
        top->prev = tmp;
        top = tmp;
    }
    else{
        LetterNode* rear, * front;
        rear = nullptr;
        front = top;
        while(front != nullptr && front->letter <= l){
            rear = front;
            front = front->next;
        }
        if(front == nullptr){
            bottom->next = tmp;
            tmp->prev = bottom;
            bottom = tmp;
        }
        else{
            rear->next = tmp;
            tmp->prev = rear;
            front->prev = tmp;
            tmp->next= front;
            
        }
    
    }
    tmp->Words.push(w);
    remove(w);
    count++;
    
}
LetterNode* LetterQueue::remove(string w){
    LetterNode* temp = top;
    while(temp->next != nullptr && temp != nullptr){
        if(temp->letter == temp->next->letter){
            temp->next = temp->next->next;
            temp->Words.push(w);
        }
        else{
            temp = temp->next;
        }
    }
    return temp;
    
}
void LetterQueue::display(){
    LetterNode* tmp = top;
    while(tmp != nullptr){
        cout << tmp->letter << " ";
        tmp->Words.display();
        tmp = tmp->next;
        
    }
    
    
}

