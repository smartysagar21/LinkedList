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


void insertNode(Node* &tail, int element, int val){

	//Empty List
	if(tail == NULL){
		Node* newNode = new Node(val);
		tail = newNode;
		newNode -> next = newNode;
	}
	else{
		//Non-Empty List
		//Assuming that the element is present in the list

		Node* curr = tail;

		while(curr -> data != element){
			curr = curr -> next;
		}

		//Element found -> curr is representing element wla node
		Node* temp = new Node(val);
		temp -> next = curr -> next;
		curr -> next = temp;

	}
}



void deleteNode(Node* &tail, int val){

	//Empty List
	if(tail==NULL){
		cout<<"Empty List"<<endl;
		return;
	}
	//Non-Empty List
	else{

		//Assuming that value is present in the Linked List
		Node* prev = tail;
		Node* curr = prev -> next;

		while(curr -> data != val){
			prev = curr;
			curr = curr -> next;
		}

		//1 Length Linked List
		if(curr == prev){
			tail = NULL;
		}

		if(tail == curr){
			tail = prev;
		}

		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}


//Traversing A Linked List
void print(Node* tail){

	Node* temp = tail;

	if(tail == NULL){
		cout<<"EMPTY LIST"<<endl;
		return;
	}

	do{
		cout<<tail -> data<<" ";
		tail = tail -> next;
	}while(tail != temp);
	cout<<endl;
}



int main(){
	

	Node* tail = NULL;

	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 5);
	print(tail);

	insertNode(tail, 3, 7);
	print(tail);

	deleteNode(tail, 5);
	print(tail);
	
	deleteNode(tail, 3);
	print(tail);

	deleteNode(tail, 7);
	print(tail);



	return 0;
}
