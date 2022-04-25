#include<bits/stdc++.h>
using namespace std:

	class Node {
	public:
		char data;
		unordered_map<char, Node*> child;
		bool terminal;
		Node(char d) {
			data = d;
			terminal = false;
		}
	};

class Trie {
	Node * root;
	int count;
public:
	Trie() {
		root = new Node('/0');
		count = 0;
	}

	void insert(char *w) {
		Node *temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->child.count(ch)) {
				temp = temp->child[ch];
			}
			else {
				Node*n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

	void find(char*w) {
		Node*temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->child.count(ch) == 0) {
				return false;
			}
			else {
				temp = temp->child[ch];
			}
		}
		return temp->terminal;
	}
};



int main() {
	Trie T;
	char words[][10] = {"a", "hello", "not", "news", "apple"};
	char w[10];
	cin >> w;
	for (int i = 0; i < 5; i++) {
		T.insert(words[i]);
	}

	if (T.find(w)) {
		cout << "Word is Present" << endl;
	}
	else {
		cout << "Word is Absent" << endl;
	}
	return 0;
}