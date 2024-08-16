#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    vector<vector<int>>adjMatrix(n,vector(n,0));

    int e;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;

     bool directed = 0;
    cout<<"Enter edges : ";
    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjMatrix[u-1][v-1] = 1;
        if(!directed){
            adjMatrix[v-1][u-1] = 1;
        }
    }

    cout<<"Printing the Graph"<<endl;
   
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;

}