#include <bits/stdc++.h>
using namespace std;

class subsetCountWays {
public:
    int Solve(int i, int sum, vector<int>& arr, int target, vector<vector<int>>& dp) {
        
        // Base case
        if (i == arr.size()) {
            return (sum == target) ? 1 : 0;
        }

        // DP check
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int take = 0;

        // Take current element
        if (sum + arr[i] <= target) {
            take = Solve(i + 1, sum + arr[i], arr, target, dp);
        }

        // Not take
        int nonTake = Solve(i + 1, sum, arr, target, dp);

        return dp[i][sum] = take + nonTake;
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

    subsetCountWays obj;
    int result = obj.Solve(0, 0, arr, target, dp);

    cout << "Number of subsets: " << result << endl;

    return 0;
}