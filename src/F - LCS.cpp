#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    string ans;
    int i = n, j = m;
    while (i && j) {
        if (s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--, j--;
        }
        else if (dp[i][j-1] >= dp[i-1][j]) {
            j--;
        }
        else i--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}