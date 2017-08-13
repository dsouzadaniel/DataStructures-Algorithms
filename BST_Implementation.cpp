#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

struct node{
    int info;
    node* left;
    node* right;
}*root;

int height;
int theight;
class BST{
public:
    void insert(node*, node*);
    void display(node*,int);
    void find(int, node**, node**);
    void deletenode(int);
    void case_a(node*,node*);
    void case_b(node*,node*);
    void case_c(node*,node*);
    void pre_order(node*);
    void in_order(node*);
    void post_order(node*);
    void decreasing(node*);
    void height(node*, int*,int*);
    void pre_orderOS(node*);
    BST(){
        root = NULL;
    }
};

int main(){
    int choice,num;
    BST tree;
    node* temp;
    while(1) {
        cout<<"\n \n Welcome to a BST Implementation"<<endl;
        cout << " Enter your choice!" << endl;
        cout << "1. Insert \t 2. View \t 3. Delete \t 4. Pre_Order \t 5. Post_Order \t 6. In_Order \t 7. Decreasing \t 8. Height \t 15. Exit \t 99.Old_SCHOOL PreOrder \t" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                temp = new node;
                cout << "Enter the value to be inserted" << endl;
                cin >> temp->info;
                tree.insert(root, temp);
                break;
            case 2:
                cout << "The Constructed Binary Search Tree is :\n \n " << endl;
                tree.display(root, 1);
                break;
            case 3:
                cout<<"Enter the element to be deleted"<<endl;
                cin>>num;
                tree.deletenode(num);
                break;
            case 4:
                cout<<"\n The Pre-Order Traversal of the BST is : \n \t "<<endl;
                tree.pre_order(root);
                break;
            case 5:
                cout<<"\n The Post-Order Traversal of the BST is : \n \t "<<endl;
                tree.post_order(root);
                break;
            case 6:
                cout<<"\n The In-Order Traversal of the BST is : \n \t "<<endl;
                tree.in_order(root);
                break;
            case 7:
                cout<<" The nodes in \n \t"<<endl;
                cout<<" Increasing Order\n"<<endl;
                tree.in_order(root);
                cout<<" \n \t Decreasing Order\n"<<endl;
                tree.decreasing(root);
                break;
            case 8:
                cout<<" The Height of the Tree is :"<<endl;
                height = 0;
                theight = 0;
                tree.height(root,&height,&theight);
                cout<<height<<endl;
                break;
            case 15:
                cout << "Exiting Program" << endl;
                exit(1);
            case 99:
                cout<<"Old School PreOrder is "<<endl;
                tree.pre_orderOS(root);
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }
}

void BST::insert(node *tree, node *val) {
    if(root==NULL){
        root = new node;
        root->info = val->info;
        root->left =NULL;
        root->right = NULL;
        cout<<"Root Added!"<<endl;
        return;
    }
    if (tree->info == val->info){
        cout<<" The value already exits"<<endl;
        return;
    }
    if(tree->info>val->info){
        if(tree->left!=NULL){
            insert(tree->left,val);
        }
        else{
            tree->left = new node;
            (tree->left)->info = val->info;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            return;
        }
    }
    else {
        if(tree->right!=NULL){
            insert(tree->right,val);
        }
        else{
            tree->right = new node;
            (tree->right)->info = val->info;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            return;
        }
    }
}

void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

void BST::find(int value,node** par,node** loc) {
    node *ptr, *ptrsave;
    if (root == NULL) {
        cout << " No List Exists" << endl;
        return;
    } else if (value == root->info) {
        *par = NULL;
        *loc = root;
        return;
    }
    else{
        ptrsave = root;
        if(root->info > value){
            ptr = root->left;
        }
        else{
            ptr = root->right;
        }
        while(ptr!=NULL){
            if(ptr->info == value){
                *loc = ptr;
                *par = ptrsave;
                return;
            }
            ptrsave = ptr;
            if(ptr->info > value){
                ptr=ptr->left;
            }
            else{
                ptr=ptr->right;
            }
        }
        *loc = NULL;
        *par = NULL;
        return;
    }
}



void BST::deletenode(int value){
    node *location, *parent;
    if(root==NULL){
        cout<<"No List Exists"<<endl;
        return;
    }
    else{
        find(value,&parent,&location);

        if(location==NULL){
            cout<<" Element not present in the LIST"<<endl;
            return;
        }

        if(location->left==NULL && location->right==NULL){
            case_a(parent,location);
        }
        else if(location->left!=NULL &&  location->right == NULL){
            case_b(parent,location);
        }
        else if(location->left==NULL && location->right!=NULL){
            case_b(parent,location);
        }
        else{
            case_c(parent,location);
        }
    }
    free(location);
    cout<<"\n \t Node Successfully Deleted!"<<endl;
    return;
}

// This is when both the children to the node(to be deleted) are NULL
void BST::case_a(node* par, node*loc){
    if(par==NULL){
        root = NULL;
        return;
    }
    else{
        if(par->left == loc){
            par->left = NULL;
        }
        else{
            par->right = NULL;
        }
        return;
    }
}

// This is when one of the children is NULL
void BST::case_b(node* par, node* loc){
    node* child;
    if(loc->left!=NULL){
        child = loc->left;
    }
    else{
        child = loc->right;
    }
    if(par==NULL){
        root=child;
        return;
    }
    if(par->left == loc){
        par->left = child;
    }
    else{
        par->right = child;
    }
    return;
}

// This is when both the children are non-null
void BST::case_c(node* par, node* loc){
    node *ptr,*ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while(ptr->left!=NULL){
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if(suc->right){
        case_b(parsuc,suc);
    }
    else{
        case_a(parsuc,suc);
    }
    if(par==NULL){
        root = suc;
        return;
    }
    else{
        if(par->left==loc){
            par->left = suc;
        }
        else{
            par->right = suc;
        }
    }
    suc->left = loc->left;
    suc->right = loc->right;
    return;
}

void BST::pre_order(node *ptr) {
    if(root==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if(ptr!=NULL){
        cout<<ptr->info<<"  ";
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
    return;
}

void BST::in_order(node *ptr) {
    if(root==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if(ptr!=NULL){
        in_order(ptr->left);
        cout<<ptr->info<<"  ";
        in_order(ptr->right);
    }
    return;
}

void BST::post_order(node *ptr) {
    if(root==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if(ptr!=NULL){
        post_order(ptr->left);
        post_order(ptr->right);
        cout<<ptr->info<<"  ";
    }
    return;
}

void BST::decreasing(node *ptr) {
    if(root==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(ptr!=NULL){
        decreasing(ptr->right);
        cout<<ptr->info<<"   ";
        decreasing(ptr->left);
    }
    return;
}

void BST::height(node* ptr, int* val, int* temp){
    if(root==NULL){
        cout<<"No tree exists"<<endl;
        return;
    }
    if(ptr!=NULL){
        *temp=*temp+1;
        height(ptr->left,val,temp);
        height(ptr->right,val,temp);
        *temp=*temp-1;
    }
    else{
        if((*val) < (*temp)){
            (*val)=(*temp);
        }
        return;
    }
}

void BST::pre_orderOS(node* ptr) {
    stack<node*> x;
    x.push(ptr);
    while(x.size()){
        node* curr = x.top();
        x.pop();
        cout<<curr->info<<"\t";
        if(curr->right) x.push(curr->right);
        if(curr->left) x.push(curr->left);
    }

}
