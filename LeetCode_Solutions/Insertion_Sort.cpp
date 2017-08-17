#include<iostream>
#include<cstdlib>

using namespace std;

void insertionsort(int[],int);
int main(){
    int a[10] = {0,0,0,0,0,0,1,0,-1,0};
    cout<<" Welcome to Insertion Sort"<<endl;
//    cout<<"Enter your array to be sorted"<<endl;
//    for(int i=0;i<10;i++)
//        cin>>a[i];
    cout<<"\n\nEntered Array is : "<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
    insertionsort(a,10);
    cout<<"\n\nEntered Array is : "<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
}

void insertionsort(int x[],int l){
    for(int j=1;j<l;j++){
        int temp = x[j];
        int k = j;
        while(temp<x[k-1] && k>0){
            x[k] = x[k-1];
            k = k-1;
        }
        x[k] = temp;
    }
    return;
}
