#include<bits/stdc++.h>

using namespace std;

void solution(string str,int i,int count, string rems){
	if(i>=str.length()){
		if(count!=0){
			cout<<rems+to_string(count)<<endl;
		}
		else{
			cout<<rems<<endl;
		}
		return ;
	}
	if(count!=0){
		solution(str,i+1,0,rems+to_string(count)+str[i]);
	}
	else{
		solution(str,i+1,0,rems+str[i]);
	}
	solution(str,i+1,count+1,rems);
}

int main(){
	string str;
	cin>>str;
	solution(str,0,0,"");
	return 0;
}