#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    // winning - from a state, if any of reachable states is losing.
    // losing - from a state, if no reachable states are losing.
    int n, k; cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];

    vector<int> dp(k+1, 0);
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) if (i - a[j] >= 0) {
            if (dp[i - a[j]] == 0) dp[i] = 1;
        }
    }
    cout<<(dp[k]?"First":"Second");
}