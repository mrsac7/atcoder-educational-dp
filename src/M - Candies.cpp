#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,k; cin>>n>>k;
    int a[n+1];
    for (int i = 1; i <= n; i++)
        cin>>a[i];

    vector<int> dp(100005, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> pre(100005, 0);
        for (int j = 0; j <= k; j++) {
            pre[j+1] = (pre[j] + dp[j])%md;
        }
        vector<int> temp(100005, 0);
        temp[0] = 1;
        for (int j = 1; j <= k; j++) {
            int l = max(0LL, j-a[i]);
            temp[j] = (pre[j+1] - pre[l] + md)%md;
        }
        dp = temp;
    }
    cout<<dp[k];
}