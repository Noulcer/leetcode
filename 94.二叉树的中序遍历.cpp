#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

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

