#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int dp[10005][2][100];
const int md = 1e9+7;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin>>s;
    int k; cin>>k;
    int n = s.size();
    dp[n][0][0] = dp[n][1][0] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int mod = 0; mod < k; mod++) {
            for (int d = 0; d < 10; d++) {
                int new_mod = ((mod - d) % k + k)%k;
                (dp[i][0][mod] += dp[i+1][0][new_mod])%=md;
            }
            for (int d = 0; d <= s[i] - '0'; d++) {
                int new_mod = ((mod-d)%k+k)%k;
                (dp[i][1][mod] += 
                (d == s[i]-'0') ? dp[i+1][1][new_mod] : dp[i+1][0][new_mod])%=md;
            }
        }
    }
    cout<<(dp[0][1][0] - 1 + md)%md; //exclude 0
}