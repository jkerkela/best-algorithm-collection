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
    vector<int> largestValues(TreeNode* root) {
        return findLargestValuesPerRowBFS(root);
    }
    
    vector<int> findLargestValuesPerRowBFS(TreeNode* node) {
        vector<int> largestValuesPerRow;
        if(node == NULL) {
            return largestValuesPerRow;
        }
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()) {
            int largestValueInCurrentRow = INT_MIN;
            int childNodes = q.size();
            while(childNodes > 0) {
                node = q.front();
                q.pop();
                largestValueInCurrentRow = max(largestValueInCurrentRow, node->val);
                if(node->left) {q.push(node->left);}
                if(node->right) {q.push(node->right);}
                childNodes--;
            }
            largestValuesPerRow.emplace_back(largestValueInCurrentRow);
        }
        return largestValuesPerRow;
    }
};
