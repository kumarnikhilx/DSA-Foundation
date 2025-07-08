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


Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}
void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) 
	return;

  if(level == leftView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	leftView.push_back(root->data);
  }
  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}


int main(){
    Node* root = createTree();
//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 

    vector<int> leftView;
  printLeftView(root, 0, leftView);
    return 0;

     for(int i=0; i<leftView.size(); i++) {
	  cout << leftView[i] << " ";
  }

}