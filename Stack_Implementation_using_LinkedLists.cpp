// C++ Implementation of a Stack using Linked Lists with operations Push,Pop,Traverse and Exit

#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
    int info;
    struct node* link;
}*top;

class stack_list{
public:
    node* push(node*, int);
    node* pop(node*);
    void traverse(node*);
    stack_list(){
        top = NULL;
    }
};


int main(){
    int choice;
    stack_list sl;
    while(1){
        cout<<"Welcome to a Stack Implementation with Linked Lists\n"<<endl;
        cout<<"Select an operation to perform : \n"<<endl;
        cout<<"1.Push \t 2.Pop \t 3.Traverse \t 4.Exit \t\n";
        cin>>choice;
        switch(choice){
            case 1:
                int value;
                cout<<"\n\nEnter the value to be pushed \n"<<endl;
                cin>>value;
                top = sl.push(top,value);
                break;

            case 2:
                top = sl.pop(top);
                break;

            case 3:
                cout<<"\nTraversing the List : "<<endl;
                sl.traverse(top);
                break;

            case 4:
                exit(1);
                break;

            default:
                cout<<"\nInvalid choice!"<<endl;
                break;
        }
    }
}




node* stack_list::push(node* top, int data){
    node* temp = new node;
    temp->info = data;
    temp->link = top;
    top = temp;
    return top;
}

node* stack_list::pop(node* top){
    node* temp = new node;
    temp = top;
    if(top==NULL){
        cout<<"\nStack is Empty!"<<endl;
    }
    else{
        cout<<"\nValue popped is : "<<temp->info<<endl;
        top=temp->link;
        delete temp;
    }
    return top;
}

void stack_list::traverse(node* top){
    node* temp = new node;
    temp = top;
    if(top==NULL){
        cout<<"\nStack is Empty!!\n"<<endl;
    }
    else{
        while(temp!=NULL){
            cout<<temp->info<<endl;
            temp=temp->link;
        }
    }
}
