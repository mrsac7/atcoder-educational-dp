#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
const int md = 1e9+7;
vector<int> adj[mxN];

int dp[mxN][2];

void dfs(int s, int p = 0) {
    dp[s][0] = 1;
    dp[s][1] = 1;
    for (auto i: adj[s]) {
        if (i != p) {
            dfs(i, s);
            (dp[s][0] *= (dp[i][0] + dp[i][1])) %= md;
            (dp[s][1] *= dp[i][0]) %= md;
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    for (int i = 1; i < n; i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout<<(dp[1][0] + dp[1][1]) %md;
}