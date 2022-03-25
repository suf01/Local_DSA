#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int> > verticalTrav(node* root){
    //vertical, level, node
    map<int, map<int, multiset<int>> > nodes;
    queue<pair<node*, pair<int, int>> > todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        node* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left, {x-1, y+1}});
        }
        if(node->right){
            todo.push({node->right, {x+1, y+1}});
        }
    }

    vector<vector<int> > ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(8);

    verticalTrav(root);
}