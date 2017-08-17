#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

void BSearch(int,int,int[],int);
int main(){
    int a[20] = {2,4,16,24,28,45,56,58,66,72,77,84,86,91,93,99,101,122,154,177};
    int x;
    cout<<"Welcome to Binary Search. Enter your term"<<endl;
    cin>>x;
    BSearch(0,20,a,x);
    return 0;
}

void BSearch(int start, int end, int a[], int num){
    for(int i=start;i<end;i++)
        cout<<a[i]<<"\t";
    cout<<"\n";
    int mid = (floor)((start+end)/2);
    cout<<start<<"+"<<end-1<<" by 2 = "<<mid<<endl;
    if(a[mid]==num){
        cout<<" Number is found!! @ index : "<<mid<<endl;
        return;
    }
    if(start >= end){
        cout<<" Element not found"<<endl;
        return;
    }
    if(a[mid]>num)
        BSearch(start,mid-1,a,num);
    else if(a[mid]<num)
        BSearch(mid+1,end,a,num);
    else{
        cout<<"Element not found"<<endl;
        return;
    }

}
