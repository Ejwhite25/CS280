/*280
 Linked List
 Evan White */
#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class LinkedList{
private:
    Node *top , *bottom;
public:
    LinkedList();
    void insert(int);
    bool Delete(int);
    void display();
    
};
LinkedList::LinkedList(){
    top = bottom = nullptr;
}

void LinkedList::insert(int v){
    Node* p = new Node;
    p->data = v;
    p->next = nullptr;
    if(top == nullptr ||top->data > p->data ){
        p->next = top;
        top = p;
    }
    else{
        bottom = top;
        while(bottom->next != nullptr && bottom->next->data < p->data){
            bottom = bottom->next;
        }
        p->next = bottom->next;
        bottom->next = p;
    }
    
}
bool LinkedList::Delete(int v){
    Node *front, *rear;
    rear = nullptr;
    for(front = top; front != nullptr; rear = front,front = front->next){
        if(front->data == v){
            if(rear == nullptr){
                top = front->next;
                
            }
            else{
                rear->next = front->next;
            }
            delete front;
            return true;
        }
    }
    return false;
    
    
}
void LinkedList::display(){
    Node* runner = top;
    while(runner != nullptr){
        cout.width(4); cout << right << runner->data << "";
        runner = runner->next;
        }
        cout << endl;
}
int main(){
    LinkedList l1 = LinkedList();
    cout << "inserting integers: 12, -8, 14, 2, 10, -20, 30" << endl;
    l1.insert(12);
    l1.insert(-8);
    l1.insert(14);
    l1.insert(2);
    l1.insert(10);
    l1.insert(-20);
    l1.insert(30);
    cout << "Expected:" << endl;
    cout << "-20 -8 2 10 12 14 30" << endl;
    cout << "Actual:" << endl;
    l1.display();
    cout << "Deleting 12" << endl;
    cout << "Expected:" << endl;
    cout << "-20 -8 2 10 14 30" << endl;
    cout << "Done" << endl;
    cout << "Actual:" << endl;
    bool result = l1.Delete(12);
    l1.display();
    if(result == true){
        cout << "Done" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
    cout << "Deleting 30" << endl;
    cout << "Expected:" << endl;
    cout << "-20 -8 2 10 14" << endl;
    cout << "Done" << endl;
    cout << "Actual:" << endl;
    bool result2  = l1.Delete(30);
    l1.display();
    if(result2 == true){
        cout << "Done" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
    cout << "Deleting 9" << endl;
    cout << "Expected:" << endl;
    cout << "-20 -8 2 10 14" << endl;
    cout << "Fail" << endl;
    cout << "Actual:" << endl;
    bool result3  = l1.Delete(9);
    l1.display();
    if(result3 == true){
        cout << "Done" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
    
  
    
    
    
    
}
