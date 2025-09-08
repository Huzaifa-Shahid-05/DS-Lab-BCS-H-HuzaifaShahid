#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* pointer;
		Node(int val){
			data = val;
			next = 0;
			pointer = 0;
		}
};

Node* flatLL(Node* head){
	Node* curr = head;
	while(curr != 0){
		if(curr->pointer != 0){
			Node* child = flatLL(curr->pointer);
			Node* nextNode = curr->next;
			curr->next = curr->pointer;
			curr->pointer = 0;
			while(curr->next != 0){
		    	curr= curr->next;
			}
			Node* tail = curr;
			tail->next = nextNode;
		}
		curr = curr->next;
	}
	return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->pointer = new Node(4);
    head->next->pointer->next = new Node(5);
    Node* flatten = flatLL(head);
    Node* temp = flatten;
    while(temp != 0){
        cout<<temp->data;
        if (temp->next != 0){
        	cout<<"->";
		}
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}
