#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5+5;
vector<int> adj[mxN];

vector<int> ts;
int vis[mxN];

void dfs(int x) {
    vis[x] = 1;
    for (auto i: adj[x])
        if (!vis[i])
            dfs(i);
    ts.push_back(x);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) if (!vis[i])
        dfs(i);

    vector<int> dp(n+1, 0);
    reverse(ts.begin(), ts.end());
    for (auto i: ts) {
        for (auto j: adj[i])
            dp[j] = max(dp[j], dp[i] + 1);
    }
    cout<<*max_element(dp.begin(), dp.end());
}