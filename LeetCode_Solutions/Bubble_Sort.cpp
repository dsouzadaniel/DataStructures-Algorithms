// C++ Implementation of Bubble Sort

#include<iostream>
using namespace std;

int main(){
    int a[10];
    int num = 10;
    cout<<"\nHello! Welcome to Bubble Sort"<<endl;
    cout<<"\n\n Enter "<<num<<" numbers\n"<<endl;
    for(int j = 0; j<num; j++){
        cin>>a[j];
    }
    cout<<"Your Original List : \n"<<endl;
    for(int j=0; j<num; j++){
        cout<<a[j]<<"\t";
    }

    for(int i = num-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"\n\n (Bubble)Sorted List is : \n"<<endl;
    for(int j=0; j<num; j++){
        cout<<a[j]<<"\t";
    }

}
