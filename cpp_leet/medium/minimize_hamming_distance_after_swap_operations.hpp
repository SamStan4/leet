#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
private:
    static void get_connected_nodes(const std::vector<int>& source,
                                    const std::vector<int>& target,
                                    const std::unordered_map<int, std::vector<int>>& adjacency_matrix,
                                    std::unordered_set<int>& visited,
                                    std::unordered_map<int, int>& connected_source_node_values,
                                    std::unordered_map<int, int>& connected_target_node_values,
                                    const int cur_idx) {

        // Ensure that we have not yet been here.
        if (visited.find(cur_idx) != visited.end()) {
            return;
        }

        // Sanity check, we should not call this function if cur_idx is not a key in the adjacency matrix.
        if (adjacency_matrix.find(cur_idx) == adjacency_matrix.end()) {
            return;
        }

        // Mark the node as visited.
        visited.insert(cur_idx);

        // Update the connected node value trackers.
        ++connected_source_node_values[source[cur_idx]];
        ++connected_target_node_values[target[cur_idx]];

        // Search.
        for (const int adjacent_node : adjacency_matrix.at(cur_idx)) {
            Solution::get_connected_nodes(source,
                                          target,
                                          adjacency_matrix,
                                          visited,
                                          connected_source_node_values,
                                          connected_target_node_values,
                                          adjacent_node);
        }
    }

    static int compute_distance_between_maps(const std::unordered_map<int, int>& mp_one,
                                             const std::unordered_map<int, int>& mp_two) {

        int total_elements = 0;
        int total_common_elements = 0;

        for (const std::pair<int, int>& key_value : mp_one) {
            total_elements += key_value.second;
            if (mp_two.find(key_value.first) != mp_two.end()) {
                total_common_elements += std::min(key_value.second, mp_two.at(key_value.first));
            }
        }

        return total_elements - total_common_elements;
    }
public:
    static int minimumHammingDistance(std::vector<int>& source, 
                                      std::vector<int>& target,
                                      std::vector<std::vector<int>>& allowed_swaps) {

        const int n = static_cast<int>(source.size());

        std::unordered_map<int, std::vector<int>> adjacency_matrix;
        
        // Build the adjacency matrix here.
        for (const std::vector<int>& swap : allowed_swaps) {
            
            const int a = swap[0];
            const int b = swap[1];

            adjacency_matrix[a].push_back(b);
            adjacency_matrix[b].push_back(a);
        }

        std::unordered_set<int> visited;

        int total_hamming_distance = 0;

        for (int i = 0; i < n; ++i) {
            if (adjacency_matrix.find(i) == adjacency_matrix.end()) {
                total_hamming_distance += source[i] == target[i] ? 0 : 1;
                continue;
            }

            std::unordered_map<int, int> connected_source_node_values;
            std::unordered_map<int, int> connected_target_node_values;

            Solution::get_connected_nodes(source,
                                          target,
                                          adjacency_matrix,
                                          visited,
                                          connected_source_node_values,
                                          connected_target_node_values,
                                          i);

            total_hamming_distance += Solution::compute_distance_between_maps(connected_source_node_values,
                                                                              connected_target_node_values);
        }

        return total_hamming_distance;
    }
};