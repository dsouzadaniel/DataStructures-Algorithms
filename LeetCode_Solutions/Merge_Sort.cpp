#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

void mergesort(int[],int,int,int);
void sort(int[],int,int,int);


int main(){
    int a[10]={55,44,3,2,11,18,77,4,5,1};
    cout<<" Welcome to Merge Sort"<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";


    //cout<<a<<" - "<<a[0]<<" = 10?"<<endl;

    mergesort(a,0,9,10);
    cout<<"\n\n After Sorting! : "<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
}

void mergesort(int x[],int l, int r, int length) {
    int mid = (floor)((r + l) / 2);
    if (l < r) {
        mergesort(x, l, mid, mid + 1 - l);
        mergesort(x, mid + 1, r, r - mid);

        sort(x, l, mid, r);
    }
}

void sort(int x[],int l, int m, int r){
    int n1= m+1-l;
    int n2 = r-m;
    int tempL[n1];
    int tempR[n2];

    for(int i=0;i<n1;i++)
        tempL[i]=x[l+i];
    for(int j=0;j<n2;j++)
        tempR[j] = x[m+1+j];

    int i = 0;
    int j= 0;
    int k = l;

    while(i<n1 && j<(n2)){

        if(tempL[i]<=tempR[j]){
            x[k] = tempL[i];
            i++;
        }
        else{
            x[k] = tempR[j];
            j++;
        }
        k++;
    }

    while(i<(n1)){
        x[k] = tempL[i];
        i++;
        k++;
    }
    while(j<(n2)){
        x[k] = tempR[j];
        j++;
        k++;
    }
    return;
}
