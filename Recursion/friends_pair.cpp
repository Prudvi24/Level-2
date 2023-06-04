#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solution(int i, int n, vector<bool>used, string res){
	if(i>=n+1){
		cout<<res<<endl;
		return ;
	}
	if(used[i]==1){
		solution(i+1, n, used, res);
	}
	else{
		used[i]=1;
		solution(i+1, n, used,res+"("+to_string(i)+")");
		for(int j=i+1;j<=n;j++){
			if(used[j]==0){
				used[j]=1;
				solution(i+1,n,used,res+"("+to_string(i)+","+to_string(j)+")");
				used[j]=0;
			}
		}
		used[i]=0;		
	}
}
int main(){
	int n;
	cin>>n;
	vector<bool>used(n+1,0);
	solution(1,n,used,"");
	return 0;
}