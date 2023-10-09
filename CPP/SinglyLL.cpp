#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data= data;
        this->next= NULL;
    }
};

void insertAthead(Node* &head, int d)
{
    //create new node
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    //create new node
    Node* temp = new Node(d);

    tail->next = temp;
    //tail = tail->next;
    tail= temp;
}

void insertAtPos(Node* &tail, Node* &head, int d, int pos)
{
    if(pos == 1)
    {
        insertAthead(head, d);
        return;
    }
    //create new node
    Node* temp = new Node(d);
    Node* curr = head;
    
    int cnt = 1;
    while(cnt< pos-1)
    {
        curr= curr->next;
        cnt++;
    }
    temp->next = curr->next;
    curr->next = temp;

}
//delete function
void deleteAtHead(Node* &head)
{
    Node* temp = head;
    head = head->next;
    temp -> next = NULL;
    free(temp);
}

void deleteAtTail(Node* &tail, Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    while(curr->next != NULL)
    {
        prev = curr;
        curr= curr->next;
    }
    prev->next = NULL;
    curr -> next = NULL;
    free(curr);
    tail = prev;
}

void deleteAtPos(Node* &head, int pos)
{
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt<pos)
    {
        prev = curr;
        curr= curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr -> next = NULL;
    free(curr);

}

void print(Node* &head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        cout<<temp->data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    //create new node
    Node* node1 = new Node(10);
    
    //head pointed to starting node
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout<<endl;
    insertAthead(head, 12);
    print(head);
    cout<<endl;
    insertAthead(head, 15);
    print(head);
    cout<<endl;
    insertAtTail(tail, 13);
    print(head);
    cout<<endl;
    insertAtTail(tail, 16);
    print(head);
    cout<<endl;
    insertAtPos(tail, head, 20, 4);
    print(head);
    cout<<endl;
    insertAtPos(tail, head, 25, 6);
    print(head);
    cout<<endl;
    deleteAtHead(head);
    print(head);
    cout<<endl;
    deleteAtTail(tail, head);
    print(head);
    cout<<endl;
    cout<<"done"<<endl;
    deleteAtPos(head, 5);
    print(head);
    cout<<endl;

    return 0;
}
