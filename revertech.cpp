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
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;

    
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}
//Reverse Linked list by 2 Methods
//Iterative
node* reverit(node* &head){
    node* pp=NULL;
    node* cp=head;
    node* np;
    while(cp!=NULL){
        np=cp->next;
        cp->next=pp;
        pp=cp;
        cp=np;
    }  
    return pp;
}
//Recursive
node *reverec(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node *newh=reverec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newh;
}
//Reverse K nodes
node* revk(node* &head,int k){
    int count=0;
    node* pp=NULL;
    node* cp=head;
    node* np;
    while(cp!=NULL && count<k){
        np=cp->next;
        cp->next=pp;
        pp=cp;
        cp=np;
        count++;
    }
    if(np!=NULL)
    head->next=revk(np,k);

    return pp;
}
bool search(node* &head,int key){
    node* temp=head;
    while(temp!=NULL){
    if(temp->data==key){
        return true;
    }temp=temp->next;}
    return false;
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
    insertAtHead(head,1);    
    insertAtHead(head,2);    
    insertAtHead(head,3);    
    insertAtHead(head,4);    
    insertAtHead(head,5);
    display(head);
    insertAtTail(head,6);    
    insertAtTail(head,7);    
    insertAtTail(head,8);    
    insertAtTail(head,9);    
    insertAtTail(head,10);
    display(head);
    cout<<search(head,70)<<endl;
    deletion(head,6);
    display(head);
    deleteAtHead(head);
    display(head);
    node* newh=reverit(head);
    display(newh); 
    node* newh2=reverec(newh);
    display(newh2); 
    int k=2;
    node* newh3=revk(newh2,k);
    display(newh3);
    return 0;    

}
