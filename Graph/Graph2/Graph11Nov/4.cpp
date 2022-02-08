//Coding Ninja using vector
//Coding Ninja using array
#include<bits/stdc++.h>
#define MAXN 102
using namespace std;
void initialize(vector<vector<bool>>&visited, int N, int M){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=false;
        }
    }
}
bool dfs(char Graph[][MAXN], char c[], int i, int j, int N, int M, vector<vector<bool>>&visited){
    if(Graph[i][j]=='A'){
        return true;
    }
    visited[i][j]=true;
    bool ans=false;
    
    if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1]){
        ans=ans||dfs(Graph, c+1, i-1, j-1, N, M, visited);
    }
    if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j]){
        ans=ans||dfs(Graph, c+1, i-1, j, N, M, visited);
    }
    if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1]){
        ans=ans||dfs(Graph, c+1, i-1, j+1, N, M, visited);
    }
    if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1]){
        ans=ans||dfs(Graph, c+1, i, j+1, N, M, visited);
    }
    if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1]){
        ans=ans||dfs(Graph, c+1, i+1, j+1, N, M, visited);
    }
    if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j]){
        ans=ans||dfs(Graph, c+1, i+1, j, N, M, visited);
    }
    if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1]){
        ans=ans||dfs(Graph, c+1, i+1, j-1, N, M, visited);
    }
    if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1]){
        ans=ans||dfs(Graph, c+1, i, j-1, N, M, visited);
    }
    return ans;   
}
int solve(char Graph[][MAXN],int N, int M){
    // Write your code here.
    
    char c[]="CODINGNINJA";
    vector<vector<bool>>visited(N,vector<bool>(M));
    //m=no of columns
    initialize(visited, N, M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int ans=false;
            if(Graph[i][j]=='C'){
                ans=dfs(Graph, c+1, i, j, N, M, visited);
                if(ans){
                    return 1; 
                }
                initialize(visited, N, M);
            }
    
        }
    }
    return 0;    
}
// #include<bits/stdc++.h>
// #define MAXN 102
// using namespace std;
// void initialize(bool **visited, int N, int M){
//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             visited[i][j]=false;
//         }
//     }
// }
// bool dfs(char Graph[][MAXN], char c[], int i, int j, int N, int M, bool **visited){
//     if(Graph[i][j]=='A'){
//         return true;
//     }
//     visited[i][j]=true;
//     bool ans=false;
    
//     if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1]){
//         ans=ans||dfs(Graph, c+1, i-1, j-1, N, M, visited);
//     }
//     if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j]){
//         ans=ans||dfs(Graph, c+1, i-1, j, N, M, visited);
//     }
//     if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1]){
//         ans=ans||dfs(Graph, c+1, i-1, j+1, N, M, visited);
//     }
//     if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1]){
//         ans=ans||dfs(Graph, c+1, i, j+1, N, M, visited);
//     }
//     if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1]){
//         ans=ans||dfs(Graph, c+1, i+1, j+1, N, M, visited);
//     }
//     if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j]){
//         ans=ans||dfs(Graph, c+1, i+1, j, N, M, visited);
//     }
//     if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1]){
//         ans=ans||dfs(Graph, c+1, i+1, j-1, N, M, visited);
//     }
//     if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1]){
//         ans=ans||dfs(Graph, c+1, i, j-1, N, M, visited);
//     }
//     return ans;   
// }
// int solve(char Graph[][MAXN],int N, int M){
// 	// Write your code here.
    
//     char c[]="CODINGNINJA";
//     bool **visited=new bool*[N];
//     for(int i=0;i<N;i++){
//         visited[i]=new bool[M];   
//     }
//     initialize(visited, N, M);
//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             int ans=false;
//             if(Graph[i][j]=='C'){
//                 ans=dfs(Graph, c+1, i, j, N, M, visited);
//                 if(ans){
//                     return 1; 
//                 }
//                 initialize(visited, N, M);
//             }
    
//         }
//     }
//     return 0;    
// }
