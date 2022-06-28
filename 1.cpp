#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        // Size based Unoion
        if(size[b] > size[a]) 
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){

    // input number of nodes and edges

    int n,k; cin>>n>>k;

    for (int i = 1; i <= n; ++i) make(i);

    for (int i = 0; i < k; ++i){
        int a,b; cin>>a>>b;
        Union(a,b);
    }

    // number of connected components  = number of nodes having themselves as their parent 

    int connected_ct = 0;

    for (int i = 1; i <= n; ++i){
        if(find(i) == i) connected_ct++;
    }

    cout<<connected_ct<<endl;
}
