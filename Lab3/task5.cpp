#include<iostream>
using namespace std;

class Node {
public:   
    int data;
    Node* next;
    Node(int d) : data(d), next(0) {}
};

class DoublyNode {  
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int d, DoublyNode* n=0, DoublyNode* p=0) : data(d), next(n), prev(p) {}
};

DoublyNode* singlyToDoubly(Node* head){
	if(!head){
		return 0;
	}
	DoublyNode* head2 = new DoublyNode(head->data,0, 0);
	DoublyNode* tail = head2;
	Node* temp = head;
	temp = temp->next;
	while(temp!=0){
		DoublyNode* node = new DoublyNode(temp->data, 0, tail);
		tail->next = node;
		tail = node;
		temp = temp->next;
	}
	return head2;
}

Node* singlyToCircular(Node* head){
    Node* temp = head;
    while(temp->next != 0){   
        temp = temp->next;
    }
    temp->next = head;   
    return head;         
}

void circularPrint(Node* head, int times){
	Node* temp = head;
	int counter = 0;
	while(counter<times){
		counter+=1;
		cout<<"value = "<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	Node* head = new Node(12);
	head->next = new Node(14);
	head->next->next = new Node(18);
	head->next->next->next = new Node(20);
	DoublyNode* doublyHead = singlyToDoubly(head);

    head = singlyToCircular(head);
    circularPrint(head, 6);
	cout<<"---forward using next pointer---"<<endl;
	DoublyNode* temp = doublyHead;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;

	cout<<"---backward using prev pointer---"<<endl;
	temp = doublyHead;
	while(temp->next){ 
		temp = temp->next;
	}
	while(temp){
		cout<<temp->data<< " ";
		temp = temp->prev;
	}
	cout<<endl;

	return 0;
}