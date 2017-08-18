#include<iostream>
#include<cstdlib>

using namespace std;

void swap(int*,int*);

int sort(int[],int,int);
void quicksort(int[],int,int);

int main(){
    int a[10] = {45,33,22,1,4,2,55,4,1,7};
    cout<<" \n \nBefore Sort : "<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
    quicksort(a,0,9);
    cout<<" \n \nAfter Sort : "<<endl;
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
}

void quicksort(int x[],int low,int high){
    if(low<high){
        int p = sort(x,low,high);
        quicksort(x,low,p-1);
        quicksort(x,p+1,high);
    }
}

void swap(int* a, int* b){
    int temp;
    temp =*a;
    *a=*b;
    *b=temp;
}

int sort(int x[],int low, int high){
    int i = low -1;
    int pivot = x[high];
    for(int j = low;j<=high-1;j++){
        if(x[j]<=pivot){
            i++;
            swap(&x[i],&x[j]);
        }
    }
    swap(&x[i+1],&x[high]);
    return (i+1);
}
