#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* search_node(node* root, int ele){
    node* temp = root;

    while(temp != NULL && temp->data != ele){
        if(ele < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    return temp;
}

int ceil_BST(node* root, int key){
    node* temp = root;
    int ceil = -1;

    if(temp == NULL){
        return ceil;
    }

    while(temp){
        if(temp->data == key){
            ceil = temp->data;
            return ceil;
        }

        if(temp->data < key){
            temp = temp->right;
        }else{
            ceil = temp->data;
            temp = temp->left;
        }
    }
    return ceil;
}

int floor_BST(node* root, int key){
    node* temp = root;
    int floor = -1;

    if(temp == NULL){
        return floor;
    }

    while(temp){
        if(temp->data == key){
            floor = temp->data;
            return floor;
        }

        if(temp->data > key){
            temp = temp->left;
        }else{
            floor = temp->data;
            temp = temp->right;
        }
    }
    return floor;
}

node* insert_into_BST(node* root, int val){
    node* temp = root;

    if(temp == NULL){
        return new node(val);
    }

    while(1){
        if(temp->data > val){
            if(temp->left){
                temp = temp->left;
            }else{
                temp->left = new node(val);
                break;
            }
        }else{
            if(temp->right){
                temp = temp->right;
            }else{
                temp->right = new node(val);
                break;
            }
        }
    }
    return root;
}

int main(){
    node* root = new node(8);
    root->left = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);

    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    int ans = ceil_BST(root, 11);
    cout<<ans;
}