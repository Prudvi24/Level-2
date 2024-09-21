#include <bits/stdc++.h>

using namespace std;

bool long_pressed_name(string &name, string &typed){
	int i=0, j=0;
	if(typed.length() < name.length()){
		return false;
	}
	while(i<name.length() && j<typed.length()){
		if(name[i]==typed[j]){
			i++;
			j++;
		}
		else{
			if(i==0){
				return false;
			}
			if(name[i-1]==typed[j]){
				j++;
			}
			else{
				return false;
			}
		}
	}
	if(i<name.length()){
		return false;
	}
	while(j<typed.length()){
		if(name[i-1]!=typed[j]){
			return false;
		}
		j++;
	}
	return true;
}

int main(){
	string name, typed;
	cin>>name>>typed;
	bool ans = long_pressed_name(name, typed);
	if(ans){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}