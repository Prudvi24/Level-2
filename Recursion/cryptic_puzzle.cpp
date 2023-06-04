#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void display_hash(unordered_map<char, int>&hash){
	for(auto item : hash){
		cout<<item.first<<"-"<<item.second<<" ";
	}
	cout<<endl;
}

void solution(unordered_map<char,int>&hash, vector<int>&num,string unique, string s1, string s2, string s3, int idx){
	
	if(idx>=unique.length()){
		long int n1=0, n2=0, n3=0;
		int mul = 1;
		for(int i=s1.length()-1;i>=0;i--){
			n1 += hash[s1[i]]*(mul);
			mul *= 10;
		}
		mul=1;
		for(int i=s2.length()-1;i>=0;i--){
			n2 += hash[s2[i]]*(mul);
			mul *= 10;
		}
		mul=1;
		for(int i=s3.length()-1;i>=0;i--){
			n3 += hash[s3[i]]*(mul);
			mul *= 10;
		}
		//cout<<n1<<" --> "<<n2<<" --> "<<n3<<endl;
		if(n1+n2==n3){
			display_hash(hash);
		}
		return ;
	}

	for(int i=0;i<10;i++){
		if(num[i]==0){
			num[i] = 1;
			hash[unique[idx]] = i;
			solution(hash,num,unique,s1,s2,s3,idx+1);
			hash[unique[idx]] = 0;
			num[i] = 0;
		}
	}
}

int main(){
	string s1,s2,s3, unique="";
	cin>>s1>>s2>>s3;
	unordered_map<char, int>hashmap;
	for(int i=0;i<s1.length();i++){
		if(hashmap.find(s1[i])==hashmap.end()){
			hashmap[s1[i]] = -1;
			unique += s1[i];
		}
	}
	for(int i=0;i<s2.length();i++){
		if(hashmap.find(s2[i])==hashmap.end()){
			hashmap[s2[i]] = -1;
			unique += s2[i];
		}
	}
	for(int i=0;i<s3.length();i++){
		if(hashmap.find(s3[i])==hashmap.end()){
			hashmap[s3[i]] = -1;
			unique += s3[i];
		}
	}
	vector<int>num(10,0);
	solution(hashmap,num,unique,s1,s2,s3,0);
	return 0;
}

