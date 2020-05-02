/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        return balanceBSTWithInorderTraversing(root);
    }
    
    TreeNode* balanceBSTWithInorderTraversing(TreeNode* root) {
        if (root == nullptr) { return nullptr;}
        vector<TreeNode*> nodes;
        storeNodesInOrderTraverse(root, nodes);
        int node_count = nodes.size();
        return buildBSTRecursiveFrom(nodes, 0, node_count - 1);
    }
    
    void storeNodesInOrderTraverse(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node==nullptr) {
            return;
        }
        storeNodesInOrderTraverse(node->left, nodes);
        nodes.push_back(node);
        storeNodesInOrderTraverse(node->right, nodes);
    }
    
    TreeNode* buildBSTRecursiveFrom(vector<TreeNode*>& nodes, int start_pos, int end_pos) {
        if (start_pos > end_pos) { return nullptr; }
        int parent_node_location = (start_pos + end_pos) / 2;
        TreeNode* parent = nodes[parent_node_location];
        parent->left = buildBSTRecursiveFrom(nodes, start_pos, parent_node_location - 1);
        parent->right = buildBSTRecursiveFrom(nodes, parent_node_location + 1, end_pos);
        
        return parent;
    }
};
