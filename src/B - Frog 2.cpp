#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 1LL<<60;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,k; cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) if (i-j >= 0){
            dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
        }
    }
    cout<<dp[n-1];
}