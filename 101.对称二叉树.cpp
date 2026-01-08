#include <iostream>
#include <queue>

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
        bool check(TreeNode* lNode, TreeNode* rNode){
            // 稍微简洁的写法
            // if(lNode==NULL || rNode==NULL) return lNode == rNode; 
            if(lNode==NULL && rNode==NULL) return true;
            if(lNode==NULL || rNode==NULL) return false;
            return (lNode->val==rNode->val) && check(lNode->left, rNode->right) && check(lNode->right, rNode->left);
        }
        bool isSymmetric(TreeNode* root) {
            if(root) return check(root->left, root->right);
            return true;
        }
    };

// 迭代法 - 队列 - 按层比较
class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if(root==NULL) return true;
            queue<TreeNode*> que;
            que.push(root->left);
            que.push(root->right);
            while(!que.empty()){
                TreeNode* nodeL = que.front(); que.pop();
                TreeNode* nodeR = que.front(); que.pop();
                if(nodeL==NULL && nodeR==NULL) continue;
                if(nodeL==NULL || nodeR==NULL || (nodeL->val!=nodeR->val)) return false;
                que.push(nodeL->left); que.push(nodeR->right);
                que.push(nodeL->right); que.push(nodeR->left); 
            }
            return true;
        }
    };