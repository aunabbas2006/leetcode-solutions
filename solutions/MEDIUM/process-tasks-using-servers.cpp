// Problem: Process Tasks Using Servers
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/process-tasks-using-servers/
// Approach: Simulate the task assignment process using two min-priority queues: one for available servers (ordered by weight, then index) and another for busy servers (ordered by their task completion time, then weight, then index). Iterate through tasks, advancing a current time pointer to manage server availability and assign tasks from the free server queue to the busy server queue.

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busy_servers;

        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        long long current_time = 0; 

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);

            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [free_t, w, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({w, idx});
            }

            if (free_servers.empty()) {
                auto [free_t, w, idx] = busy_servers.top();
                busy_servers.pop();
                
                current_time = free_t; 
                free_servers.push({w, idx}); 

                while (!busy_servers.empty() && get<0>(busy_servers.top()) == current_time) {
                    auto [free_t_other, w_other, idx_other] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({w_other, idx_other});
                }
            }

            auto [server_w, server_idx] = free_servers.top();
            free_servers.pop();

            ans[j] = server_idx;

            long long new_free_time = current_time + tasks[j];
            busy_servers.push({new_free_time, server_w, server_idx});
        }

        return ans;
    }
};
