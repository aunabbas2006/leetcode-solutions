// Problem: Make Lexicographically Smallest Array by Swapping Elements
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Approach: Identify connected components of indices where elements can be mutually swapped, by first sorting the numbers with their original indices and then using a Disjoint Set Union (DSU) structure to connect adjacent elements that are within the `limit` difference. For each connected component, collect its original values and original indices, sort both lists, and then assign the sorted values to the sorted original indices in the result array.

class Solution {
private:
    class DSU {
        vector<int> parent;
        vector<int> sz; 

    public:
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i; 
            }
            sz.assign(n, 1);
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (sz[root_i] < sz[root_j])
                    swap(root_i, root_j);
                parent[root_j] = root_i;
                sz[root_i] += sz[root_j];
            }
        }
    };

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }

        sort(indexed_nums.begin(), indexed_nums.end());

        DSU dsu(n);

        for (int i = 0; i < n - 1; ++i) {
            if (indexed_nums[i+1].first - indexed_nums[i].first <= limit) {
                dsu.unite(indexed_nums[i].second, indexed_nums[i+1].second);
            }
        }

        map<int, vector<int>> component_values;
        map<int, vector<int>> component_indices;

        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            component_values[root].push_back(nums[i]);
            component_indices[root].push_back(i);
        }

        vector<int> ans(n);
        for (auto& entry : component_values) {
            int root = entry.first;
            
            vector<int>& current_values = entry.second;
            vector<int>& current_indices = component_indices[root];

            sort(current_values.begin(), current_values.end());
            sort(current_indices.begin(), current_indices.end());

            for (int j = 0; j < current_values.size(); ++j) {
                ans[current_indices[j]] = current_values[j];
            }
        }

        return ans;
    }
};
