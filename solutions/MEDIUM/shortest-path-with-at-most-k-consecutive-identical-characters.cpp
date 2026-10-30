// Problem: Shortest Path With At Most K Consecutive Identical Characters
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
// Approach: Dijkstra's algorithm on an augmented state space where each state is defined by `(node, consecutive_count)`, representing the minimum path weight to `node` such that `labels[node]` is the `consecutive_count`-th identical character in sequence. Transitions update the `consecutive_count` based on whether the next node's label matches the current node's, pruning paths that exceed `k` consecutive identical characters.

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        
        
        
        unordered_map<long long, int> dist;

        
        
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       greater<tuple<int, int, int, int>>> pq;

        
        
        
        
        int k_plus_1 = k + 1; 
        long long label_idx_multiplier = k_plus_1;
        long long node_multiplier = 26LL * k_plus_1; 

        
        int start_node = 0;
        int start_label_idx = labels[0] - 'a';
        int start_consecutive_count = 1;

        
        long long start_state_key = (long long)start_node * node_multiplier +
                                    (long long)start_label_idx * label_idx_multiplier +
                                    start_consecutive_count;
        
        
        dist[start_state_key] = 0;
        pq.push({0, start_node, start_label_idx, start_consecutive_count});

        
        const int INF = 2147483647; 

        while (!pq.empty()) {
            auto [d, u, prev_label_idx, prev_count] = pq.top();
            pq.pop();

            
            long long current_state_key = (long long)u * node_multiplier +
                                         (long long)prev_label_idx * label_idx_multiplier +
                                         prev_count;

            
            
            if (dist.count(current_state_key) && d > dist[current_state_key]) {
                continue;
            }

            
            for (auto& edge_data : adj[u]) {
                int v = edge_data.first;
                int weight = edge_data.second;

                int current_label_idx = labels[v] - 'a';
                int new_consecutive_count;

                
                if (current_label_idx == prev_label_idx) {
                    new_consecutive_count = prev_count + 1;
                } else {
                    new_consecutive_count = 1;
                }

                
                if (new_consecutive_count > k) {
                    continue; 
                }

                int new_dist = d + weight;
                
                long long next_state_key = (long long)v * node_multiplier +
                                          (long long)current_label_idx * label_idx_multiplier +
                                          new_consecutive_count;

                
                
                if (!dist.count(next_state_key) || new_dist < dist[next_state_key]) {
                    dist[next_state_key] = new_dist;
                    pq.push({new_dist, v, current_label_idx, new_consecutive_count});
                }
            }
        }

        
        
        int final_min_total_weight = INF;
        for (int char_idx = 0; char_idx < 26; ++char_idx) {
            for (int count = 1; count <= k; ++count) {
                long long target_state_key = (long long)(n - 1) * node_multiplier +
                                             (long long)char_idx * label_idx_multiplier +
                                             count;
                if (dist.count(target_state_key)) {
                    final_min_total_weight = min(final_min_total_weight, dist[target_state_key]);
                }
            }
        }

        
        return (final_min_total_weight == INF) ? -1 : final_min_total_weight;
    }
};
