#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    // constructor
    Node(int d){
        this ->data = d;
        this ->next = NULL;
        this ->prev = NULL;
    }
    // destructor
    ~Node(){
        int val = this -> data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for data "<<val<<endl;
    }
};
// traversing a linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// gives a length of linked list 

int getlength(Node* &head){ 
    int len = 0;
    Node* temp = head;
    while(temp!= NULL){
        len++;
        temp = temp->next;
    }
   return len;
    
}
// insert at head
void Insertathead(Node* &head,int d){
    // empty list
    if(head== NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else {
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}
// insert at tail
void Insertattail(Node* tail,int d){
    Node* temp =  new Node(d);
    tail -> next = temp;
    temp -> prev  = tail;
    tail = temp;
    
}
// insert at position
 void Insertatposition(Node* &tail,Node* &head,int position,int d){
     // insert at start
     if(position==1){
         Insertathead(head,d);
         return;
     }
     Node* temp = head;
     int cnt = 1;
     while(cnt < position-1){
         temp = temp-> next;
         cnt++;
     }
     // insert at last position
     if(temp->next == NULL){
         Insertattail(tail,d);
         return;
     }
     // creating a node for d
     Node* nodetoinsert = new Node(d);
     nodetoinsert -> next = temp -> next;
     temp-> next -> prev = nodetoinsert;
     temp -> next = nodetoinsert;
     nodetoinsert -> prev = temp;
 }
 // deleting a node 
  void deleto(int positon,Node* &head){
     //deleting a first node 
     if(positon == 1){
         Node* temp = head;
         temp -> next -> prev = NULL;
         head = temp-> next;
         // memroy free start Node
         temp->next = NULL;
         delete temp;
     }
     else{
         //deleting any middle node or last
         Node* curr = head;
         Node* prev = NULL;
         int cnt = 1;
         while(cnt<positon){
             prev = curr;
             curr = curr-> next;
             cnt++;
         }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        
         delete curr;
         
 }  
     
 }

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
   
    Insertathead(head,11);
    print(head);
     cout<<getlength(head)<<endl;
     Insertattail(tail,12);
     print(head);
     Insertatposition(tail,head,2,13);
     print(head);
    deleto(2,head);
    print(head);
    return 0;
}