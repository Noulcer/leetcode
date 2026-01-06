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
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            traversal(root, res);
            return  res;
        }
        void traversal(TreeNode* node, vector<int>& res){
            if(node == NULL) return;
            res.push_back(node->val);
            traversal(node->left, res);
            traversal(node->right, res);
        }
    };

// 迭代法
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            while(!st.empty() || cur!=NULL){
                if(cur==NULL){
                    cur = st.top();
                    st.pop();
                }
                res.push_back(cur->val);
                if(cur->right) st.push(cur->right);
                cur = cur->left;
            }
            return  res;
        }
    };

// 统一迭代法
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> st;
            TreeNode* cur = root;
            // 防止空栈pop
            if(cur!=NULL) st.push(cur);
            while(!st.empty()){
                cur = st.top();
                st.pop();
                if(cur != NULL){
                    if(cur->right) st.push(cur->right);
                    if(cur->left) st.push(cur->left);
                    st.push(cur);
                    st.push(NULL);
                }else{
                    res.push_back(st.top()->val);
                    st.pop();
                }
            }
            return res;
        }
    };