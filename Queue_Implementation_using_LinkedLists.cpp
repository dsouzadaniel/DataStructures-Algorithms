//C++ Implementation of a Queue using Linked Lists with operations Enqueue, Dequeue and Traverse

#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
    int data;
    node* link;
};

class Queue{
private:
    node* rear;
    node* front;

public:
    Queue();
    void enqueue(int);
    void dequeue();
    void traverse();
};

Queue::Queue(){
    rear = NULL;
    front = NULL;
}

void Queue::enqueue(int value){
    node* temp = new node;
    temp->data = value;
    temp->link = NULL;
    if(front==NULL){
        front=temp;
    }
    else if(rear!=NULL){
        rear->link = temp;
    }
    rear = temp;
}

void Queue::dequeue(){
    node* temp = new node;
    if(front==NULL){
        cout<<"The Queue is Empty!"<<endl;
    }
    else{
        cout<<"Removed "<<front->data<<" from the queue!"<<endl;
        temp = front;
        front = front->link;
        delete temp;
    }
};

void Queue::traverse(){
    node* ref = new node;
    ref = front;
    if(front==NULL){
        cout<<"The Queue is Empty!"<<endl;
    }
    else{
        while(ref!=NULL){
            cout<<ref->data<<endl;
            ref=ref->link;
        }
        cout<<"\n"<<endl;
    }
}


int main(){
    int choice;
    Queue theline;
    while(1){
        cout<<"Welcome to a Linked List Implementation of a Queue"<<endl;
        cout<<"\n Select one of the Options : "<<endl;
        cout<<" 1.Enqueue\t 2.Dequeue\t 3.Traverse\t 4.Quit "<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                int entry;
                cout<<"\n Enter the number to be added to the queue : "<<endl;
                cin>>entry;
                theline.enqueue(entry);
                break;
            case 2:
                theline.dequeue();
                break;
            case 3:
                cout<<"Traversing the Queue : \n"<<endl;
                theline.traverse();
                break;
            case 4:
                exit(1);
            default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }
    }
}
