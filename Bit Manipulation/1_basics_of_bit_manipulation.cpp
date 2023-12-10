#include<bits/stdc++.h>

using namespace std;

void bit_manipulation(int &n, int &i, int &j, int &k, int &m){
	long onmask = (1<<i);
	long offmask = ~(1<<j);
	long toggle_mask = (1<<k);
	long check_mask = ~(1<<m);

	cout<<(n|onmask)<<endl;
	cout<<(n&offmask)<<endl;
	cout<<(n^toggle_mask)<<endl;
	if(n&check_mask){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
}

int main(){
	int n,i,j,k,m;
	cin>>n>>i>>j>>k>>m;
	bit_manipulation(n,i,j,k,m);
	return 0;
}