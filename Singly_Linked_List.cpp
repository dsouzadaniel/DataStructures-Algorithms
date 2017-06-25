// C++ Implementation of a Singly Linked List with creation,deletion and display operations.

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class list{
private:
    node *head,*tail;
public:
    list(){
        head = NULL;
        tail = NULL;
    }


    void createnode(int value){
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    void displaynode(){
        node *temp = new node;
        temp = head;
        while(temp!=NULL){
            cout<<"Value = "<<temp->data<<"\n"<<endl;
            temp = temp->next;
        }
    }

    void createnodefr(int value){
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void creatnodemid(int pos, int value){
        node *temp = new node;
        node *curr = new node;
        node *prev = new node;
        temp->data = value;
        curr = head;
        for ( int i = 1; i<pos; i++) {
            prev = curr;
            curr = curr->next;
        }
         prev->next = temp;
        temp->next = curr;

    }
    void deletenode() {
        node *curr = new node;
        node *prev = new node;
        curr = head;
        while(curr->next!=NULL){
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = NULL;
        delete curr;
    }

    void deletenodefr(){
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void deletenodemid(int pos){
        node *temp = new node;
        node *prev = new node;
        node *curr = new node;

        curr = head;
        for(int i=1; i<pos; i++){
            prev = curr;
            curr = curr->next;
        }
        temp = curr;
        curr=curr->next;
        prev->next = curr;
        delete temp;
    }

};

int main(){
    list a;
    a.createnode(22);       // 22
    a.createnode(88);       // 22 88
    a.createnodefr(24);     // 24 22 88
    a.creatnodemid(2,55);   // 24 55 22 88
    a.deletenodefr();       // 55 22 88
    a.creatnodemid(3,66);   // 55 22 66 88
    a.deletenode();         // 55 22 66
    a.deletenodemid(3);     // 55 22
    a.displaynode();        // --> 55 22
    return 0;
}
