#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;
int dp[(1LL<<21) + 5];

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    }
    dp[0] = 1;
    for (int s = 0; s < 1<<n; s++) {
        int i = __builtin_popcount(s);
        for (int j = 0; j < n; j++) {
            if (adj[i][j] && !(s&(1<<j))) {
                (dp[s | (1<<j)] += dp[s]) %=md;
            }
        }
    }
    cout << dp[(1LL<<n) - 1];
}