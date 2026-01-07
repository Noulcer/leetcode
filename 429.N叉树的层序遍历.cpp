#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    Node(int x): val(x) {};
};


class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> res;
            queue<Node*> que;
            if(root==NULL) return res;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                vector<int> res_layer;
                for(int i=0;i<size;i++){
                    Node* node = que.front();
                    res_layer.push_back(node->val);
                    que.pop();
                    for(int j=0;j<node->children.size();j++){
                        if(node->children[j]!=NULL) que.push(node->children[j]);
                    }
                }
                res.push_back(res_layer);
            }
            return res;
        }
    };