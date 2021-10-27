#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9 + 7, mxN = 2e6+6;
int F[mxN], I[mxN];

int exp(int x, int y, int md){
    int ans = 1;
    x = x%md;
    while (y > 0) {
        if (y&1)
            ans = ans*x%md;
        y = y>>1;
        x = x*x%md;
    }
    return ans;
}

int C(int n, int k) {
    if (k > n) return 0;
    return F[n] * I[k] % md * I[n - k] % md;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    F[0] = 1, I[0] = 1;
    for (int i = 1; i < mxN; i++) {
        F[i] = i * F[i - 1] % md;
        I[i] = exp(F[i], md - 2, md);
    }

    int n, m, k; cin >> n >> m >> k;
    int dp[k + 2]; memset(dp, 0, sizeof dp);
    vector<pair<int, int>> v(k);
    for (auto &[i, j]: v) {
        cin >> i >> j;
        i--, j--;
    }

    v.push_back({n-1, m-1});
    sort(v.begin(), v.end());

    for (int i = 0; i <= k; i++) {
        auto [x, y] = v[i];
        dp[i] = C(x + y, x);

        for (int j = 0; j < i; j++) {
            auto [xx, yy] = v[j];
            if (yy > y) continue;
            dp[i] = (dp[i] - dp[j] * C(x + y - xx - yy, x - xx) % md + md) % md;
        }
    }
    cout << dp[k];
}