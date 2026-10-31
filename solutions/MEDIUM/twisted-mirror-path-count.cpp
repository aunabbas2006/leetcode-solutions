// Problem: Twisted Mirror Path Count
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/twisted-mirror-path-count/
// Approach: Memoized depth-first search (DFS) counts paths, using a state of (row, col, last_move_direction) where 'last_move_direction' (right or down) determines the reflection behavior when entering a mirror cell. The total paths are the sum of paths from initial moves right and down from the start.

class Solution {
private:
    struct ReflectionResult {
        int r;
        int c;
        int dir; 
        bool valid;
        bool initialized; 
    };

    int M, N;
    vector<vector<int>> const* gridPtr;
    vector<vector<vector<ReflectionResult>>> memoReflection;
    const int MOD = 1e9 + 7;

    ReflectionResult getFinalDestinationMemo(int r, int c, int dir) {
        if (r < 0 || r >= M || c < 0 || c >= N) {
            return {-1, -1, -1, false, true}; 
        }

        if (memoReflection[r][c][dir].initialized) {
            return memoReflection[r][c][dir];
        }

        if ((*gridPtr)[r][c] == 0) {
            memoReflection[r][c][dir] = {r, c, dir, true, true};
            return memoReflection[r][c][dir];
        }

        
        int nextR = r;
        int nextC = c;
        int nextDir = dir;

        if (dir == 0) { 
            nextR++; 
            nextDir = 1; 
        } else { 
            nextC++; 
            nextDir = 0; 
        }

        ReflectionResult res = getFinalDestinationMemo(nextR, nextC, nextDir);
        
        memoReflection[r][c][dir] = res;
        return res;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        gridPtr = &grid;

        memoReflection.assign(M, vector<vector<ReflectionResult>>(N, vector<ReflectionResult>(2, {-1, -1, -1, false, false})));

        vector<vector<vector<long long>>> dp(M, vector<vector<long long>>(N, vector<long long>(2, 0)));

        
        
        int targetR_right = 0;
        int targetC_right = 1;
        if (targetC_right < N) {
            ReflectionResult res = getFinalDestinationMemo(targetR_right, targetC_right, 0);
            if (res.valid) {
                dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + 1) % MOD;
            }
        }

        
        int targetR_down = 1;
        int targetC_down = 0;
        if (targetR_down < M) {
            ReflectionResult res = getFinalDestinationMemo(targetR_down, targetC_down, 1);
            if (res.valid) {
                dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + 1) % MOD;
            }
        }

        
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                
                
                if (r == 0 && c == 0) {
                    continue;
                }

                
                if (dp[r][c][0] > 0) {
                    long long paths = dp[r][c][0];
                    
                    if (c + 1 < N) {
                        ReflectionResult res = getFinalDestinationMemo(r, c + 1, 0);
                        if (res.valid) {
                            dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + paths) % MOD;
                        }
                    }
                    
                    if (r + 1 < M) {
                        ReflectionResult res = getFinalDestinationMemo(r + 1, c, 1);
                        if (res.valid) {
                            dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + paths) % MOD;
                        }
                        
                    }
                }

                
                if (dp[r][c][1] > 0) {
                    long long paths = dp[r][c][1];
                    
                    if (c + 1 < N) {
                        ReflectionResult res = getFinalDestinationMemo(r, c + 1, 0);
                        if (res.valid) {
                            dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + paths) % MOD;
                        }
                    }
                    
                    if (r + 1 < M) {
                        ReflectionResult res = getFinalDestinationMemo(r + 1, c, 1);
                        if (res.valid) {
                            dp[res.r][res.c][res.dir] = (dp[res.r][res.c][res.dir] + paths) % MOD;
                        }
                    }
                }
            }
        }

        
        return (dp[M - 1][N - 1][0] + dp[M - 1][N - 1][1]) % MOD;
    }
};
