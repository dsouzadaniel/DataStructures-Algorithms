// C++ Implementation of Selection Sort

#include<iostream>
using namespace std;

int main(){
    int a[10];
    int num = 10;
    cout<<"\nHello! Welcome to Selection Sort"<<endl;
    cout<<"\n\n Enter "<<num<<" numbers\n"<<endl;
    for(int j = 0; j<num; j++){
        cin>>a[j];
    }
    cout<<"Your Original List : \n"<<endl;
    for(int j=0; j<num; j++){
        cout<<a[j]<<"\t";
    }

    for(int i = 0; i<num-1; i++){
        int smallest_index = i;
        for(int j=i; j<num; j++){
            if(a[j]<a[smallest_index]){
                smallest_index = j;
            }
        }
        int temp = a[smallest_index];
        a[smallest_index] = a[i];
        a[i] = temp;
    }

    cout<<"\n\n (Selection)Sorted List is : \n"<<endl;
    for(int j=0; j<num; j++){
        cout<<a[j]<<"\t";
    }

}
