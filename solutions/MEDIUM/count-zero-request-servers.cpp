// Problem: Count Zero Request Servers
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-zero-request-servers/
// Approach: Sort logs by time and queries by their end times (keeping original indices). Use a two-pointer sliding window over the sorted logs, maintaining a hash map to count requests for each server within the current query's time interval and tracking the number of unique servers with requests.

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> queries_with_idx(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            queries_with_idx[i] = {queries[i], i};
        }
        sort(queries_with_idx.begin(), queries_with_idx.end());

        vector<int> ans(queries.size());
        map<int, int> server_request_counts;
        int distinct_active_servers = 0;
        int log_ptr_left = 0;
        int log_ptr_right = 0;

        for (auto const& query_entry : queries_with_idx) {
            int current_query_time = query_entry.first;
            int original_idx = query_entry.second;

            int window_start_time = current_query_time - x;
            int window_end_time = current_query_time;

            while (log_ptr_right < logs.size() && logs[log_ptr_right][1] <= window_end_time) {
                int server_id = logs[log_ptr_right][0];
                if (server_request_counts[server_id] == 0) {
                    distinct_active_servers++;
                }
                server_request_counts[server_id]++;
                log_ptr_right++;
            }

            while (log_ptr_left < logs.size() && logs[log_ptr_left][1] < window_start_time) {
                int server_id = logs[log_ptr_left][0];
                server_request_counts[server_id]--;
                if (server_request_counts[server_id] == 0) {
                    distinct_active_servers--;
                }
                log_ptr_left++;
            }
            
            ans[original_idx] = n - distinct_active_servers;
        }

        return ans;
    }
};
