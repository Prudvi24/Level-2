#include<bits/stdc++.h>

using namespace std;

void right_most_set_bit_mask(int &n){
	int rmsb = n&-n;   // n & (-n)
	cout<<rmsb<<endl;   
}

int main(){
	int n;
	cin>>n;
	right_most_set_bit_mask(n);
	return 0;
}