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
 
int n;
vector<ll> seg;
 
void update(int i, long long val) {
    // Jump to the leaf (p + n), and keep moving to the parent (p >>= 1)
    for (i += n; i > 0; i >>= 1) {
        seg[i] = (seg[i] + val) % MOD;
    }
}
 
ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)res = (res + seg[l++])%MOD;
        if (r & 1)res = (res + seg[--r])%MOD;
    }
    return res;
}
 
void solve() {
 
    //stores amount of subsequences ending in the ith smallest number
    //take sum of all previous values through segment tree
    //go in correct order but use ranking for the segment tree ranges
 
    cin >> n;
    seg.assign(2*n, 0);
    vector<int> nums(n);
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sorted[i]=nums[i];
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int i = 0; i < n; i++) {
        int val = nums[i];
        int rank = lower_bound(sorted.begin(), sorted.end(), val)-sorted.begin();
 
        ll count = 0;
        if (rank > 0) {
            count = query(0, rank);
        }
        update(rank, (count+1)%MOD);
    }
    cout << query(0, n);
 
 
 
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