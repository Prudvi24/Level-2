#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int solution(vector<string>words, vector<char>letters,vector<int>score,
	vector<int>freq, int idx){

	if(idx >= words.size()){
		return 0;
	}

    // word not included
	int wni = solution(words, letters, score, freq, idx+1);

	//If we want to include the word then check for freq and score should not be less than 0
	int flag = 1;
	//check for freq
	int ims=0,wi = 0;
	string dword = words[idx];
	for(int i=0;i<dword.length();i++){
		if(freq[dword[i]-'a'] <= 0){+
			flag = 0;
		}
		freq[dword[i]-'a']-=1;
		ims += score[dword[i]-'a'];
	}
	//check for the letters
	if(flag){
		wi = solution(words, letters, score, freq, idx+1);
		wi += ims;
	}
	for(int i=0;i<dword.length();i++){
		freq[dword[i]-'a']+=1;
	}
	return max(wni, wi);
}

int main(){
	int n,a;
	cin>>n;
	vector<string>words;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		words.push_back(str);
	}
	cin>>a;
	char ch;
	vector<char>letters;
	for(int i=0;i<a;i++){
		cin>>ch;
		letters.push_back(ch);
	}
	vector<int>score(26,0);
	for(int i=0;i<26;i++){
		cin>>score[i];
	}
	if(words.size()==0 || letters.size()==0 || score.size()==0){
		cout<<"0"<<endl;
		return 0;
	}
	vector<int>freq(26,0);
	for(auto c : letters){
		freq[c-'a']++;
	}
	int ans = solution(words, letters, score, freq, 0);
	cout<<ans<<endl;
	return 0;
}