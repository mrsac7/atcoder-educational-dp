#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    double a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
   vector<vector<double>> dp(n+1, vector<double>(n, 0.0));
    dp[0][0] = 1 - a[0];
    dp[1][0] = a[0];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (i && j) dp[i][j] += dp[i-1][j-1]*a[j];     
            if (j) dp[i][j] += dp[i][j-1]*(1-a[j]);
        }
    }
    double ans = 0;
    for (int i = n/2+1; i <= n; i++)
        ans += dp[i][n-1];
    cout.precision(10);
    cout<<ans;
}