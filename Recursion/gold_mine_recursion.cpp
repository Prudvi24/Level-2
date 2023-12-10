#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<int>>&arr){
	for(auto vec : arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

void solution(int i, int j, vector<vector<int>>arr, 
	vector<vector<bool>>&checker, vector<int>&ans){
	if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || arr[i][j]==0 || checker[i][j]==1){
		return ;
	}
	checker[i][j] = 1;
	ans.push_back(arr[i][j]);
	solution(i+1, j, arr, checker,ans);
	solution(i-1, j, arr, checker,ans);
	solution(i, j+1, arr, checker,ans);
	solution(i, j-1, arr, checker,ans);
}

int main(){
	int n,m,d;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	vector<vector<bool>>checker(n,vector<bool>(m,0));
	int res = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0 && checker[i][j]==0){
				vector<int>ans;
				solution(i,j,arr,checker,ans);
				int se = 0;
				for(auto val : ans){
					se += val;
				}
				res = max(res,se);
			}
		}
	}
	cout<<res<<endl;
	return 0;
}