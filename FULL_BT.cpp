#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> preorder_it(node* root){
    stack<node*> st;

    st.push(root);
    vector<int> ans;

    while(!st.empty()){
        node* temp = st.top();
        st.pop();

        ans.push_back(temp->data);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
    return ans;
}

vector<int> inorder_it(node* root){
    stack<node*> st;

    vector<int> ans;
    node* temp = root;

    while(1){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }else{
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

vector<int> postorder_it(node* root){
    stack<node*> st1;
    stack<node*> st2;

    st1.push(root);

    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left!=NULL) st1.push(temp->left);
        if(temp->right!=NULL) st1.push(temp->right);
    }

    vector<int> ans;

    while(!st2.empty()){
        node* temp = st2.top();
        st2.pop();

        ans.push_back(temp->data);
    }

    return ans;
}

int max_height(node* root){
    if(root == NULL){
        return 0;
    }

    int lh = max_height(root->left);
    int rh = max_height(root->right);

    return 1+max(lh, rh);
}

int isbalanced(node* root){
    if(root == NULL){
        return 0;
    }

    int lh = isbalanced(root->left);
    if(lh == -1) return -1;

    int rh = isbalanced(root->right);
    if(rh == -1) return -1;

    if(abs(rh-lh) > 1) return -1;

    return 1+max(lh, rh);
}

int find_dia(node* root, int &dia){
    if(root == NULL){
        return 0;
    }

    int lh = find_dia(root->left, dia);
    int rh = find_dia(root->right, dia);

    dia = max(dia, rh+lh);

    return 1+max(rh, lh);
}

int maxdia(node* root){
    int dia = 0;
    find_dia(root, dia);
    return dia;
}

int find_msp(node* root, int &msp){
    if(root == NULL){
        return 0;
    }

    int lp = max(0, find_msp(root->left, msp));
    int rp = max(0, find_msp(root->right, msp));

    msp = max(msp, lp+rp+root->data);

    return root->data+max(lp, rp);
}

int maxisumpath(node* root){
    int msp = INT_MIN;
    find_msp(root, msp);
    return msp;
}

bool is_identical(node* p, node* q){
    if(p == NULL || q == NULL){
        return (p == q);
    }

    return (p->data == q->data) &&
    is_identical(p->left, q->left) &&
    is_identical(p->right, q->right);
}

