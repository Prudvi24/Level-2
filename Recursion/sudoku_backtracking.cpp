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

bool isValid(vector<vector<int>>&arr, int i, int j, int val){
	//check col vector
	for(int k=0;k<arr.size();k++){
		if(arr[k][j]==val){
			return 0;
		}
	}
	//check row vector
	for(int k=0;k<arr[0].size();k++){
		if(arr[i][k]==val){
			return 0;
		}
	}
	//check in the 3*3 submatrix
	int si = i/3 * 3;
	int sj = j/3 * 3;
	for(int a=0; a<3; a++){
		for(int b=0;b<3;b++){
			if(arr[si+a][sj+b]==val){
				return 0;
			}
		}
	}
	return 1;
}

void solution(int i, int j, vector<vector<int>>&arr){
	if(i==arr.size()){
		display(arr);
		return ;
	}
	int ni = 0;
	int nj = 0;

	if(j==arr[0].size()-1){
		ni = i+1;
		nj = 0;
	}
	else{
		ni = i;
		nj = j+1;
	}
	//cout<<"("<<i<<","<<j<<")"<<endl;
	if(arr[i][j]!=0){
		solution(ni, nj, arr);
	}
	else{
		for(int pos=1;pos<=9;pos++){
			if(isValid(arr,i,j,pos)==1){
				arr[i][j]=pos;
				//cout<<"("<<i<<","<<j<<") --> "<<pos<<endl;
				solution(ni, nj, arr);
				arr[i][j]=0;
			}
		}
	}

}

int main(){
	int n = 9;
	vector<vector<int>>arr(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	solution(0,0,arr);
	return 0;
}
/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/