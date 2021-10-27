#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e5 + 5;
int md, dp[mxN], A[mxN];
vector<int> G[mxN];

void dfs(int s, int p = -1) {
    int x = 1;
    for (auto i: G[s]) if (i != p) {
        dfs(i, s);
        x = x * dp[i] % md;
    }
    dp[s] = (x + 1) % md;
}

void reroot(int s, int p = -1) {
    A[s] = (dp[s] - 1 + md) % md;
    int n = G[s].size();
    vector<int> P(n + 1, 1), S(n + 2, 1);
    for (int i = 0; i < n; i++) {
        P[i+1] = P[i] * dp[G[s][i]] % md;
        S[n-i] = S[n-i+1] * dp[G[s][n-i-1]] % md;
    }
    for (int i = 0; i < n; i++) if (G[s][i] != p) {
        int x = dp[G[s][i]], y = dp[s];
        dp[s] = (P[i] * S[i+2] % md + 1) % md;
        dp[G[s][i]] = (x - 1 + md) % md * dp[s] % md;
        dp[G[s][i]] = (dp[G[s][i]] + 1) % md;
        reroot(G[s][i], s);
        dp[G[s][i]] = x;
        dp[s] = y;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n >> md;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    reroot(1);
    for (int i = 1; i <= n; i++)
        cout << A[i] << endl;
}