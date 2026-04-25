#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
 
 
// --- Type Aliases ---
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int, int>;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
#define dbg(x)
#endif
 
 
 
// --- Constants ---
const int MOD = 1e9+7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve() {
 
    int n,m,v1,v2;
    cin >> n >> m;
    vector<vector<int>> rEdges(n);
    vector<vector<ll>> dp((1 << n), vector<ll>(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        rEdges[v2-1].push_back(v1-1);
    }
    dp[1][0]=1;
    for (int mask = 2; mask < (1 << n); mask++) {
        if (mask & (1 << (n-1)) && mask != (1 << n)-1) continue;
 
        for (int u = 0; u < n; u++) {
 
            if ((mask & (1 << u)) == 0) continue;
            int past_mask = mask ^ (1 << u);
 
            for (int v : rEdges[u]) {
                if ((past_mask & (1 << v)) == 0)continue;
                dp[mask][u] = (dp[mask][u] + dp[past_mask][v])%MOD;
            }
        }
    }
    cout << dp[(1 << n)-1][n-1];
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    int t = 1;
    //cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
}