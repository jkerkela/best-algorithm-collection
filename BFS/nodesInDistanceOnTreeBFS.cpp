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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        return findNodeValuesForTargetForDistance(root, target, K);
    }
    
    
    vector<int> findNodeValuesForTargetForDistance(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent_node_graph;
        unordered_map<TreeNode*, bool> visited;
        
        buildNodeGraphFromTree(parent_node_graph, root);
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int current_level = 0;
        TreeNode* current_node;
        while(!q.empty()) {
            if (current_level++ == K) break;
            int layer_size = q.size();
            for(int i = 0; i < layer_size; i++) {
                current_node = q.front();
                q.pop();
                if(current_node->left && !visited[current_node->left]) {
                q.push(current_node->left);
                visited[current_node->left] = true;
                }
                if(current_node->right && !visited[current_node->right]) {
                    q.push(current_node->right);
                    visited[current_node->right] = true;
                }
                if(parent_node_graph[current_node] && !visited[parent_node_graph[current_node]]) {
                    q.push(parent_node_graph[current_node]);
                    visited[parent_node_graph[current_node]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()) {
            TreeNode* current_node = q.front(); 
            q.pop();
            result.push_back(current_node->val);
        }
        return result;
        
    }
    
    void buildNodeGraphFromTree(unordered_map<TreeNode*, TreeNode*>& parent_node_graph, TreeNode* node) {
        if (node == NULL) return;
        if(node->left) {
            parent_node_graph[node->left] = node;
        }
        if(node->right) {
            parent_node_graph[node->right] = node;
        }
        buildNodeGraphFromTree(parent_node_graph, node->left);
        buildNodeGraphFromTree(parent_node_graph, node->right);
    }
    
};
