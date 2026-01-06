#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            traversal(root, res);
            return  res;
        }
        void traversal(TreeNode* node, vector<int>& res){
            if(node == NULL) return;
            traversal(node->left, res);
            traversal(node->right, res);
            res.push_back(node->val);
        }
    };

// 迭代法 
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while(!st.empty() || cur!=NULL){
                if(cur == NULL){
                    cur = st.top();
                    st.pop();
                }
                res.push_back(cur->val);
                if(cur->left) st.push(cur->left);
                cur = cur->right;
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };

// 统一迭代法
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            if(root==NULL) return res;
            TreeNode* cur = root;
            st.push(cur);
            while(!st.empty()){
                cur = st.top();
                st.pop();
                if(cur){
                    st.push(cur);
                    st.push(NULL);
                    if(cur->right) st.push(cur->right);
                    if(cur->left) st.push(cur->left);
                }else{
                    res.push_back(st.top()->val);
                    st.pop();
                }
            }
            return res;
        }
    };