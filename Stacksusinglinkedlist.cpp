#include<bits/stdc++.h>
using namespace std;

class Node{
public:
   int data;
   Node* next;
   Node(int d){
    this->data=d;
    this->next=NULL;
   }
};
class Stack{
   Node* head;
   int capacity;
   int currSize;
   public:
   Stack(int c){
    this->capacity=c;
    this->currSize=0;
    head=NULL;
   }
   int isEmpty(){
      return this->head==NULL;
   }
   int isFull(){
      return this->currSize==this->capacity-1;
   }
   void push(int d){
      if(this->currSize==this->capacity){
         cout<<"Overflow"<<endl;
         return;
      }
      Node* newNode=new Node(d);
      newNode->next=this->head;
      this->head=newNode;
      this->currSize++;
   }
   void pop(){
      if(this->head==NULL){
         cout<<"Underflow"<<endl;
         return;
      }
      head=head->next;
   }
   void getTop(){
      if(this->head==NULL){
         cout<<"Empty"<<endl;
         return;
      }
      cout<<this->head->data<<endl;
   }
   void display(){
      Node* temp=this->head;
      if(head!=NULL){
         while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
         }
         cout<<endl;
      }
   }
};

int main(){
   Stack st(5);
   st.push(5);
   st.push(4);
   st.push(3);
   st.push(2);
   st.getTop();
   st.push(6);
   st.push(5);
   st.getTop();
   st.display();
   st.pop();
   st.display();
   st.getTop();
   return 0;
}