#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solution(vector<vector<bool>>board, vector<bool>cols, vector<bool>diag,
	vector<bool>rdiag, int row, string ans){

	if(row>=board.size()){
		cout<<ans<<" ."<<endl;
	}

    /* The most important step is to place and bound the daig and rdaig array so that there will be no conflict between the queen*/

	for(int i=0;i<board.size();i++){
		if(cols[i]==0 && diag[row+i]==0 && rdiag[row-i+board.size()-1]==0){
			cols[i]=1;
			diag[row+i]=1;
			rdiag[row-i+board.size()-1]=1;
			solution(board, cols, diag, rdiag, row+1, ans+to_string(row)+"-"+to_string(i)+", ");
			cols[i]=0;
			diag[row+i]=0;
			rdiag[row-i+board.size()-1]=0;
		}
	}

}

int main(){
	int n;
	cin>>n;
	vector<vector<bool>>board(n,vector<bool>(n,0));
	vector<bool>col(n,0);
	vector<bool>diag(2*n-1,0);
	vector<bool>rdiag(2*n-1,0);
	solution(board,col,diag,rdiag,0,"");
	return 0;
}