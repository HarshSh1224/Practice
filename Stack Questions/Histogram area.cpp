#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> v = {2,4};
    int max_area = INT_MIN;
    vector<int> nse(v.size());
    vector<int> nse_left(v.size());
    stack<int> st;

    for (int i = 0; i < v.size(); ++i){
        
        while(!st.empty() && v[st.top()] > v[i]){
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        nse[st.top()] = v.size();
        st.pop();
    }

    for (int i = v.size()-1; i >= 0; --i){
        
        while(!st.empty() && v[st.top()] > v[i]){
            nse_left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        nse_left[st.top()] = -1;
        st.pop();
    }

    // for(auto el:nse_left) cout<<el<<" ";
    // cout<<endl;

    for (int i = 0; i < v.size(); ++i){

        int width = nse[i] - nse_left[i] - 1;

        if(nse[i] == -1) width = v.size() - i;
        int area = v[i]*width;

        max_area = max(area,max_area);
    }

    cout<<max_area<<endl;
}