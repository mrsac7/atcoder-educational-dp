#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1 << 17;
int dp[mxN];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    int G[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    for (int mask = 1; mask < 1 << n; mask++) {
        for (int j = 0; j < n; j++) if (mask >> j & 1) {
            for (int i = j + 1; i < n; i++) if (mask >> i & 1) {
                dp[mask] += G[i][j];
            }
        }
    }
    for (int mask = 1; mask < 1 << n; mask++) {
        for (int s = mask; s > 0; s = (s - 1) & mask) {
            dp[mask] = max(dp[mask], dp[s] + dp[mask ^ s]);
        }
    }
    cout << dp[(1 << n) - 1];
}