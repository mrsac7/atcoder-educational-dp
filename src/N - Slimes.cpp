#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 1LL<<60;
int dp[405][405];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    int a[n+1];
    vector<vector<int>> dp(405, vector<int>(405, INF));
    vector<vector<int>> ans(405, vector<int>(405, INF));
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        dp[i][i] = a[i];
        ans[i][i] = 0;
    }

    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++) if (i+l <= n) 
            for (int k = i; k < i+l; k++) {
                int x = dp[i][k] + dp[k+1][i+l];
                int y = ans[i][k] + ans[k+1][i+l] + x;
                if (ans[i][i+l] > y) {
                    ans[i][i+l] = y;
                    dp[i][i+l] = x;
                }
            }

    cout<<ans[1][n];
}
