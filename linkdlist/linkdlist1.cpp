#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<" memmory is free for node with data"<<value<<endl;
    }

};
void insertathead(Node* & head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;

}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatposition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertathead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
     if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    Node* node2insert=new Node(d);
    node2insert->next=temp->next;
    temp->next=node2insert;
   
    
}
void deletenode(int position,Node* &head){
    //deleting start node
    if(position==1){
        Node* temp=head;
        head=head->next;
        delete temp;

    }else{
        //deleting any middle or last node
        Node* current=head;
        Node* prev=NULL;
        int count=1;
        while(count<=position){
            prev=current;
            current=current->next;
            count++;
        }
        prev->next=current->next;
        delete current;

    }
}
void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    //Node* head=node1;
    Node* tail=node1;
    Node* head=node1;
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertathead(head,9);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertattail(tail,12);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertatposition(head,tail,3,11);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertatposition(head,tail,5,13);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertatposition(head,tail,6,14);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deletenode(4,head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    


    return 0;
}