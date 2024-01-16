#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertathead(Node* &head,int data){
    Node* newnode=new Node(data);
    newnode->next=head;
    head=newnode;
}
void insertattail(Node* &tail,int data){
    Node* newnode=new Node(data);
    tail->next=newnode;
    tail=newnode;
}

void display(Node *first){
        Node* temp=first;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;

    }

int main(){
    Node *head=new Node(10);
    
   Node* tail=head;

display(head);
insertathead(head,50);

display(head);
insertathead(head,30);

display(head);
insertattail(tail,70);
display(head);
return 0;
}