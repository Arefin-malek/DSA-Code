#include <bits/stdc++.h>
using namespace std;
class node{
    public :
        int data;
        node* next;
    
    node(int data){
        this->data = data;
        this -> next = NULL;
    }
    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void InsertatHead(node* &head , int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp ;
}
void Insertattail(node* &tail , int d){
    node* temp = new node(d);
    tail->next = temp ;
    tail = tail -> next;
}
void Insertatpos(int pos , int d , node* &head , node* &tail){
    // inserting at head;
    if(pos ==1 ){
        InsertatHead(head , d);
        return;
    }
    node*  temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    // insertion at tail if its the last node;
    if(temp -> next ==NULL){
        Insertattail(tail , d);
        return;
    }
    node* n1 = new node(d);
    n1->next = temp -> next; 
    temp->next = n1;

}
void deletenode(node* &head , int pos ){
    if( pos ==1 ){
        node* temp = head;
        head = head -> next;

        temp -> next = NULL;
        delete temp ;
    }

    else{
        node* curr = head;
        node* prev = NULL;

        int cnt =1 ;
        while(cnt <= pos ){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev->next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}
void print(node*&head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}
int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    InsertatHead(head , 50);
    InsertatHead(head , 40);
    InsertatHead(head , 30);
    InsertatHead(head , 20);
    InsertatHead(head , 10);
   // print(head);
    Insertattail(tail , 30);
    print(head);

    cout << endl;

    Insertatpos(3,40 ,head , tail);
    print(head);

    deletenode(head , 1);
    print(head);
    cout << endl <<head -> data << " " << tail -> data << endl;
}