/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void modifyBinaryTreeRecursively(TreeNode* node, int *sum) {
        
        if (node == NULL)  return; 
        modifyBinaryTreeRecursively(node->right, sum); 
        *sum = *sum + node->val;
        node->val = *sum;
        
        modifyBinaryTreeRecursively(node->left, sum);
        
    }
    
    void TransformBinarySearchTreeToGreaterSumTree(TreeNode* root) {
        int sum = 0; 
        modifyBinaryTreeRecursively(root, &sum); 
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        TransformBinarySearchTreeToGreaterSumTree(root);
        return root;
    }
};
