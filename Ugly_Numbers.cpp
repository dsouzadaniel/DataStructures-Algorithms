//This program calculates Ugly Numbers with a Dynamic Programming Approach

#include<iostream>
using namespace std;

int calcugly();

int curr2,curr3,curr5;
int i2=0,i3=0,i5=0;
int* ug;

int main(){
    int num;
    int newug;

    cout<<"Welcome to the Ugly Number Generator"<<endl;
    cin >> num;
    cout<<"Hello!"<<endl;
    ug = new int [num+1];
    ug[0] = 1;
    ug[1] = 2;
    curr2=2*ug[i2];
    curr3=3*ug[i3];
    curr5=5*ug[i5];
    for(int i=1; i<=num; i++){
        newug = calcugly();
        if(newug!=ug[i-1]) ug[i] = newug;
        else --i;
    }
    cout<<"\n The "<<num<<" ugly number is "<<ug[num-1]<<endl;
}

int calcugly(){
    int x;
    x = min(curr2,min(curr3,curr5));
    if(x==curr2){
        i2+=1;
        curr2=2*ug[i2];
    }
    else if (x==curr3){
        i3+=1;
        curr3=3*ug[i3];
    }
    else if (x==curr5){
        i5+=1;
        curr5=5*ug[i5];
    }
    return x;
}
