#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
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
//#define dbg(x)
#endif
 
 
 
// --- Constants ---
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e18;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve(){
 
    //go through masks adding a person if they are supposed to be there and recalculating state
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)cin >> w[i];
 
    vector<pair<int,int>> dp(1 << n, {1e6,0});
    dp[0]={1,0};
    for (int mask = 1; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            int we = w[i];
            if ((mask & 1 << i)==0)continue;
            int prev_mask = (mask ^ (1 << i));
            auto p = dp[prev_mask];
            if (p.second+we > x) {
                dp[mask]=min(dp[mask], {p.first+1, we});
            }else {
                dp[mask]=min(dp[mask], {p.first, p.second+we});
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
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