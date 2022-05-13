#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

vector<string> subsets(string s){
	vector<string> sbsts;
	for (int masks = 0; masks < (1<<s.size()); ++masks){
		string temp;
		temp.clear();
		for(int i=0; i<s.size(); i++){
			if((masks>>i)&1) temp.push_back(s[i]); 
		}
		sbsts.push_back(temp);
	}
	return sbsts;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string strings[n];
		for (int i = 0; i < n; ++i){
			cin>>strings[i];
		}

		unordered_map<string,int> hsh;

		for(auto str:strings){
			set<char> distinct_vowels;
			for(auto ch:str){
				if(isVowel(ch)) distinct_vowels.insert(ch);
			}
			string dct_vowels;
			for(auto ch:distinct_vowels){
				dct_vowels.push_back(ch);
			}
			vector<string> all_subsets = subsets(dct_vowels);
			for(auto str:all_subsets){
				if(str.size()) hsh[str]++;
			}
		}

		long long total = 0;

		for(auto &pr:hsh){
			if(pr.second<3) continue;
			long long ct = pr.second;
			long long ways = (ct*(ct-1)*(ct-2)) / 6;
			if(pr.first.size() %2 ==0) total-=ways;
			else total += ways;
		}
		cout<<total<<endl;
	}
}
