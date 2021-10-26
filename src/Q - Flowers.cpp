#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 1e6+6;
int seg[2*mxN], N;

void update(int k, int x) {
    k += N; seg[k] = x; k >>= 1;
    while (k > 0) {
        seg[k] = max(seg[2*k], seg[2*k+1]);
        k >>= 1;
    }
}

int query(int a, int b) {
    a += N, b += N;
    int s = 0;
    while (a <= b) {
        if (a&1) s = max(s, seg[a++]);
        if (b&1^1) s = max(s, seg[b--]);
        a >>= 1, b >>= 1;
    }
    return s;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    N = 1LL<< (int) ceil(log2(n));
    vector<int> a(n), b(n);
    for (auto &i: a)
        cin >> i;
    for (auto &i: b)
        cin >> i;
    
    int ans = b[0];
    update(a[0]-1, b[0]);
    for (int i = 1; i < n; i++) {
        int x = b[i] + query(0, a[i]-1);
        ans = max(ans, x);
        update(a[i]-1, x);
    }
    cout << ans;
}