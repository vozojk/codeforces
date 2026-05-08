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
 
 
void solve() {
 
    int n,q;
    cin >> n >> q;
    vector<int> boss(n);
    for (int i = 1; i < n; i++) {
        cin >> boss[i];
        boss[i]--;
    }
    vector<vector<int>> dp(n, vector<int>(20, -1));
    for (int i = 1; i < n; i++) {
        dp[i][0]=boss[i];
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][j-1]!=-1){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    while (q--) {
        int x,k;
        cin >> x >> k;
        x--;
        int levels = 0;
        int node = x;
        for (int i = 19; i >= 0; i--) {
            int num = (1 << i);
            if (num+levels>k || node == -1)continue;
            levels+=num;
            node = dp[node][i];
        }
        cout << (node == -1 ? node : node+1) << "\n";
    }
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