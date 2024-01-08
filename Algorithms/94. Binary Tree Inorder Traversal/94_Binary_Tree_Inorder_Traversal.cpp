 class Solution {
 public:
     void binaryTree(TreeNode* root, vector<int> &v) {
         
         if (root != nullptr){
             binaryTree(root->left, v);
             v.push_back(root->val);
             binaryTree(root->right, v);
       
         }
     }

     vector<int> inorderTraversal(TreeNode* root) {
         vector<int> v;
         binaryTree(root, v);
         return v;
     }
 };
