#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void dfs(int n, int i){
	if(i>n){
		return ;
	}
	else{
		cout<<i<<endl;
	}
	for(int j=0;j<=9;j++){
		dfs(n,10*i+j);
	}
}

void solution(int n){
	for(int i=1;i<=9;i++){
		dfs(n,i);
	}
}

int main(){
	int n;
	cin>>n;
	solution(n);
	return 0;
}