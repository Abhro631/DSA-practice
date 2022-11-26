#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void del(node* &head,int pos){
    node* temp=head;
    int count=1;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
   
    
    while(temp!=NULL && count!=pos){
        temp=temp->next;
    count++;}
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;

}
void insertAtHead(node* &head, int val){
     node* n=new node(val);
     n->next=head;
     if(head!=NULL){
     head->prev=n; }
     head=n;
}
void insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
     insertAtHead(head,val);
     return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;

}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   cout<<"NULL"<<endl; 
}
 int len(node* head)
    {
        int l=0;
        node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;

    }
    void intersect(node* &head1,node* &head2,int pos ){
        node* temp1=head1;
        pos--;
        while(pos--){
            temp1=temp1->next;
        }
        node* temp2=head2;
        while(temp2->next!=NULL){
            temp2=temp2->next;

        }
        temp2->next=temp1;
    }
    int intersection(node* &head1,node* &head2){
        int l1=len(head1);
        int l2=len(head2);
         int d=0;
        node* p1;
        node* p2;
        if(l1>l2){
            d=l1-l2;
            p1=head1;
            p2=head2;
        }
        else{
            d=l2-l1;
            p1=head2;
            p2=head1;
        }
        while(d){
           
             p1=p1->next;
            if(p1==NULL){
                return -1;
            }
             d--;
        }
        while(p1!=NULL && p2!=NULL){
            if(p1==p2){
                return p1->data;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return -1;
    }
    int merge(node* &head1,node* &head2){
        node* p1=head1;
        node* p2=head2;
        node* dum=new node(-1);
        node* p3=dum;
        while(p1!=NULL && p2!=NULL){
            if(p1->data<p2->data){
                p3->next=p1;
                p1=p1->next;
            }
            else{
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;}
            while(p1!=NULL){
                 p3->next=p1;
                p1=p1->next;
                p3=p3->next;
            }
            while(p2!=NULL){
                 p3->next=p2;
                p2=p2->next;
                p3=p3->next;
            }
            return dum->next;
        }
    
node* append(node* head,int k){
        node* newhead;
        node* newtail;
        node* tail=head;
        int l=len(head);
        k=k%l;
        int count=1;
        while(tail->next!=NULL){
            if(count==l-k){
            newtail=tail;
            }
            if(count==l-k+1){
                newhead=tail;
            }
            tail=tail->next;
            count++;
        }
        newtail->next=NULL;
        tail->next=head;
        return newhead;
    }
int main(){
    node* head1=NULL;
    node* head2=NULL;
    // insertAtTail(head1,1);
    // insertAtTail(head1,2);
    // insertAtTail(head1,3);
    // insertAtTail(head1,4);
    // insertAtTail(head1,5);
    // insertAtTail(head1,6);
    // insertAtTail(head2,9);
    // insertAtTail(head2,10);
    // intersect(head1,head2,3);
    // // display(head);
    // display(head1);
    // display(head2);
    // cout<<intersection(head1,head2)<<endl;
    // del(head,1);
    // int arr[]={1,2,3,4,5,6};
    // for(int i=0;i<6;i++){
    //   insertAtTail(head,arr[i]);
    // }
    // display(head);
    //  node* newhead=append(head,3);
    //  display(newhead);
}
