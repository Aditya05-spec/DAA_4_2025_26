#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = cost;  // clone

            for (auto &curr : flights) {
                int u = curr[0];
                int v = curr[1];
                int w = curr[2];

                if (cost[u] != INT_MAX && cost[u] + w < temp[v]) {
                    temp[v] = cost[u] + w;
                }
            }

            cost = temp;
        }

        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }
};