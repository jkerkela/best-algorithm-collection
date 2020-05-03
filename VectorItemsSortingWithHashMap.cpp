class Solution {
public:
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, unordered_map<string, int>> orders_per_table;
        set<string> food_types_ordered;
        for(auto& order : orders) {
            orders_per_table[order[1]][order[2]]++;
            food_types_ordered.insert(order[2]);
        } 
        
        vector<vector<string>> result_table;
        
        vector<string> header;
        header.push_back("Table");
        for(auto& food_type: food_types_ordered){
            header.push_back(food_type);
        }
        result_table.push_back(header);
        
        for(auto& order : orders_per_table) {
            vector<string> formated_orders;
            formated_orders.push_back(order.first);
            for(auto& food_type : food_types_ordered) {
                formated_orders.push_back(to_string(order.second[food_type]));
            }
            result_table.push_back(formated_orders);
        }
        
        sort(result_table.begin() + 1, result_table.end(), [](const vector<string>& vs1, const vector<string>& vs2){
            return stoi(vs1[0]) < stoi(vs2[0]);
        });
        
        return result_table;
    }
};
