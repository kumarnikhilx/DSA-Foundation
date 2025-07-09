#include <iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertIntoBST(Node* root, int data) {
	if(root == NULL) {
		root = new Node(data);
		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}

void createBST(Node* &root) {
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

	while(data != -1) {
		root = insertIntoBST(root, data);
		cout << "Enter data:" << endl;
		cin >> data;
	}
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

bool searchInBST(Node* root, int target) {
	//base case
	if(root == NULL) {
		return false;
	}

	//1 case mujhe solve krna h 
	if(root->data == target ) {
		return true;
	}

	//baaaki recursion sambhal lega 
	//left ya right
	bool leftAns = false;
	bool rightAns = false;
	if(target > root->data) {
		rightAns = searchInBST(root->right, target);
	}
	else {
		leftAns = searchInBST(root->left, target);
	}

	return leftAns || rightAns;
}

int main(void){
    Node* root=NULL;
    createBST(root);
    int target=25;

    searchInBST(root,target);


    return 0;
}