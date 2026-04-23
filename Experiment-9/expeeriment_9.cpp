#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(int arr[], int n) {
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            for(int j = totalSum; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        int mini = INT_MAX;

        for(int s1 = 0; s1 <= totalSum / 2; s1++) {
            if(dp[s1]) {
                mini = min(mini, totalSum - 2 * s1);
            }
        }

        return mini;
    }
};