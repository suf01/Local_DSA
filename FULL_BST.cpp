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

node* findlastright(node* temp){
    if(temp->right == NULL){
        return temp;
    }
    return findlastright(temp->right);
}

node* helper(node* temp){
    if(temp->left == NULL){
        return temp->right;
    }
    if(temp->right == NULL){
        return temp->left;
    }

    node* rightchild = temp->right;
    node* lastright = findlastright(temp->left);

    lastright->right = rightchild;

    return temp->left;
}

node* delete_node(node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return helper(root);
    }

    node* temp = root;

    while(temp!=NULL){
        if(key < temp->data){
            if(temp->left != NULL && temp->left->data == key){
                temp->left = helper(temp->left);
                break;
            }else{
                temp = temp->left;
            }
        }else{
            if(temp->right != NULL && temp->right->data == key){
                temp->right = helper(temp->right);
                break;
            }else{
                temp = temp->right;
            }
        }
    }
    return root;
}

void inorder(node* root, int &k, int &res){
    if(root == NULL){
        return;
    }

    inorder(root->left, k, res);
    
    if(--k == 0){
        res = root->data;
        return;
    }

    inorder(root->right, k, res);
}

int kth_smallest(node* root, int k){
    int res = -1;

    inorder(root, k, res);
    return res;
}

//for leetcode use long instead of int, donot pass minval and maxval with reference and is <= and >=
bool check(node* root, int minval, int maxval){
    if(root == NULL){
        return true;
    }

    if(root->data <= minval || root->data >= maxval){
        return false;
    }

    return check(root->left, minval, root->data) && check(root->right, root->data, maxval);
}

bool check_BST(node* root){
    int minval = INT_MIN;
    int maxval = INT_MAX;

    return check(root, minval, maxval);
}

node* LCA_BST(node* root, node* p, node* q){
    if(root == NULL){
        return NULL;
    }

    if(p->data < root->data && q->data < root->data){
        return LCA_BST(root->left, p, q);
    }
    if(p->data > root->data && q->data > root->data){
        return LCA_BST(root->right, p, q);
    }
    return root;
}

node* bulidtree(vector<int> &v, int &i, int bound){
    if(i == v.size() || v[i] > bound){
        return NULL;
    }

    node* root = new node(v[i]);
    i++;
    root->left = bulidtree(v, i, root->data);
    root->right = bulidtree(v, i, bound);
    return root;
}

node* BST_preorder(vector<int> &v){
    int i = 0;
    int bound = INT_MAX;
    return bulidtree(v, i, bound);
}

int successor(node* root, node* key){
    int ans = -1;

    while(root){
        if(key->data < root->data){
            ans = root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ans;
}

int predecessor(node* root, node* key){
    int ans = -1;

    while(root){
        if(key->data < root->data){
            root = root->left;
        }else{
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

//read bst iterator
//to two sum IV using bst iterator for O(N) & O(H)
void find_inorder(TreeNode* root, vector<int> &inorder){
    if(root == NULL){
        return;
    }
        
    find_inorder(root->left, inorder);
    inorder.push_back(root->val);
    find_inorder(root->right, inorder);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    find_inorder(root, inorder);
        
    int i = 0;
    int j = inorder.size()-1;
        
    while(i < j){
        if(inorder[i]+inorder[j] == k){
            return true;
        }
        if(inorder[i]+inorder[j] > k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

void find_swapped(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &end){
    if(root == NULL){
        return;
    }
        
    find_swapped(root->left, prev, first, end);
        
    if(prev){
        if(root->val < prev->val){
            if(!first){
                first = prev;
            }
            end = root;
        }
    }
    prev = root;
        
    find_swapped(root->right, prev, first, end);   
}
    
void recoverTree(TreeNode* root) {
    TreeNode *prev = NULL;
    TreeNode* first = NULL;
    TreeNode* end = NULL;
        
    find_swapped(root, prev, first, end);
    swap(first->val, end->val);
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
}
