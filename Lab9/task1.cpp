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

Node* deleteNode(Node* root, int val) {
    if (!root) return root;

    if (val < root->value) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->value) {
        root->right = deleteNode(root->right, val);
    } else {
        //no child
        if (!root->left && !root->right) {
            cout << "Deleting " <<val<< ": Case 1 (no child / leaf)\n";
            delete root;
            return 0;
        } 
        //one child
        else if (!root->left || !root->right) {
            cout << "Deleting " <<val<< ": Case 2 (one child)\n";
            Node* child = root->left ? root->left : root->right;
            Node* temp = root;
            root = child;      
            delete temp;
        } 
        //two children
        else {
            Node* succ = minValueNode(root->right);
            cout << "Deleting " <<val<< ": Case 3 (two children). Inorder successor = " << succ->value << "\n";
            root->value = succ->value;
            root->right = deleteNode(root->right, succ->value);
        }
    }

    if (!root) return root;
    updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    cout << root->value<< " ";
    inorder(root->right);
}


void printPathBalances(Node* root, int key) {
    Node* cur = root;
    cout<<"Affected nodes (key(balance)): ";
    while(cur){
        cout << cur->value << "(" << getBalance(cur) << ") ";
        if(key < cur->value) cur = cur->left;
        else if(key > cur->value) cur = cur->right;
        else break;
    }
    cout << endl;
}

Node* doInsert(Node* root, int val){
	cout<<endl;
    cout<<"--- Insert "<<val<<"-----"<<endl;
    root = insert(root, val);
    cout << "Tree height: " << getHeight(root) << endl;
    printPathBalances(root, val);
    return root;
}

Node* doDelete(Node* root, int val){
    cout<<"-----Delete "<<val<<"-----"<<endl;
    root = deleteNode(root, val);
    if(root) cout<<"Tree height: "<<getHeight(root)<<endl;
    printPathBalances(root, val);
    return root;
}

int main(){
    Node* root = 0;

    int inserts[] = {105, 210, 150, 300, 75, 90, 180, 50, 250, 275};
    int nInserts = sizeof(inserts)/sizeof(inserts[0]);
    cout<<"-----Inserting roll numbers-----"<<endl;
    for(int i=0;i<nInserts;i++){
        root = doInsert(root, inserts[i]);
    }

    cout<<"-----Tree after all insertions-----"<<endl;
    cout<<"Tree height: "<<getHeight(root)<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout << endl;


    int deletes[] = {90, 105, 300, 250};
    int nDeletes = sizeof(deletes)/sizeof(deletes[0]);
    cout<<"-----Deleting roll numbers-----"<<endl;
    for(int i=0;i<nDeletes;i++){
        root = doDelete(root, deletes[i]);
    }
    cout<<endl;
    cout<<"-----Final tree state-----"<<endl;
    cout<<"Tree height: "<<getHeight(root)<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}
