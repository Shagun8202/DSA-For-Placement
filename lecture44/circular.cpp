# include <iostream>
using namespace std;

 class Node{
     public:
     
     int data;
     Node* next;
     
     // constructor
     
     Node(int d){
         this -> data = d;
         this -> next = NULL;
     }
     
     //destructor
     ~Node(){
         int value = this-> data;
         //memory free
         if(this->next!=NULL){
             delete next;
             this-> next = NULL ;
         }
         cout<<"memory is free for node with data"<<value<<endl;
     }
     
 };
 void insertnode(Node* &tail,int element , int d){
    
     //empty list 
     if(tail == NULL){
         Node* newnode = new Node(d);
         tail = newnode;
         newnode -> next = newnode;
     }
     else{
         // non empty list
          //assuming element is present
          Node* curr = tail;
          while(curr -> data != element){
              curr = curr-> next;
          }
          // element foud -> curr is reorensting element vala node 
          Node* temp = new Node(d);
          temp -> next = curr -> next;
          curr -> next = temp;
          
         
     }
 }
 void print(Node* tail){
     Node* temp = tail;
     do{
         cout<< tail -> data << " ";
         tail = tail -> next;
     }while(tail!=temp);
     cout<<endl;
 }
 void deletenode(Node* tail,int value){
     // empty list
     if(tail == NULL){
         cout<< "list is empty"<<endl;
     }
     else{
         // assuming value is presnet 
         Node* prev = tail;
         Node* curr = prev-> next;
         while(curr-> data != value){
             prev = curr;
             curr = curr -> next;
         }
         prev -> next = curr -> next;
         
         curr -> next = NULL;
         delete curr;
         if(tail == curr){
             tail = prev;
         }
         
     }
 }
 
 
 
 
 
 
 
 
 int main(){
     
     Node* tail = NULL;
     insertnode(tail,5,3);
     print(tail);
     insertnode(tail,3,5);
     print(tail);
      insertnode(tail,5,7);
     print(tail);
      insertnode(tail,5,6);
     print(tail);
      insertnode(tail,3,4);
     print(tail);
      insertnode(tail,7,8);
     print(tail);
     deletenode(tail,3);
     print(tail);
     return 0;
 }