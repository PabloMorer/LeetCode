#include<iostream>
#include<vector>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void leafs(TreeNode* root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(root->val);
        }
        else {
            leafs(root->left, v);
            leafs(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        leafs(root1, v1);
        leafs(root2, v2);

        int i = 0;
        if (v1.size() != v2.size()) {
            return false;
        }
        while (i < v1.size()) {
            if (v1[i] != v2[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};
