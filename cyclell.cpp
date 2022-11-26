#include<iostream>
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
void makecyc(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL){
    if(count==pos){
        startnode=temp;
    }
    temp=temp->next;
    count++;}
    temp->next=startnode;
}
bool detcyc(node* &head){
    node* f=head;
    node* s=head;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(f==s){
            return true;
        }
    }
    return false;
}
void rmcyc(node* &head){
    node* f=head;
    node* s=head;
    do{
        s=s->next;
        f=f->next->next;
    }while(s!=f);
    while(s->next!=f->next){
        s=s->next;
        f=f->next;
    }
    s->next=NULL;

}
void display(node* head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
int main(){
    node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    makecyc(head,3);
    cout<<detcyc(head)<<endl;
    rmcyc(head);
    cout<<detcyc(head);
    // display(head);
    // insertAtTail(head,5);
    // insertAtTail(head,6);
    // insertAtTail(head,7);
    // insertAtTail(head,8);
    // display(head);

}
