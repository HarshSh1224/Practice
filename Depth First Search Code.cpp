#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){

    /*Take action on vertex after entering the vertex*/

    vis[vertex] = true;
    for(auto child: graph[vertex]){
    
    /*Take action on child before entering the child node*/

        if(vis[child]) continue;
        dfs(child);

    /*Take action on child after exiting the node*/

    }

    /*Take action on vertex before exiting the vertex*/
}

int main(){
    int n,m=9;
    cin>>n>>m;

    for (int i = 0; i < m; ++i){
        int v1,v2; cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);

}
