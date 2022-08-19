#include<bits/stdc++.h>
using namespace std;

bool isop(char x){
    return x=='+' || x=='/' || x=='*' || x=='-';
}

int main(){
    
    string s = "(b+((c-d))+c)";

    stack<char> st;
    int prev,previ; 
    for (int i = 0; i < s.size(); ++i){
        
        if(!isalpha(s[i]) && s[i]!=')'){
            st.push(s[i]);
            // cout<<s[i]<<endl;
        }

        if(s[i] == ')') {

            // cout<<"isop : "<<st.top()<<endl;
            bool t = 0;
            while(!st.empty() && isop(st.top())){
                // cout<<"Pop : "<<st.top();
                st.pop();
                t = 1;
            }
            if(t) st.pop();

        }
    }

    // cout<<1<<endl; return 0;
    // P1 : {
    //     cout<<0<<endl;
    // }

    if(st.empty()) cout<<0;
    else cout<<1;


}