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
    //to, from, weight, index
    auto cmp = [](tuple<int,int,int> a, int b) {
        return get<0>(a)<b;
    };
    int n, a, b, c;
    cin >> n;
    vector<tuple<int,int,int>> proj(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        proj[i] = {b,a,c};
    }
    sort(proj.begin(), proj.end());
    vector<ll> dp(n+1, 0);
 
    for (int i = 1; i <= n; i++) {
        auto k = lower_bound(proj.begin(), proj.begin()+i, get<1>(proj[i]), cmp);
        int lower = k-proj.begin();
        dp[i]=max(dp[lower-1]+get<2>(proj[i]), dp[i-1]);
    }
    cout << dp[n];
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