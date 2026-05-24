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
 
inline int popcount(long long x) {
    return __builtin_popcountll(x);
}
 
void solve(){
    ll n;
    cin >> n;
    ll total = 0;
    for (int i = 0; i <= 50; i++) {
        ll cycles = (n+1)/(1ll << (i+1));
        ll b1s = cycles*(1ll<<i);
        ll remainder = (n+1)%(1ll << (i+1));
        b1s += max(0ll, remainder - (1ll << i));
 
        total += b1s;
    }
    cout << total << "\n";
 
 
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