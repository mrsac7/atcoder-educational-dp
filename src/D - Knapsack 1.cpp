#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,w; cin>>n>>w;
    vector<vector<int>> dp(w+1, vector<int>(n+1, 0));
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin>>a[i]>>b[i];

    int ans = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if (i - a[j-1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-a[j-1]][j-1] + b[j-1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
}