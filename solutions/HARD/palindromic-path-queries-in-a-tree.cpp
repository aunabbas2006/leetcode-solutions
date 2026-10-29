// Problem: Palindromic Path Queries in a Tree
// Difficulty: HARD
// Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
// Approach: Heavy-Light Decomposition with a segment tree on character bitmasks handles point updates and path XOR sum queries; a path forms a palindrome if its character XOR mask has zero or one bit set.

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up;
    vector<int> tin;
    vector<int> tout;
    vector<int> initial_path_mask_from_root;
    string current_s;
    int dfs_timer;
    vector<int> seg_tree_lazy;

    static const int LOGN = 17;

    void dfs(int u, int p, int d, int current_mask_val) {
        depth[u] = d;
        up[u][0] = p;
        initial_path_mask_from_root[u] = current_mask_val ^ (1 << (current_s[u] - 'a'));

        tin[u] = ++dfs_timer;

        for (int k = 1; k < LOGN; ++k) {
            if (up[u][k - 1] != -1) {
                up[u][k] = up[up[u][k - 1]][k - 1];
            } else {
                up[u][k] = -1;
            }
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1, initial_path_mask_from_root[u]);
        }
        tout[u] = dfs_timer;
    }

    int get_ancestor(int u, int k) {
        for (int i = 0; i < LOGN; ++i) {
            if ((k >> i) & 1) {
                u = up[u][i];
                if (u == -1) break;
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        u = get_ancestor(u, depth[u] - depth[v]);

        if (u == v) return u;

        for (int k = LOGN - 1; k >= 0; --k) {
            if (up[u][k] != -1 && up[v][k] != -1 && up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }

    void update_segment_tree(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) {
            return;
        }
        if (l <= start && end <= r) {
            seg_tree_lazy[node] ^= val;
            return;
        }
        int mid = start + (end - start) / 2;
        update_segment_tree(2 * node, start, mid, l, r, val);
        update_segment_tree(2 * node + 1, mid + 1, end, l, r, val);
    }

    int query_segment_tree(int node, int start, int end, int idx) {
        int res = seg_tree_lazy[node];
        if (start == end) {
            return res;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            res ^= query_segment_tree(2 * node, start, mid, idx);
        } else {
            res ^= query_segment_tree(2 * node + 1, mid + 1, end, idx);
        }
        return res;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOGN, -1));
        tin.assign(n, 0);
        tout.assign(n, 0);
        initial_path_mask_from_root.assign(n, 0);
        current_s = s;
        dfs_timer = 0;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, 0, 0);

        seg_tree_lazy.assign(4 * (n + 1), 0);

        vector<bool> result;
        for (const string& query_str : queries) {
            if (query_str[0] == 'u') {
                int ui = 0;
                char c_char;
                int i = 7;
                while (query_str[i] != ' ') {
                    ui = ui * 10 + (query_str[i] - '0');
                    i++;
                }
                c_char = query_str[i + 1];

                char s_old = current_s[ui];
                current_s[ui] = c_char;

                int delta_mask = (1 << (s_old - 'a')) ^ (1 << (c_char - 'a'));

                update_segment_tree(1, 1, n, tin[ui], tout[ui], delta_mask);
            } else {
                int ui = 0, vi = 0;
                int i = 6;
                while (query_str[i] != ' ') {
                    ui = ui * 10 + (query_str[i] - '0');
                    i++;
                }
                i++;
                while (i < query_str.length()) {
                    vi = vi * 10 + (query_str[i] - '0');
                    i++;
                }

                int L = lca(ui, vi);

                int mask_u = initial_path_mask_from_root[ui] ^ query_segment_tree(1, 1, n, tin[ui]);
                int mask_v = initial_path_mask_from_root[vi] ^ query_segment_tree(1, 1, n, tin[vi]);
                int mask_L = initial_path_mask_from_root[L] ^ query_segment_tree(1, 1, n, tin[L]);

                int path_total_mask = mask_u ^ mask_v ^ (1 << (current_s[L] - 'a'));

                bool is_palindrome = (path_total_mask == 0) || ((path_total_mask & (path_total_mask - 1)) == 0);
                result.push_back(is_palindrome);
            }
        }

        return result;
    }
};
