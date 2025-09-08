#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int d)
		{
			data=d;
			next=nullptr;	
		}
		Node()
		{
			data=0;
			next=nullptr;	
		}	
};

class Linkedlist{
    Node* head;
    public:
        Linkedlist()
        {
            head=nullptr;
        }
        void pushback(int d)
		{
			Node* n = new Node(d);
    		if (head == nullptr)
    		{
        		head = n;
        		n->next = head;
        		cout<<"Node created at position: "<<n->data<<endl;
   			}
    		else
    		{
        		Node* temp = head;
        		while (temp->next != head)
        		{
            		temp = temp->next;
        		}

        		temp->next = n;
        		n->next = head;
        		cout<<"Node created at position: "<<n->data<<endl;
    		}
		}

        Node* getHead()
        {
            return head;
        }
};

int Josephus(int N,int k,Node* head)
{
	int j=0;
	Node* temp=head;
	Node* next;
	Node* prev;
	while(temp->next!=temp)
	{
		for (int i = 1; i < k; ++i)
        {
            prev = temp;
            temp = temp->next;
        }
		prev->next=temp->next;
		delete temp;
		temp=prev->next;
		j++;
		if(j==N)
		{
			j=0;
		}
	}
	return temp->data;
}

int main()
{
	int N=7,k=3;
	Linkedlist l;
	for(int i=0;i<N;i++)
	{
		l.pushback(i+1);
	}
	int posi=Josephus(N,k,l.getHead());
	
    cout << endl;
	cout<<"Surviving Node Position: "<<posi<<endl;
}