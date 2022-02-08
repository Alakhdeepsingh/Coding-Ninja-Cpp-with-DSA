//Kruskals Algorithm using vector
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge e1,Edge e2){
    return e1.weight < e2.weight;
}
int findParent(int v,vector<int>&parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}
void kruskals(vector<Edge>&input, int n,int E){
    //Sort the input Array - ascending order based on weights
    sort(input.begin(), input.end(),compare);
    vector<Edge>output(n-1);
    vector<int>parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    int count =0;
    int i=0;
    while(count!=n-1){
        Edge currentEdge=input[i];
        int sourceParent=findParent(currentEdge.source,parent);
        int destinationParent=findParent(currentEdge.destination,parent);
    if(sourceParent != destinationParent){
        output[count]=currentEdge;
        count++;
        parent[sourceParent]=destinationParent;
    }
    i++;
}

for(int i=0; i<n-1; i++){
    if(output[i].source<output[i].destination){
    cout<<output[i].source<<" "<<output[i].destination<<output[i].weight<<endl;
    }
    else{
        cout<<output[i].destination<<" "<<output[i].source<<endl<<" "<<output[i].weight<<endl;
    }
}
}
int main()
{
    int n,E;
    cin>>n>>E;
    vector<Edge>input(E);
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
            input[i].source=s;
            input[i].destination=d;
            input[i].weight=w;
        }
        kruskals(input, n, E);
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// class Edge{
//     public:
//     int source;
//     int destination;
//     int weight;
// };
// bool compare(Edge e1,Edge e2){
//     return e1.weight < e2.weight;
// }
// int findParent(int v,int* parent){
//     if(parent[v]==v){
//         return v;
//     }
//     return findParent(parent[v],parent);
// }
// void kruskals(Edge *input, int n,int E){
//     //Sort the input Array - ascending order based on weights
//     sort(input, input+E,compare);
//     Edge *output = new Edge[n-1];
//     int *parent=new int[n];
//     for(int i=0;i<n;i++){
//         parent[i]=i;
//     }
    
//     int count =0;
//     int i=0;
//     while(count!=n-1){
//         Edge currentEdge=input[i];
//         int sourceParent=findParent(currentEdge.source,parent);
//         int destinationParent=findParent(currentEdge.destination,parent);
//     if(sourceParent != destinationParent){
//         output[count]=currentEdge;
//         count++;
//         parent[sourceParent]=destinationParent;
//     }
//     i++;
// }

// for(int i=0; i<n-1; i++){
//     if(output[i].source<output[i].destination){
//     cout<<output[i].source<<" "<<output[i].destination<<output[i].weight<<endl;
//     }
//     else{
//         cout<<output[i].destination<<" "<<output[i].source<<endl<<" "<<output[i].weight<<endl;
//     }
// }
// }
// int main()
// {
//     int n,E;
//     cin>>n>>E;
//     // Edge *input = new Edge[E];
//     vector<vector<int>>edges(n,vector<int>(n));
//     // vector<int>edge;    
// 	for(int i=0;i<E;i++){
// 		int s,d,w;
//         cin>>s>>d>>w;
//             input[i].source=s;
//             input[i].destination=d;
//             input[i].weight=w;
//         }
//         kruskals(Edge, n, E);
//     return 0;
// }