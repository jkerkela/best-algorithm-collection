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
    
    TreeNode* insertToBSTRecursive(TreeNode* node, int key) 
    { 
        if (node == NULL) return new TreeNode{key};

        if (key < node->val) 
            node->left  = insertToBSTRecursive(node->left, key); 
        else if (key > node->val) 
            node->right = insertToBSTRecursive(node->right, key);    

        return node; 
    } 
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertToBSTRecursive(root, val);
    }
};
