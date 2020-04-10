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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return findLowestCommonParentOFDeepestLeaves(root);
    }
    
    
    TreeNode* findLowestCommonParentOFDeepestLeaves(TreeNode* node) {
        if (!node) {
            return NULL;
        }
        
        int depthOfLeftTree = getDepthOfTree(node->left, 0);
        int depthOfRightTree = getDepthOfTree(node->right, 0);
        if (depthOfLeftTree == depthOfRightTree) {
            return node;
        }
        else if (depthOfLeftTree > depthOfRightTree) {
            return findLowestCommonParentOFDeepestLeaves(node->left);
        }
        else {
            return findLowestCommonParentOFDeepestLeaves(node->right);
        }
    }
    
    int getDepthOfTree(TreeNode* node, int currentDepth){
        if(!node) {
            return currentDepth - 1;
        }
        return max(getDepthOfTree(node->left, currentDepth + 1), getDepthOfTree(node->right, currentDepth + 1));
    }
    
};
