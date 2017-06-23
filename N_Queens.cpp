#include<iostream>
using namespace std;

int n;
int *q;
int **t;

void search(int);
void dangertile(int,int,int);
void printsoln();

int main() {
    cout<<"Welcome to the N-Queens Solver"<<endl;
    cout<<"\n\n";
    cout<<"Enter the size of the grid. Ex : 4 for a 4X4 Grid"<<endl;
    cin >>n;
    q = new int[n];
    q[n] = -1;
    t = new int* [n];
    for (int o=0; o<n; o++){
        t[o] = new int [n];
        for (int p =0; p<n; p++) t[o][p] = 0;
    }
    search(0);
    delete [] q;
    for (int o =0; o<n; o++) delete [] t[o];
    delete [] t;
    return 0;
}

void search(int row){
    if (row==n) printsoln();
    else{
        for(q[row]=0; q[row]<n; q[row]++){
            if(t[row][q[row]]==0){
                dangertile(row,q[row],1);
                search(row+1);
                dangertile(row, q[row],-1);
            }
        }
    }
}

void dangertile(int row, int col, int change){
    for(int j =row+1; j<n; j++){
        t[j][col] += change;
        if((col-(j-row))>=0) t[j][col-(j-row)] += change;
        if((col+(j-row))<n) t[j][col+(j-row)] += change;
    }
}

void printsoln(){
        cout<<"\n Possible N-Queens Solution: \n";
        for (int i =0; i<n; i++) {
            for ( int k = 0; k<n; k++) cout<<" -- ";
            cout<<"\n";
            for (int j = 0; j<=n; j++){
                cout<<"|";
                if(q[i]==j) cout<<" Q ";
                else cout<<"   ";
                }
            cout<<"\n";
            }
         for ( int k = 0; k<n; k++) cout<<"  --";
            cout<<"\n \n";
        }
