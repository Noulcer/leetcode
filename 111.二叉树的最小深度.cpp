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
    int minDepth(TreeNode* root) {
            int depth = 0;
            queue<TreeNode*> que;
            if(root==NULL) return depth;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    que.pop();
                    if(node->left==NULL && node->right==NULL) return depth+1;
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right) return minDepth(root->right)+1;
        if(root->left && root->right==NULL) return minDepth(root->left)+1;
        if(root->left==NULL && root->right==NULL) return 1;
        return min(minDepth(root->left), minDepth(root->right))+1;
        }
    };