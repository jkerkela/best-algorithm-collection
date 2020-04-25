class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        return resolve_shortest_path_over_grap_dijkstra(times, N, K);
        
    }
    
    int resolve_shortest_path_over_grap_dijkstra(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> nodes_graph_source_dest(N+1);
        for (auto edge : times) {
            int source_node = edge[0];
            int dest_node = edge[1];
            int cost = edge[2];
            nodes_graph_source_dest[source_node].push_back(make_pair(cost, dest_node));            
        }
        
        vector<int> current_total_cost_to_node(N+1, INT_MAX);
        priority_queue<pair<int,int>> prio_q_cost_node;
        current_total_cost_to_node[K] = 0;
        prio_q_cost_node.push(make_pair(0, K));
        while (!prio_q_cost_node.empty()) {
            pair<int,int> current_node = prio_q_cost_node.top();
            prio_q_cost_node.pop();
            for (auto adjacent_node : nodes_graph_source_dest[current_node.second]) {
                int total_cost_on_path = current_total_cost_to_node[current_node.second] + adjacent_node.first;
                if (total_cost_on_path < current_total_cost_to_node[adjacent_node.second]) {
                    current_total_cost_to_node[adjacent_node.second] = total_cost_on_path;
                    prio_q_cost_node.push(make_pair(total_cost_on_path, adjacent_node.second));
                }
            }            
        }        
        int max_time = INT_MIN;
        for (int i = 1; i < current_total_cost_to_node.size(); ++i) {
            if (max_time < current_total_cost_to_node[i]) {
                max_time = current_total_cost_to_node[i];
            }
        }
        
        return max_time == INT_MAX? -1 : max_time;
    }
};
