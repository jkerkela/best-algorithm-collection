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
    
    void deleteLeavesFromTreeRecursivelyPostOrder(TreeNode* parentNode, TreeNode* node, bool isLeftLeave, int target) {
        
        if(node == NULL) return;
        deleteLeavesFromTreeRecursivelyPostOrder(node, node->left, true, target);
        deleteLeavesFromTreeRecursivelyPostOrder(node, node->right, false, target);
        if (node->val == target && node->left == NULL && node->right == NULL && parentNode != node) {
            isLeftLeave ? parentNode->left = NULL : parentNode->right = NULL;
            delete (node);
        }
    }
    
    bool isRootNodeRemovable(TreeNode* root, int target) {
        return (!root->left && !root->right && root->val == target);
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        deleteLeavesFromTreeRecursivelyPostOrder(root, root, false, target);
        if(isRootNodeRemovable(root, target)){
            return NULL;
        }
        return root;
    }
};
