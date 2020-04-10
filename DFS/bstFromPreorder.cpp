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
    
    int searchNextBiggestElemFromIndexRangeTo(int val, vector<int>& preorder, int low, int high) {
        int i = 0;
        for (i = low; i <= high; ++i )  {
            if (preorder[i] > val) return i;
        }
        return i;
    }
    
    TreeNode* constructTreeFromPreOrd(vector<int>& preorder, int minIndex, int maxIndex) {
        
        if (minIndex > maxIndex) return NULL;  
        TreeNode* root = new TreeNode(preorder[minIndex]);  
        if (minIndex == maxIndex) return root;
        
        auto nextBiggestElemIndex = searchNextBiggestElemFromIndexRangeTo(root->val, preorder, minIndex, maxIndex);
        root->left = constructTreeFromPreOrd(preorder, minIndex + 1, nextBiggestElemIndex - 1);  
        root->right = constructTreeFromPreOrd(preorder, nextBiggestElemIndex, maxIndex);  
        return root;  
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        auto size = preorder.size();
        return constructTreeFromPreOrd(preorder, 0, size -1);
    }
};
