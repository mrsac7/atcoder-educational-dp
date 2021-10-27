#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e4 + 4;
int dp[mxN];

struct node {
    int x, y, z;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        v[i] = {x, y, z};
    }
    sort(v.begin(), v.end(), [&](node &i, node &j) {
        return i.x + i.y < j.x + j.y;
    });
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = v[i].y; j >= 0; j--) {
            if (dp[j] != -1) {
                dp[j + v[i].x] = max(dp[j + v[i].x], dp[j] + v[i].z);
            }
        }
    }
    cout << *max_element(dp, dp + mxN);
}