#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 305;
double dp[mxN][mxN][mxN];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin>>n;
    int a[4] = {0};
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        a[x]++;
    }
    for (int z = 0; z <= n; z++) {
        for (int y = 0; y <= n; y++) {
            for (int x = 0; x <= n; x++) if (x + y + z <= n) {
                double p0 = (n-(x+y+z))*1.0/n;
                double p1 = x*1.0/n;
                double p2 = y*1.0/n;
                double p3 = z*1.0/n;
                if (x + y + z == 0) continue;
                if (x > 0) dp[x][y][z] += p1*dp[x-1][y][z];
                if (y > 0) dp[x][y][z] += p2*dp[x+1][y-1][z];
                if (z > 0) dp[x][y][z] += p3*dp[x][y+1][z-1];
                dp[x][y][z] += 1.0;
                dp[x][y][z] /= (1 - p0);
            }
        }
    }
    cout.precision(10);
    cout<<dp[a[1]][a[2]][a[3]];
}