#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int>& v, int m){
	int lo = 0, hi = v.size()-1, mid;

	while(hi-lo > 1){
		mid = (hi+lo)/2;

		if(v[mid] <= m){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
	if(v[hi] > m) return hi;
	else if(v[lo] > m) return lo;
	else return -1;
}

int lower_bound(vector<int>& v, int m){
	int lo = 0, hi = v.size()-1, mid;

	while(hi-lo > 1){
		mid = (hi+lo)/2;

		if(v[mid] < m){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
	if(v[lo] >= m) return lo;
	else if(v[hi] >= m) return hi;
	else return -1;
}

int main(){
	int n; cin>>n;
	vector<int> v;

	for (int i = 0; i < n; ++i){
		int x; cin>>x;
		v.push_back(x);
	}
	int m; cin>>m;
	cout<<upper_bound(v,m)<<endl;
	cout<<lower_bound(v,m)<<endl;
}
