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

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

int main(void){
    Node* root=NULL;
    createBST(root);

    cout<<"level order Traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"MIN Value:- "<<minValue(root)<<endl;
    cout<<"MAX Value:- "<<maxValue(root)<<endl;


    return 0;
}