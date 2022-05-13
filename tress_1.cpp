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

/*
struct node
{
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
*/

void preorder(node* root){
    
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelorder(node* root){

    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* cur = q.front();
        cout<<cur->data<<" ";

        if(cur->left != NULL) q.push(cur->left);
        if(cur->right != NULL) q.push(cur->right);

        q.pop();
    }
}

vector<vector<int> > level_order(node* root){
    queue<node*> q;

    vector<vector<int> > ans;

    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> inter;

        while(n){
            node* temp = q.front();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            inter.push_back(temp->data);
            q.pop();
            n--;
        }
        ans.push_back(inter);
    }
    return ans;
}

int maxdepth(node* root){
    if(root == NULL){
        return 0;
    }
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);

    return 1 + max(lh, rh);
}

int diam(node* root, int &diameter){
    if(root == NULL){
        return 0;
    }

    int lh = diam(root->left, diameter);
    int rh = diam(root->right, diameter);

    diameter = max(diameter, lh+rh);

    return max(lh, rh)+1;
}

int diameterofBT(node* root){
    int diameter = 0;
    diam(root, diameter);
    return diameter;
}

int isbalanced(node* root){
    if(root == NULL){
        return 0;
    }
    int lh = isbalanced(root->left);
    if(lh == -1) return -1;
    
    int rh = isbalanced(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh>1)){
        return -1;
    }

    return max(lh, rh)+1;
}
int msp(node* root, int &maxi){
    if(root == NULL){
        return 0;
    }

    int lp = msp(root->left, maxi);
    int rp = msp(root->right, maxi);

    /*for negetive numbers
    int lp = max(0, msp(root->left, maxi));
    int rp = max(0, msp(root->right, maxi));
    */
    maxi = max(maxi, lp+rp+root->data);

    return max(lp, rp)+root->data;
}

int maxsumpath(node* root){
    int maxi = INT_MIN;
    msp(root, maxi);
    return maxi;
}

void sprialtraversal(node* root){ 

    if(root == NULL){
        return ;
    }

    stack<node*> ms;
    ms.push(root);

    int flag = 1;
    stack<node*> cs;
    
    while(!ms.empty()){
        
        node* temp = ms.top();
        cout<<temp->data<<" ";
        ms.pop();

        if(flag){
            if(temp->left != NULL){
                cs.push(temp->left);
            }
            if(temp->right != NULL){
                cs.push(temp->right);
            }
        }else{
            if(temp->right != NULL){
                cs.push(temp->right);
            }
            if(temp->left != NULL){
                cs.push(temp->left);
            }
        }
        
        if(ms.empty()){
            swap(ms, cs);
            flag = !flag;
            cout<<endl;
        }
    }
}

int main(){
    node* root = new node(1);
    
    root->left = new node(3);
    
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    
    root->right = new node(4);
    
    root->right->left = new node(7);
    root->right->left->left = new node(10);
    
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;

    levelorder(root);
    cout<<endl;

    cout<<maxdepth(root)<<endl;

    if(isbalanced(root)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }

    cout<<diameterofBT(root)<<endl;

    cout<<maxsumpath(root)<<endl;

    sprialtraversal(root);

}
