#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            vector<int> res;
            queue<TreeNode*> que;
            if(root==NULL) return res;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                int max = que.front()->val;
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->val>max) max = node->val;
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                res.push_back(max);
            }
            return res;
        }
    };