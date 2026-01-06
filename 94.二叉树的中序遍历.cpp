#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 递归法
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            traversal(root, res);
            return  res;
        }
        void traversal(TreeNode* node, vector<int>& res){
            if(node == NULL) return;
            traversal(node->left, res);
            res.push_back(node->val);
            traversal(node->right, res);
        }
    };

// 迭代法 
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while(!st.empty() || cur!=NULL){
                if(cur!=NULL){
                    st.push(cur);
                    cur = cur->left;
                }else{
                    cur = st.top();
                    st.pop();
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
            return res;
        }
    };

// 统一迭代法
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            if(root==NULL) return res;
            TreeNode* cur = root;
            st.push(cur);
            while(!st.empty()){
                cur = st.top();
                st.pop();
                if(cur){
                    if(cur->right) st.push(cur->right);
                    st.push(cur);
                    st.push(NULL);
                    if(cur->left) st.push(cur->left);
                }else{
                    res.push_back(st.top()->val);
                    st.pop();
                }
            }
            return res;
        }
    };