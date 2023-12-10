#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display(vector<vector<char>>&arr){
	for(auto vec : arr){
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}

bool checkPlaceVertically(vector<vector<char>>&arr, string word, int i, int j){
	if(i-1>=0 && arr[i-1][j]!='+'){
		return 0;
	}
	else if(i+word.length()<arr.size() && arr[i+word.length()][j]!='+'){
		return 0;
	}
	for(int k=0;k<word.length();k++){
		if(i+k >= arr.size()){
			return 0;
		}
		if(arr[i+k][j]=='-' || arr[i+k][j]==word[k]){
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}

bool checkPlaceHorizontally(vector<vector<char>>&arr, string word, int i, int j){
	if(j-1 >=0 && arr[i][j-1]!='+'){
		return 0;
	}
	else if(j+word.length()<arr.size() && arr[i][j+word.length()]!='+'){
		return 0;
	}
	for(int k=0;k<word.length();k++){
		if(j+k >= arr.size()){
			return 0;
		}
		if(arr[i][j+k]=='-'|| arr[i][j+k]==word[k]){
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}

vector<bool> placeVertically(vector<vector<char>>&arr, string word, int i, int j){
	vector<bool>placed(word.length(),0);
	for(int k=0;k<word.length();k++){
		if(arr[i+k][j]==word[k]){
			continue;
		}
		else{
			arr[i+k][j] = word[k];
			placed[k] = 1;
		}
	}
	return placed;
}

vector<bool> placeHorizontally(vector<vector<char>>&arr, string word, int i, int j){
	vector<bool>placed(word.length(),0);
	for(int k=0;k<word.length();k++){
		if(arr[i][j+k]==word[k]){
			continue;
		}
		else{
			arr[i][j+k] = word[k];
			placed[k] = 1;
		}
	}
	return placed;
}

void unPlaceVertically(vector<vector<char>>&arr, vector<bool>&placed, int i, int j){
	for(int k=0;k<placed.size();k++){
		if(placed[k]==1){
			arr[i+k][j] = '-';
		}
	}
}

void unPlaceHorizontally(vector<vector<char>>&arr, vector<bool>&placed, int i, int j){
	for(int k=0;k<placed.size();k++){
		if(placed[k]==1){
			arr[i][j+k] = '-';
		}
	}
}

void solution(vector<vector<char>>&arr, vector<string>&words, int idx){
	if(idx>=words.size()){
		display(arr);
		return ;
	}

	string word = words[idx];
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr.size();j++){
			if(arr[i][j]=='-' || arr[i][j]==word[0]){
				if(checkPlaceVertically(arr,word, i, j)==1){
					vector<bool>wordplaced = placeVertically(arr,word, i, j);
					solution(arr, words, idx+1);
					unPlaceVertically(arr,wordplaced,i,j);
				}
				if(checkPlaceHorizontally(arr,word,i,j)==1){
					vector<bool>wordplaced = placeHorizontally(arr,word, i, j);
					solution(arr, words, idx+1);
					unPlaceHorizontally(arr, wordplaced, i, j);
				}
			}
		}
	}
}

int main(){
	char ch;
	vector<vector<char>>arr;
	for(int i=0;i<10;i++){
		vector<char>tmp;
		for(int j=0;j<10;j++){
			cin>>ch;
			tmp.push_back(ch);
		}
		arr.push_back(tmp);
	}
	int n;
	cin>>n;
	vector<string>words(n,"");
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	solution(arr,words,0);
	return 0;
}