#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,m; cin>>n>>m;
    vector<string> grid(n);
    for (auto &i: grid)
        cin>>i;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (grid[i][j] == '.') {
            if (i+1 < n && grid[i+1][j] == '.') (dp[i+1][j] += dp[i][j])%=md;
            if (j+1 < m && grid[i][j+1] == '.') (dp[i][j+1] += dp[i][j])%=md;
        }
    }
    cout<<dp[n-1][m-1];
}