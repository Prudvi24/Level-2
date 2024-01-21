#include<bits/stdc++.h>

using namespace std;

class Node;
void display(vector<Node*>vec){
	for(auto val : vec){
		cout<<val<<endl;
	}
	cout<<endl;
}

class Node{
public:
	vector<Node*>child;
	bool isEnd;

	Node(){
		for(int i=0;i<26;i++){
			child.push_back(nullptr);
		}
		isEnd=0;
	}
	void addWord(const string &word);
	bool searchWord(string word);
	bool find(string word, int idx);
};

void Node::addWord(const string &word){
	Node *curr = this;
	for(int i=0;i<word.length();i++){
		if(curr->child[word[i]-'a']==nullptr){
			curr->child[word[i]-'a'] = new Node();
		}
		curr = curr->child[word[i]-'a'];
	}
	curr->isEnd = 1;
}

bool Node::find(string word, int i){
	Node *curr = this;
	if(word.length()==i){
		return curr->isEnd;
	}

	if(word[i]=='.'){
		for(int j=0;j<26;j++){
			if(curr->child[j]!=nullptr){
				curr = curr->child[j];
				bool res = curr->find(word, i+1);
				if(res){
					return 1;
				}
			}
		}
		return 0;
	}
	else{
		if(curr->child[word[i]-'a']==nullptr){
			return 0;
		}
		curr = curr->child[word[i]-'a'];
		bool res = curr->find(word, i+1);
		return res;
	}
}

bool Node::searchWord(string word){
	Node *curr = this;
	return curr->find(word, 0);
}


int main(){
	int n;
	cin>>n;
	string query, str;
	Node *root = new Node();
	while(n--){
		cin>>query;
		cin>>str;
		if(query[0]=='a'){
			root->addWord(str);
		}
		else{
			bool res = root->searchWord(str);
			if(res){
				cout<<"String exist"<<endl;
			}
			else{
				cout<<"String doesn't found"<<endl;
			}
		}
	}
	return 0;
}