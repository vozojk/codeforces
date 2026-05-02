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
    //Unique Sets, Single Use: Outer = Items, Inner = Backwards (0/1 Knapsack)
 
    int n;
    cin >> n;
    vector<int> c(n);
    vector<vector<ll>> dp(n, vector<ll>(n));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
        dp[i][i]=c[i];
    }
 
    for (int i = 1; i < n; i++) {
        int l = 0;
        int r = i;
        while (r<n) {
            dp[l][r]=max(c[l]-dp[l+1][r], c[r]-dp[l][r-1]);
            l++;
            r++;
        }
    }
    cout << (sum+dp[0][n-1])/2;
 
 
 
 
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