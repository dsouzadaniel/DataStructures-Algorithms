// C++ Code to give you all permutations of a string using backtracking(recursion) technique

#include<iostream>
#include<string>
using namespace std;

void perm(char*, int, int);
void swap(char*, char*);

char *q;

void swap(char* x, char* y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void perm(char* list, int start, int end){
    if(start==end){
        cout<<list<<"\n";
    }
    for(int i=start; i<=end; i++){
        swap((list+start),(list+i));
        perm(list, start+1, end);
        swap((list+start),(list+i));
    }
}


int main(){
    q = new char [10];
    cout<<"Enter the String"<<endl;
    cin>>q;
    int len = strlen(q);
    perm(q,0,len-1);
    return 0;
}
