#include<iostream>
using namespace std;
class Node{
	public:
	Node* left;
	Node* right;
	int value;
	int height;
	Node(int v){
		value = v;
		height = 1;
		left = 0;
		right = 0;
	}
};

int getHeight(Node* n){
	if(n!=0){
		return n->height;
	}
	return 0;
}

void updateHeight(Node* n){
	if(n!=0){
		n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	}
}

Node* minValueNode(Node* n) {
    Node* cur = n;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

int getBalance(Node* n){
	if(n){
		return getHeight(n->left) - getHeight(n->right);
	}
	return 0;
}

Node* rightRotate(Node *y){
	Node* x = y->left;
	Node* T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	updateHeight(y);
	updateHeight(x);
	cout<<"Right rotation performed at "<<y->value<<endl;
	return x;
}

Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	updateHeight(x);
	updateHeight(y);
	cout<<"Left rotation performed at "<<x->value<<endl;
	return y;
}

Node* insert(Node* node, int val){
	if(node==0){
		return new Node(val);
	}
	
	if(val<node->value){
		node->left = insert(node->left, val);
	}
	else if(val>node->value){
		node->right = insert(node->right, val);
	}
	else{
		return node;
	}
	updateHeight(node);
	int balance = getBalance(node);
	
	if(balance>1 && val < node->left->value){
		return rightRotate(node);
	}
	if(balance<-1 && val > node->right->value){
		return leftRotate(node);
	}
	if(balance>1 && val > node->left->value){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && val <node->right->value){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void rangeQuery(Node* root, int x, int y){
	if(root==0){
		return;
	}
	
	if(root->value > x){
		rangeQuery(root->left, x, y);
	}
	if(root->value >=x && root->value <= y){
		cout<<root->value<<" ";
	}
	if(root->value < y){
		rangeQuery(root->right, x, y);
	}
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

int main(){
    Node* root = 0;

    int prices[] = {500, 1200, 800, 1500, 300, 2000, 700, 1000};
    int n = sizeof(prices)/sizeof(prices[0]);

    cout<<"Inserting product prices into AVL Tree: "<<endl;
    for(int i=0; i<n; i++){
        root = insert(root, prices[i]);
    }

    cout<<"All product prices (inorder traversal): ";
    inorder(root);
    cout << endl;

    
    int X, Y;
    cout<<"Enter range X and Y to search prices: ";
    cin>>X>>Y;

    cout<<"Product prices between "<<X<<" and "<<Y<<": ";
    rangeQuery(root, X, Y);
    cout << endl;
    return 0;
}
