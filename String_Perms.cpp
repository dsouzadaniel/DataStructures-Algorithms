// String Permutations

#include<iostream>
#include<cstdlib>
using namespace std;
int x=0;
void swapchars(char* a, char* b){
    char temp;
    temp= *a;
    *a=*b;
    *b=temp;
    return;
}

void PermuteStrings(char* s, int current, int length){
    int j;
    if(current==length){
        x=x+1;
        cout<<x<<". "<<s<<endl;
        return;
    }

    for(j=current;j<length;j++){
        swapchars(&s[j],&s[current]);
        PermuteStrings(s,current+1,length);
        swapchars(&s[j],&s[current]);
    }
}


int main(){
    string s;
    cout<<" Hello. Welcome to the String Permutor 2000!"<<endl;
    cout<<" Enter your string!"<<endl;
    cin>>s;
    cout<<"Permutations are  : "<<endl;
    x=0;
    PermuteStrings(&s[0],0,s.length());
}
