#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 深度优先-递归法-前序-后序
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if(root==NULL) return root;
            TreeNode* node = root->left;
            root->left = root->right;
            root->right = node;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    };

// 深度优先-递归法-中序
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if(root==NULL) return root;
            invertTree(root->left);
            TreeNode* node = root->left;
            root->left = root->right;
            root->right = node;
            // 这里还是左子树
            invertTree(root->left);
            return root;
        }
    };

// 深度优先-迭代法-前序-后序
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while(!st.empty() || cur!=NULL){
                if(cur==NULL){
                    cur = st.top();
                    st.pop();
                }
                TreeNode* node = cur->left;
                cur->left = cur->right;
                cur->right = node;
                // 一定要判断右子树不空才压栈，这样cur==NULL时，从栈中拿出来的节点不是NULL，直接就可以“操作”
                if(cur->right) st.push(cur->right);
                cur = cur->left;
            }
            return root;
        }
    };

// 深度优先-迭代法-中序
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while(!st.empty() || cur!=NULL){
                if(cur!=NULL){
                    st.push(cur);
                    cur = cur->left;
                }else{
                    cur = st.top();
                    st.pop();
                    TreeNode* node = cur->left;
                    cur->left = cur->right;
                    cur->right = node;
                    // 交换之后"右"变"左"
                    cur = cur->left;
                }
            }
            return root;    
        }
    };

// 深度优先-统一迭代法
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            stack<TreeNode*> st;
            if(root==NULL) return root;
            st.push(root);
            while(!st.empty()){
                TreeNode* cur = st.top();
                st.pop();
                if(cur!=NULL){
                    if(cur->right)st.push(cur->right);
                    st.push(cur);
                    st.push(NULL);
                    if(cur->left) st.push(cur->left);
                }else{
                    cur = st.top();
                    st.pop();
                    TreeNode* node = cur->left;
                    cur->left = cur->right;
                    cur->right = node;
                }
            }
            return root;
        }
    };


// 广度优先-层序
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            queue<TreeNode*> que;
            if(root==NULL) return root;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                for(int i=0;i<size;i++){
                    TreeNode* cur = que.front();
                    TreeNode* node = cur->left;
                    cur->left = cur->right;
                    cur->right = node;
                    if(cur->left) que.push(cur->left);
                    if(cur->right) que.push(cur->right);
                    que.pop();
                }
            }      
            return root;
        }
    };