// C++ code to find whether a string is a Palindrome using Recursion

#include<iostream>
using namespace std;

int palin(char*, int, int);
char *word;

int main(){
    word = new char [11];
    cout<<"Enter your string! ;) "<<endl;
    cin>>word;
    int len = strlen(word);
    int dec = palin(word,0,len-1);
    if(dec) cout<<"\n \n Yes! It's a Palindrome!"<<endl;
    else cout<<"Nope! No Palindrome here"<<endl;

    return 0;
}

int palin(char *text, int start, int end){
    if((start>end)) return 1;
    if(text[start]==text[end]) palin(text,start+1,end-1);
    else return 0;
}
