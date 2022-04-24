#include<bits/stdc++.h>
using namespace std;

void printbinary(int a){
	for(int i = 10; i>=0; i--){
		cout<< ((a>>i)&1);
	}
	cout<<endl;
} 

int main(){
	int a = 13;
	printbinary(a);

	// Check if a bit is set

	int i = 0;

	//printbinary(a &  (1 << i));

	if((a &  (1 << i))!= 0)
		cout<<i<<"th Bit is set"<<endl;
	else
		cout<<i<<"th Bit is unset"<<endl;

	// Set a bit

	printbinary(a | (1<<4));
	cout<<(a | (1<<1))<<endl;
	
	// Unset a bit

	printbinary(a & ~(1<<i));

	// toggle a bit

	printbinary(a ^ (1<<i));

	// count all setbits

	int ct = 0;

	for(i = 31; i>=0; i--){
		if((a>>i) & 1){
			ct++;
		} 
	}
	cout<<ct<<endl;
	cout<<__builtin_popcount(a)<<endl;
	cout<<__builtin_popcountll(a)<<endl;
}
