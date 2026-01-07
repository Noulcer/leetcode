#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x): val(x), left(NULL), right(NULL), next(NULL) {};
};

class Solution {
    public:
        Node* connect(Node* root) {
            queue<Node*> que;
            if(root==NULL) return root;
            que.push(root);
            while(!que.empty()){
                int size = que.size();
                for(int i=0;i<size;i++){
                    Node* node = que.front();
                    que.pop();
                    if(i+1==size) {
                        node->next = NULL;
                    }else{
                        node->next = que.front();
                    }
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
            }
            return root;
        }
    };