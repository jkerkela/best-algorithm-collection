/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        return traverseTreeLevelOrderBFS(root);
    }
    
    vector<vector<int>> traverseTreeLevelOrderBFS(Node* node) {
        vector<vector<int>> travelsalResult;
        if (node == NULL) {
            return travelsalResult;
        }
        vector<int> vNodes;
        queue<Node*> q;  
        q.push(node);
        while(!q.empty()) {
            int childNodes = q.size();
            while(childNodes > 0) {
                Node* currentNode = q.front();
                q.pop();
                vNodes.emplace_back(currentNode->val);
                for (int i=0; i < currentNode->children.size(); i++) {
                    Node* childOfcurrentNode = currentNode->children[i];
                    q.push(childOfcurrentNode);
                }
                childNodes--;
            }
            travelsalResult.emplace_back(vNodes);
            vNodes.clear();
        }
        return travelsalResult;
    }
};
