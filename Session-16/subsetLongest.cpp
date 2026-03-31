#include <bits/stdc++.h>
using namespace std;

class subsetLongest {
public:
    const int INF = 99999;

    // Function to reconstruct the longest subset
    vector<int> longest(vector<vector<int>>& dp, vector<int>& arr, int target) {
        vector<int> ans;
        int currentSum = 0;
        int i = 0;

        while (i < arr.size() && currentSum <= target) {
            int take = -INF;

            if (currentSum + arr[i] <= target) {
                take = 1 + dp[i + 1][currentSum + arr[i]];
            }

            int skip = dp[i + 1][currentSum];

            if (take >= skip && take > -INF) {
                ans.push_back(arr[i]);
                currentSum += arr[i];
            }
            i++;
        }

        return ans;
    }

    // DP function
    int solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp, int target) {
        if (i == arr.size()) {
            return (sum == target) ? 0 : -INF;
        }

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int take = -INF;

        if (sum + arr[i] <= target) {
            take = 1 + solve(i + 1, sum + arr[i], arr, dp, target);
        }

        int skip = solve(i + 1, sum, arr, dp, target);

        // same logic as Java ternary
        if (take > skip)
            return dp[i][sum] = take;
        else if (take == skip)
            return dp[i][sum] = take;
        else
            return dp[i][sum] = skip;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array of integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target value: ";
    cin >> target;

    // DP table initialized with -1
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    subsetLongest obj;

    int length = obj.solve(0, 0, arr, dp, target);
    cout << "Length of longest subset: " << length << endl;

    vector<int> result = obj.longest(dp, arr, target);

    cout << "Longest subset: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}