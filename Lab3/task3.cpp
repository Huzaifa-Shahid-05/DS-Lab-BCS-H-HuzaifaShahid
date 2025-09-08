#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;

		Node(int val){
			data = val;
			next = NULL;
		}
};

Node* reverseLinkedList(Node* head){
	Node* p = head;
	Node* q = 0;
	Node* r = 0;
	while(p!=0){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	return q;
}

Node* findKthNode(Node* temp, int k){
	int n = k-1;
	while(temp!=0 && n>0){
		n--;
		temp = temp->next;
	}
	return temp;
}

Node* reverseListinGroup(Node* head, int k){
	Node* curr = head;
	Node* kthNode = curr;
	Node* LastNode=0;
	while(curr!=0){
		kthNode = findKthNode(curr, k);
		if(kthNode==0){
			if(LastNode){
				LastNode->next = curr;
			}
			break;
		}
		Node* nextNode = kthNode->next;
        kthNode->next = 0;
        Node* newHead = reverseLinkedList(curr);  
        if (curr == head) {
            head = newHead;  
        } else {
            LastNode->next = newHead;  
        }
        LastNode = curr;   
        curr = nextNode;   
	}
	return head;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    
    cout<< "---Original List---"<<endl;
    Node* temp = head;
    while(temp != 0){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout <<endl;

    int k = 3; 
    head = reverseListinGroup(head, k);

    cout<<"---Reversed---"<<endl;
    temp = head;
    while (temp != 0) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}
