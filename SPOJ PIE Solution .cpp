#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int arr[N];
int n,f;
double eps = 1e-4;
double pi = 2*asin(1.0);

bool isSufficient(double volume){
	int sum = 0;
	for (int i = 0; i < n; ++i){
		int hig = (pi * arr[i] * arr[i])/volume;
		sum+=hig;
	}
	return sum>=f+1;
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>f;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}

		sort(arr,arr+n);
		int max_el = arr[n-1];
		double lo=0,hi= pi*max_el*max_el,mid;
		while(hi-lo > eps){
			mid = (hi + lo)/2;
			//cout<<mid<<" "<<endl;
			if(isSufficient(mid)){
				lo = mid;
			}else{
				hi = mid;
			}
		}
		//cout<<endl;
		if(isSufficient(hi))
			cout<<fixed<<setprecision(4)<<hi<<endl;
		else
			cout<<fixed<<setprecision(4)<<lo<<endl;
	}
}
