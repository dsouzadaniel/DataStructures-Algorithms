#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class list{
private:
    node* head, *tail;

    // Private Helper Functions
    void _traverseforward(node* curr){
        if(curr==NULL) return;
        cout<<curr->data<<"\t";
        _traverseforward(curr->next);
    }

    void _traversereverse(node *curr){
        if(curr==NULL){ return;}
        _traversereverse(curr->next);
        cout<<curr->data<<"\t";
    }

public:
    list(){
        head=NULL;
        tail=NULL;
    }

    void createnode(int value){
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;

        if(head==NULL){
            head= temp;
            tail = temp;
            temp = NULL;
        }
        else{
            tail->next = temp;
            tail = temp;
        }

    }

    void traverseforward(){
            _traverseforward(head);
    };

    void traversereverse(){
            _traversereverse(head);
    }

};

int main(){
    list x;
    x.createnode(25);
    x.createnode(35);
    x.createnode(45);
    x.createnode(55);
    x.createnode(65);
    cout<<"Forward Traversal is : \n"<<endl;
    x.traverseforward();
    cout<<"\n \n";
    cout<<"Reverse Traversal is : \n"<<endl;
    x.traversereverse();
    cout<<"\n \n";
    return 0;
}
