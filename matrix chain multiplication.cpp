#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    vector<int> p = {10, 20, 30, 40};

    int n = p.size() - 1;

    int dp[10][10] = {0};

    for (int len = 2; len <= n; len++) {

        for (int i = 1; i <= n - len + 1; i++) {

            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    cout << "Minimum Cost = " << dp[1][n];

    return 0;
}
