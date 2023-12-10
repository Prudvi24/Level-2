#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int solve(int n, int k){
	if(n==1){
		return 0;
	}
	int rr = solve(n-1,k);
	return (rr+k)%n;
}

int main(){
	int n,k;
	cin>>n>>k;
	int ans = solve(n,k);
	cout<<ans<<endl;
	return 0;
}