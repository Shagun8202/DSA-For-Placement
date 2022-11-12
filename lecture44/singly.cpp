#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data)
{
    this -> data = data;
    this -> next = NULL;
}
};
// insert at head 
void Insertathead(Node* &head , int d ){
    Node* temp= new Node(d);
    temp-> next = head;
    head = temp;
    
}
// insert at tail
void Insertattail(Node* &tail,int f){
    Node* temp= new Node(f);
    tail -> next = temp;
    tail = temp;
    
}
 // insert at position
 void Insertatposition(Node* &head,Node* &tail,int postion, int m){
     // insert at start
     if(postion == 1){
         Insertathead(head,m);
         return;
     }
     Node* temp = head;
     int cnt = 1;
     while(cnt<postion-1){
         temp = temp->next;
         cnt++;
     
         
     }
     //insert at last psotion
     if(temp-> next == NULL){
         Insertattail(tail,m);
         return;
     }
     //craeting a node
     Node* nodetoinsert = new Node(m);
 nodetoinsert -> next = temp->next;
     temp -> next = nodetoinsert;
     
     
 }
 // printing linked list 
void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
      cout<< temp -> data<< " ";
      temp = temp -> next;
  }
}

 // deleting a node 
 void deleto(int positon,Node* &head){
     //deleting a first node 
     if(positon == 1){
         Node* temp = head;
         head = head->next;
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
         prev -> next = curr -> next;
         curr -> next = NULL;
         delete curr;
         
 }  
     
 }


int main() 
{   // created a new node
    Node* node1 = new Node(10);
    // cout<< node1->data << endl;
    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    // Insertathead(head,12);
    // Insertathead(head,13);
    // print(head);
    Insertattail(tail,12);
    Insertattail(tail,13);
     
    // Insertatposition(head,tail,2,18);
    // Insertatposition(head,tail,1,5);
    // Insertatposition(head,tail,6,9);
    // print(head);
    // cout<<endl;
    // cout<<"head"<<head->data<<endl;
    // cout<<"tail"<<tail->next<<endl;
    deleto(3,head);
    print(head);
    cout<<"tail"<<tail->next;
    
    return 0;
}
