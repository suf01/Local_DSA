#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

node* floydcycle(node* head){
	if(head == NULL || head->next == NULL){
		return NULL;
	}

	node* slow = head;
	node* fast = head;
    //fast != NULL && fast->next!= NULL 
	while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast){
			return slow;
		}
	}
	return NULL;
}

node* cylcestart(node* head){
	node* meet = floydcycle(head);
	node* start = head;

	while(meet != start){
		start = start->next;
		meet = meet->next;
	}
	return meet;
}

void removecylce(node* head){
	node* meet = floydcycle(head);
	node* start = head;
	node* prev;

	while(meet != start){
		start = start->next;
		prev = meet;
		meet = meet->next;
	}
	prev->next = NULL;

	while(head!= NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
}
int main(){
	node* head = new node(1);
	head->next = new node(2);
	node* p = head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = p;


	removecylce(head);
}