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
    int maxDepth(TreeNode* root) {
            int depth = 0;
            queue<TreeNode*> que;
            if(root==NULL) return depth;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                depth++;
            }
            return depth;
        }
    };

// 递归法
class Solution {
    public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
        }
    };