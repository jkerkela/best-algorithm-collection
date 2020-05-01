class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        return resolve_shortest_path_over_grap_dijkstra(n, flights, src, dst, K);
    }
    
    
    int resolve_shortest_path_over_grap_dijkstra(int number_of_cities, vector<vector<int>>& flights, int source, int destination, int max_stops) {
        vector<vector<pair<int, int>>> nodes_graph_source_dest(number_of_cities);
        for (auto edge : flights) {
            int source_node = edge[0];
            int dest_node = edge[1];
            int cost = edge[2];
            nodes_graph_source_dest[source_node].push_back(make_pair(cost, dest_node));            
        }
        vector<pair<int,int>> total_cost_to_node_with_stops(number_of_cities, {INT_MAX, INT_MAX});
        priority_queue<pair<int,int>> cost_to_node;
        total_cost_to_node_with_stops[source] = {0, -1};
        cost_to_node.push({0, source});
        while (!cost_to_node.empty()) {
            bool updated_connection_value = false;
            pair<int,int> current_node = cost_to_node.top();
            cost_to_node.pop();
            for (auto connected_node : nodes_graph_source_dest[current_node.second]) {
                pair<int, int> cost_on_path_with_stops = total_cost_to_node_with_stops[current_node.second];
                int total_cost_on_path = cost_on_path_with_stops.first + connected_node.first;
                int current_stops = cost_on_path_with_stops.second;
                if ((current_stops) < max_stops && total_cost_on_path < total_cost_to_node_with_stops[connected_node.second].first) {
                    total_cost_to_node_with_stops[connected_node.second] = {total_cost_on_path, current_stops + 1};
                    cost_to_node.push(make_pair(total_cost_on_path, connected_node.second));
                }
            }
        }
        
        int cheapest_cost = total_cost_to_node_with_stops[destination].first;
        if (cheapest_cost != INT_MAX) {
            return cheapest_cost;
        }
        return -1;   
    }
};
