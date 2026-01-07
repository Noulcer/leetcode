#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            queue<TreeNode*> que;
            if(root==NULL) return res;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    if(i+1==size) res.push_back(node->val);
                    que.pop();
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
            }
            return res;
        }
    };