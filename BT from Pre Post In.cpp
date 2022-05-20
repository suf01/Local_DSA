//use haspmap to store the index of elements in inorder

//from preorder and inorder

TreeNode* buildTreePrIn_help(vector<int> preorder, vector<int> inorder, int preorderstart, int preorderend, int inorderstart, int inorderend){
        if(preorderstart > preorderend || inorderstart > inorderend){
            return NULL; 
        }
        
        int rootVal = preorder[preorderstart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = -1;
        for(int i = inorderstart; i <= inorderend; i++){
            if(rootVal == inorder[i]){
                rootIndex = i;
                break;
            }
        }
        
        int lInS = inorderstart;
        int lInE = rootIndex-1;
        int rInS = rootIndex+1;
        int rInE = inorderend;
        
        int lPrS = preorderstart+1;
        int lPrE = lInE - lInS + lPrS;
        int rPrS = lPrE+1;
        int rPrE = preorderend;
        
        root->left = buildTreePrIn_help(preorder, inorder, lPrS, lPrE, lInS, lInE);
        root->right = buildTreePrIn_help(preorder, inorder, rPrS, rPrE, rInS, rInE);
        
        return root;
    }

//from postorder and inorder

TreeNode* buildTreeInPo_help(vector<int> inorder, vector<int> postorder, int postorderstart, int postorderend, int inorderstart, int inorderend){
        if(postorderstart > postorderend || inorderstart > inorderend){
            return NULL; 
        }
        
        int rootVal = postorder[postorderend];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = -1;
        for(int i = inorderstart; i <= inorderend; i++){
            if(rootVal == inorder[i]){
                rootIndex = i;
                break;
            }
        }
        
        int lInS = inorderstart;
        int lInE = rootIndex-1;
        int rInS = rootIndex+1;
        int rInE = inorderend;
        
        int rPoE = postorderend-1;
        int rPoS = rPoE-rInE+rInS;
        int lPoE = rPoS-1;
        int lPoS = postorderstart;
        
        root->left = buildTreeInPo_help(inorder, postorder, lPoS, lPoE, lInS, lInE);
        root->right = buildTreeInPo_help(inorder, postorder, rPoS, rPoE, rInS, rInE);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderstart = 0;
        int preorderend = preorder.size()-1;
        
        int inorderstart = 0;
        int inorderend = inorder.size()-1;
        
        return buildTreePrIn_help(preorder, inorder, preorderstart, preorderend, inorderstart, inorderend);
        //for inorder and postorder return buildTreeInPo_help(preorder, inorder, preorderstart, preorderend, inorderstart, inorderend);
    }
