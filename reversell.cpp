#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;

    }

};
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;

}
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
} 
node* reversei(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* neptr;
    while(curr!=NULL){
        neptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=neptr;

    }
    return prev;
}
node* reverser(node* &head){
     if(head==NULL||head->next==NULL){
         return head;
     }
     node* newhead=reverser(head->next);
     head->next->next=head;
     head->next=NULL;
     return newhead;
}
node* reversek(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* neptr;
    int count=0;
    while(curr!=NULL && k>count){
        neptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=neptr;
        count++;
    }
    if(neptr!=NULL){
    head->next=reversek(neptr,k);}
    return prev;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,1);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    display(head);
    node* newhead=reversei(head);
    // int k=2;
    // node* newhead=reversek(head,k);
    display(newhead);

    
}
