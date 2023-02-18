#include <bits/stdc++.h>

using namespace std;


class Node{

	public:
	int data;
	Node* prev;
	Node* next;

	//Constructor
	Node(int val){
		this -> data = val;
		this -> prev = NULL;
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

	//For Empty List
	if(head == NULL){
		head = temp;
		tail = temp;
	}
	else{
		temp -> next = head;
		head -> prev = temp;
		head = temp;
	}
	
}


void insertionAtTail(Node* &head, Node* &tail, int val){

	//New Node Create
	Node* temp = new Node(val);

	if(tail == NULL){
		tail = temp;
		head = temp;
	}
	else{
		tail -> next = temp;
		temp -> prev = tail;
		tail = temp;
	}

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

	//Creating A Node To Insert In Middle
	Node* nodeToInsert = new Node(val);

	nodeToInsert -> next = temp -> next;
	temp -> next -> prev = nodeToInsert;
	temp -> next = nodeToInsert;
	nodeToInsert -> prev = temp;
	
}


void deleteNode(int position, Node* &head, Node* &tail){

	//deleting head node
	if(position==1){
		Node* temp = head;
		temp -> next -> prev = NULL;
		head = temp -> next;

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

		curr -> prev = NULL;
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


//Getting size of the Linked List
int getLength(Node* head){
	int length=0;
	Node* temp = head;

	while(temp != NULL){
		length++;
		temp = temp -> next;
	}

	return length;
}


int main(){
	

	Node* head = NULL;
	Node* tail = NULL;

	print(head);

	insertionAtHead(head, tail, 10);

	print(head);

	cout<<getLength(head)<<endl;



	return 0;
}

