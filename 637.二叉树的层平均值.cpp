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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> res;
            queue<TreeNode*> que;
            if(root==NULL) return res;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                // 注意sum不是int，否则除不出来小数
                double sum = 0;
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    sum += node->val;
                    que.pop();
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                res.push_back(sum / size);
            }
            return res;
        }
    };