vector<vector<int> > spiral_traversal(node* root){
    vector<vector<int> > ans;

    if(root == NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    bool flag = true;

    while(!q.empty()){
        int n = q.size();

        vector<int> inter(n);

        for(int i = 0; i < n; i++){
            node* temp = q.front();
            q.pop();

            int index;

            if(flag){
                index = i;
            }else{
                index = n-i-1;
            }

            inter[index] = temp->data;

            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        flag = !flag;
        ans.push_back(inter);
    }
    return ans;
}

bool leafnode(node* temp){
    if(temp->left==NULL && temp->right==NULL){
        return true;
    }else{
        return false;
    }
}

void addleft(node* root, vector<int> &ans){
    node* temp = root;

    while(temp){
        if(!leafnode(temp)) ans.push_back(temp->data);

        if(temp->left!=NULL){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
}

void addrigth(node* root, vector<int> &ans){
    node* temp = root->right;
    stack<node*> st;

    while(temp){
        if(!leafnode(temp)){
            st.push(temp);
        }

        if(temp->right!=NULL){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }

    while(!st.empty()){
        node* ele = st.top();
        st.pop();
        ans.push_back(ele->data);
    }
}

void addleaf(node* root, vector<int> &ans){
    node* temp = root;

    if(leafnode(temp)){
        ans.push_back(temp->data);
    }

    if(temp->left!=NULL){
        addleaf(temp->left, ans);
    }

    if(temp->right!=NULL){
        addleaf(temp->right, ans);
    }
}

vector<int> boundary_traversal(node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    addleft(root, ans);
    addleaf(root, ans);
    addrigth(root, ans);

    return ans;
}

vector<int> top_view(node* root){
    queue<pair<node*, int> > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int, int> mpp;

    q.push({root, 0});

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* ele = temp.first;
        int line = temp.second;

        if(mpp.find(line) == mpp.end()){
            mpp[line] = ele->data;
        }

        if(ele->left!=NULL){
            q.push({ele->left, line-1});
        }

        if(ele->right!=NULL){
            q.push({ele->right, line+1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}

vector<int> bottom_view(node* root){
    queue<pair<node*, int> > q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push({root, 0});

    map<int, int> mpp;

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* ele = temp.first;
        int line = temp.second;

        mpp[line] = ele->data;

        if(ele->left!=NULL){
            q.push({ele->left, line-1});
        }

        if(ele->right!=NULL){
            q.push({ele->right, line+1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}

void view_RL(node* root, int lvl, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    if(root->right!=NULL){
        view_RL(root->right, lvl+1, ans);
    }

    if(root->left!=NULL){
        view_RL(root->left, lvl+1, ans);
    }
}

vector<int> find_view(node* root){
    vector<int> ans;
    view_RL(root, 0, ans);
    return ans;
}

bool find_path(node* root, int ele, vector<int> &ans){
    if(root == NULL){
        return false;
    }

    ans.push_back(root->data);

    if(root->data == ele){
        return true;
    }

    if(find_path(root->left, ele, ans) || find_path(root->right, ele, ans)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> node_path(node* root, int ele){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    
    find_path(root, ele, ans);

    return ans;
}

node* LCA(node* root, node* A, node* B){
    if(root == NULL || root == A || root == B){
        return root;
    }

    node* left = LCA(root->left, A, B);
    node* right = LCA(root->right, A, B);

    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }
}

int max_width(node* root){
    long ans = 0;

    if(root == NULL){
        return ans;
    }

    queue<pair<node*, long> > q;

    q.push({root, 0});

    while(!q.empty()){
        int n = q.size();

        long start = q.front().second;
        long end = q.back().second;

        ans = max(ans, end-start+1);

        for(int i = 0; i < n; i++){
            pair<node*, long> item = q.front();

            node* temp = item.first;
            long prev_index = item.second;

            if(temp->left!=NULL) q.push({temp->left, prev_index*2+1});
            if(temp->right!=NULL) q.push({temp->right, prev_index*2+2});

            q.pop();
        } 
    }

    return ans;
}

void validate_Children_Sum_Property(node* &root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    node* temp = root;
    int sum = 0;

    if(temp->left != NULL){
        sum+=temp->left->data;
    }

    if(temp->right != NULL){
        sum+=temp->right->data;
    }
    
    if(sum < temp->data){
        if(temp->left){
            temp->left->data = temp->data;
        }

        if(temp->right){
            temp->right->data = temp->data;
        }
    }else{
        temp->data = sum;
    }
    
    validate_Children_Sum_Property(root->left);
    validate_Children_Sum_Property(root->right);

    int val = 0;

    if(root->left) val+=root->left->data;
    if(root->right) val+=root->right->data;

    if(root->left!=NULL || root->right!=NULL){
        root->data = val;
    }
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> node_at_distance_K(node* root, node* target, int k){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    unordered_map<node*, node*> parent;
    queue<node*> p;

    p.push(root);

    while(!p.empty()){
        node* temp = p.front();
        p.pop();

        if(temp->left){
            parent[temp->left] = temp;
            p.push(temp->left);
        }

        if(temp->right){
            parent[temp->right] = temp;
            p.push(temp->right);
        }
    }

    queue<node*> q;
    unordered_map<node*, int> vis;

    q.push(target);
    vis[target] = 1;

    int dis = 0;
    while(!q.empty()){
        if(dis == k){
            break;
        }

        int n = q.size();

        for(int i = 0; i < n; i++){
            node* temp = q.front();
            q.pop();

            if(temp->left && vis[temp->left]!=1){
                q.push(temp->left);
                vis[temp->left] = 1;
            }

            if(temp->right && vis[temp->right]!=1){
                q.push(temp->right);
                vis[temp->right] = 1;
            }

            if(parent.find(temp)!=parent.end()){
                node* par = parent[temp];
                if(vis[par]!=1){
                    q.push(par);
                    vis[par] = 1;
                }
            }
        }
        dis++;
    }

    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
}

int burn_BT(node* root, int target){

    if(root == NULL){
        return 0;
    }

    unordered_map<node*, node*> parent;
    queue<node*> p;

    p.push(root);

    node* start = NULL;

    int dis = 0;
    while(!p.empty()){
        node* temp = p.front();
        p.pop();

        if(temp->data == target){
            start = temp;
        }

        if(temp->left){
            parent[temp->left] = temp;
            p.push(temp->left);
        }

        if(temp->right){
            parent[temp->right] = temp;
            p.push(temp->right);
        }
    }

    queue<node*> q;
    unordered_map<node*, int> vis;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()){
        int n = q.size();
        int flag = 0;

        for(int i = 0; i < n; i++){
            node* temp = q.front();
            q.pop();

            if(temp->left && vis[temp->left]!=1){
                q.push(temp->left);
                vis[temp->left] = 1;
                flag = 1;
            }

            if(temp->right && vis[temp->right]!=1){
                q.push(temp->right);
                vis[temp->right] = 1;
                flag = 1;
            }

            if(parent.find(temp)!=parent.end()){
                node* par = parent[temp];
                if(vis[par]!=1){
                    q.push(par);
                    vis[par] = 1;
                    flag = 1;
                }
            }
        }

        if(flag){
            dis++;
        }
    }
    return dis;
}

int findleftheight(node* temp){
    int height = 0;
    while(temp){
        height++;
        temp = temp->left;
    }
    return height;
}

int findrightheight(node* temp){
    int height = 0;
    while(temp){
        height++;
        temp = temp->right;
    }
    return height;
}

int count_nodes(node* root){
    if(root == NULL){
        return 0;
    }

    int lh = findleftheight(root);
    int rh = findrightheight(root);

    if(lh == rh){
        return pow(2, lh)-1;
    }

    return 1+count_nodes(root->left)+count_nodes(root->right);
}

node* BuildTree(vector<int> PRE, vector<int> IN, int PreorderStart, int PreorderEnd, int InorderStart, int InorderEnd){

    if(PreorderStart > PreorderEnd || InorderStart > InorderEnd){
        return NULL;
    }

    int rootVal = PRE[PreorderStart];

    int rootIndex = -1;

    for(int i = InorderStart; i <= InorderEnd; i++){
        if(rootVal == IN[i]){
            rootIndex = i;
            break;
        }
    }

    node* root = new node(rootVal);

    int lInS = InorderStart;
    int lInE = rootIndex-1;
    int rInS = rootIndex+1;
    int rInE = InorderEnd;

    int lPrS = PreorderStart+1;
    int lPrE = lInE - lInS + lPrS;
    int rPrS = lPrE+1;
    int rPrE = PreorderEnd;

    root->left = BuildTree(PRE, IN, lPrS, lPrE, lInS, lInE);
    root->right = BuildTree(PRE, IN, rPrS, rPrE, rInS, rInE);

    return root;
}

node* construct_BT_InPre(vector<int> PRE, vector<int> IN){
    int PreorderStart = 0;
    int PreorderEnd = PRE.size()-1;

    int InorderStart = 0;
    int InorderEnd = IN.size()-1;

    return BuildTree(PRE, IN, PreorderStart, PreorderEnd, InorderStart, InorderEnd);
}

string serialize(node* root){
    string ans = "";

    if(root == NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp){
            ans+=to_string(temp->data)+',';
            q.push(temp->left);
            q.push(temp->right);
        }else{
            ans+="#,";
        }
    }
    return ans;
}

node* deserialize(string tree){
    if(tree.size() < 1 && tree[0]=='#'){
        return NULL;
    }

    stringstream s(tree);

    string str;

    getline(s, str, ',');

    node* root = new node(stoi(str));

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        getline(s, str, ',');

        if(str == "#"){
            temp->left = NULL;
        }else{
            temp->left = new node(stoi(str));
            q.push(temp->left);
        }

        getline(s, str, ',');

        if(str == "#"){
            temp->right = NULL;
        }else{
            temp->right = new node(stoi(str));
            q.push(temp->right);
        }
    }
    return root;
}

vector<int> morris_inorder(node* root){
    vector<int> inorder;

    if(root == NULL){
        return inorder;
    }

    node* curr = root;

    while(curr!=NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* prev = curr->left;

            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> morris_preorder(node* root){
    vector<int> preorder;

    if(root == NULL){
        return preorder;
    }

    node* curr = root;

    while(curr!=NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* prev = curr->left;

            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                preorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return preorder;
}

node* prevs = NULL;
void flatten(node* root){
    if(root == NULL){
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->right = prevs;
    root->left = NULL;

    prevs = root;
}

int main(){
    node* root = new node(-3);
    root->left = new node(5);
    root->right = new node( 1);
    
    root->left->left = new node(-6);
    root->left->right = new node(-2);

    //root->left->right->left = new node(7);
    //root->left->right->right = new node(4);

    //root->right->left = new node(0);
    //root->right->right = new node(8);

    vector<int> ans = morris_inorder(root);

    for(auto it: ans){
        cout<<it<<" ";
    }  
}
