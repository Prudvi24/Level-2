#include<bits/stdc++.h>

using namespace std;

class Node;


void display(vector<Node*>vec){
	for(auto val : vec){
		cout<<val<<endl;
	}
}

class Node{
public:
	vector<Node*>child;
	bool isEnd;

	Node(){
		for(int i=0;i<26;i++){
			child.push_back(nullptr);
		}
		isEnd = 0;
	}
	void insert(const string &word);
	bool search(const string &word);
	bool starts_with(const string &word);
};

void Node::insert(const string &word){
		Node *curr = this;
		for(int i=0;i<word.length();i++){
			if(curr->child[word[i]-'a']==nullptr){
				curr->child[word[i]-'a'] = new Node();
			}
			curr = curr->child[word[i]-'a'];
		}
	curr->isEnd = 1;
}

bool Node::search(const string &word){
	Node *curr = this;
	for(int i=0;i<word.length();i++){
		if(curr->child[word[i]-'a']==nullptr){
			return 0;
		}
		curr = curr->child[word[i]-'a'];
	}
	return curr->isEnd;
}

bool Node::starts_with(const string &prefix){
	Node *curr = this;
	for(int i=0;i<prefix.length();i++){
		if(curr->child[prefix[i]-'a']==nullptr){
			return 0;
		}
		curr = curr->child[prefix[i]-'a'];
	}
	return 1;
}


int main(){
	int n;
	cin>>n;
	string query,str;
	Node *root = new Node();
	while(n--){
		cin>>query;
		if(query[0]=='i'){
			cin>>str;
			root->insert(str);
		}
		else if(query[0]=='s' && query[1]=='e'){
			cin>>str;
			bool res = root->search(str);
			if(res){
				cout<<"string exist"<<endl;
			}
			else{
				cout<<"string doesn't exist"<<endl;
			}
		}
		else if(query[0]=='s' && query[1]=='t'){
			cin>>str;
			bool res = root->starts_with(str);
			if(res){
				cout<<"Prefix eixst"<<endl;
			}
			else{
				cout<<"Prefix doesn't exist"<<endl;
			}
		}
	}
	return 0;
}