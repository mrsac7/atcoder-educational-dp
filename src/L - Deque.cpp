#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int a[n+1] = {0};
    int pre[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        dp[i][i] = a[i];
    }
    for (int d = 1; d < n; d++) {
        for (int i = 1; i <= n; i++) if (i + d <= n) {
            dp[i][i+d] = pre[i+d] - pre[i-1] - min(dp[i+1][i+d], dp[i][i+d-1]);
        }
    }
    int ans = dp[1][n];
    if (n > 1) ans -= min(dp[2][n], dp[1][n-1]);
    cout<<ans;
}