#include<bits/stdc++.h>
using namespace std;

void display(stack<pair<int,int>> st){

    if(st.empty()) return;

    vector<pair<int,int>> v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    for(auto el : v) cout<<el.first<<","<<el.second<<" ";
    cout<<endl;
}

int main(){

    int n; cin>>n;
    vector<int> price(n);

    for (int i = 0; i < n; ++i)
        cin >> price[i];

    // int n = price.size();
    vector<int> span(n);

    stack<pair<int,int>> st;

    for (int i = 0; i < n; ++i){

        
        int days = 0;

        while(!st.empty() && price[st.top().first] <= price[i]){
            // cout<<st.top().first<<endl;
            days += st.top().second + 1;
            st.pop();
        }

        st.push({i,days});
        span[i] = days+1;
        if(i == 77 ) display(st);
    }

    while(!st.empty()){
        // cout<<price[st.top().first]<<endl;
        span[st.top().first] = st.top().second + 1;
        st.pop();
    }

    for(auto el : span) cout<<el<<" ";
    cout<<endl;
}