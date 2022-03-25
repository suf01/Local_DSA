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

void insertAtHead(node* &head, int data){
    node* n = new node(data);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new node(data);
    }
}

int length(node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

void insertInMiddle(node* &head, int data, int pos){
    node* temp = head;
    if(head == NULL || pos == 0){
        insertAtHead(head, data);
    }else
    if(pos > length(head)){
        insertAtTail(head, data);
    }else{
        while(--pos){
            temp = temp->next;
        }
        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;

    }
}

bool SearchRecursive(node* head, int key){
    if(head == NULL){
        return false;
    }

    if(head->data == key){
        return true;
    }else{
        return SearchRecursive(head->next, key);
    }
}

bool SearchIterative(node* head, int key){
    while(head != NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteAtHead(node* &head){
    if(head == NULL){
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(node* &head){
    if(head == NULL){
        return;
    }

    node* prev = NULL;
    node* temp = head;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;
}

void deleteInMiddle(node* &head, int pos){
    if(head == NULL){
        return;
    }
    node* temp = head;
    node* prev = NULL;
    while(--pos){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

void BuildList(node* &head){
    int data;
    cin>>data;

    while(data != -1){
        insertAtTail(head, data);
        cin>>data;
    }
}

void ReverseLLit(node* &head){
    node *P = NULL;
    node *C = head;
    node *N = C->next;

    while(C != NULL){
        C->next = P;
        P = C;
        C = N;
        if(N!=NULL) N=N->next;
    }
    head = P;
}

node* revLLrec(node* head){
    if(head->next == NULL) return head;

    node* reversed_head = revLLrec(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversed_head;
}

node* ReverseLLrec(node* head){
    if(head == NULL) return NULL;

    return revLLrec(head);
}

void 

int main(){
    node* head = NULL;
    BuildList(head);
    print(head);
    ReverseLL(head);
    print(head);
    /*
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    
    insertAtTail(head, 10);

    insertInMiddle(head, 7, 2);
    print(head);

    if(SearchRecursive(head, 7)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
    
    deleteAtHead(head);
    deleteAtTail(head);
    print(head);
    
    deleteInMiddle(head, 2);
    print(head);

    if(SearchIterative(head, 7)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
    */

}
