#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            queue<TreeNode*> que;
            if(root==NULL) return res;
            que.push(root);
            while(!que.empty()){
                // que.size是不断变化的，单层的size需要一个单独的变量
                int size = que.size();
                vector<int> res_layer;
                for(int i=0;i<size;i++){
                    TreeNode* node = que.front();
                    res_layer.push_back(node->val);
                    que.pop();
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                res.push_back(res_layer);
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };


class Solution {
    public:
        void order(TreeNode* node, vector<vector<int>>& res, int depth){
            if(node==NULL) return;
            // 保证不会越界，适时扩大容器
            if(res.size()==depth) res.push_back(vector<int>());
            res[depth].push_back(node->val);
            order(node->left, res, depth+1);
            order(node->right, res, depth+1);
        }
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            order(root, res, 0);
            reverse(res.begin(), res.end());
            return res;
        }
    };