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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treeNodeFromPreAndInorders(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* treeNodeFromPreAndInorders(vector<int>& preorder, vector<int>& inorder, int preorderIndex, int inorderIndexStart, int inorderIndexEnd) {
        if (preorder.empty() || inorder.empty() || inorderIndexStart > inorderIndexEnd || preorderIndex >= preorder.size() || inorderIndexEnd >= inorder.size()) {
            return NULL;
        }
        auto node = new TreeNode(preorder[preorderIndex]);
        auto currentIndex = 0;
        for (int i = inorderIndexStart; i <= inorderIndexEnd; i++) {
            if (node->val == inorder[i]) {
                currentIndex = i;
            }
        }
        
        node->left = treeNodeFromPreAndInorders(preorder, inorder, preorderIndex + 1, inorderIndexStart, currentIndex - 1);
        node->right = treeNodeFromPreAndInorders(preorder, inorder, preorderIndex + currentIndex - inorderIndexStart + 1, currentIndex + 1, inorderIndexEnd);
        return node;
    }
};
