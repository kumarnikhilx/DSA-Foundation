#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* createTree(){
    cout<<"enter a value"<<endl;
    int data;
    cin>> data;

    if(data==-1){
        return NULL;
    }

    // step1:- create node for the new data

    Node* root=new Node(data);

    // step2: make left subtree;
    cout<<"enter the node for the left"<<endl;
    root->left=createTree();
    
    // step3: make right subtree
    cout<<"enter the node for the right"<<endl;
    root->right= createTree();

    return root;

}



void printTopView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));

	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		//if there is no entry for hd in map, then create a new entry
		if(hdToNodemap.find(hd) == hdToNodemap.end()) {
			hdToNodemap[hd] = frontNode->data;
		}

		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}
		
	}
	cout << "printing top view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}
	
}

void printBottomView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));

	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		//overwrite answers so that the deeper nodes can be stored
		hdToNodemap[hd] = frontNode->data;

		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}

	}
	cout << "printing bottom view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}

}

int main(){
    Node* root=createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 

    printTopView(root);
    printBottomView(root);


}