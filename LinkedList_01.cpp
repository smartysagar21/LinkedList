#include <bits/stdc++.h>

using namespace std;


class Node{

	public:
	int data;
	Node* next;

	//Constructor
	Node(int val){
		this -> data = val;
		this -> next = NULL;
	}

	//Destructor
	~Node(){
		int val = this -> data;

		//Memory Free
		if(this ->next != NULL){
			delete next;
			this -> next = NULL;
		}

		//cout<<"memory is free for node with data "<<val<<endl;
	}
};


void insertionAtHead(Node* &head, Node* &tail, int val){

	//New Node Create
	Node* temp = new Node(val);

	//Empty List
	if(head==NULL){
		head = temp;
		tail = temp;
		return;
	}

	temp -> next = head;
	head = temp;

}


void insertionAtTail(Node* &head, Node* &tail, int val){

	//New Node Create
	Node* temp = new Node(val);

	//Empty List
	if(head==NULL){
		head=temp;
		tail=temp;
		return;
	}

	tail -> next = temp;
	tail = temp;

}


void insertionAtPosition(int position, int val, Node* &head, Node* &tail){

	//Insert At Start
	if(position == 1){
		insertionAtHead(head, tail, val);
		return;
	}

	Node* temp = head;
	int ct=1;

	while(ct < position - 1){
		temp = temp -> next;
		ct++;
	}

	//Insertion At Last Position
	if(temp -> next == NULL){
		insertionAtTail(head, tail, val);
		return;
	} 

	//Creating A Node To Insert
	Node* nodeToInsert = new Node(val);
	nodeToInsert -> next = temp -> next;
	temp -> next = nodeToInsert;

}


void deleteNode(int position, Node* &head, Node* &tail){

	//deleting head node
	if(position==1){
		Node* temp = head;
		head = head -> next;

		//memory free start node
		temp -> next = NULL;
		delete temp;
	}
	//deleting node other than head
	else{
		Node* curr = head;
		Node* prev = NULL;

		int ct = 1;
		while(ct < position){
			prev = curr;
			curr = curr -> next;
			ct++;
		}

		//Updating tail
		if(curr -> next == NULL){
			tail=prev;
		}
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}


//Traversing A Linked List
void print(Node* head){
	Node* temp = head;

	if(temp == NULL){
		cout<<"Empty List"<<endl;
		return;
	}

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}

	cout<<endl;
}


int main(){
	Node* head = NULL;
	Node* tail = NULL;

	print(head);
	insertionAtHead(head, tail, 20);
	print(head);

	insertionAtTail(head, tail, 30);
	print(head);

	insertionAtPosition(3, 50, head, tail);
	print(head);

	deleteNode(1, head, tail);
	print(head);
	cout<<"Head "<<head->data<<" Tail "<<tail->data<<endl;

	return 0;
}

