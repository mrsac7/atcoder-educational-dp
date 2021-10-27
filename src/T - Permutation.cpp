#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; string s; 
    cin >> n >> s;
    int dp[n+1][n+1]; memset(dp, 0, sizeof dp);
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        vector<int> temp(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            temp[j] = (dp[i-1][j] + temp[j-1]) % md;
        }
        for (int j = 1; j <= i; j++) {
            if (s[i-2] == '>') dp[i][j] = (temp[n] - temp[j-1] + md) % md;
            else dp[i][j] = temp[j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[n][i]) % md;
    cout << ans;
}