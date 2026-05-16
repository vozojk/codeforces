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
constexpr ll INF = 2*1e9;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
struct Node {
    ll suf;
    ll pref;
    ll sum;
    ll ans;
};
 
vector<Node> tr;
vector<int> nums;
int n,m, padded_n;
 
 
 
Node merge(Node& l, Node& r) {
    Node p{
        max(r.suf, r.sum+l.suf),
        max(l.pref, l.sum+r.pref),
        l.sum + r.sum,
        max({l.ans, r.ans, l.suf+r.pref})
    };
    return p;
}
 
void update(int idx, ll val) {
    idx += padded_n;
    tr[idx] = {max(0LL, val), max(0LL, val), val, max(0LL, val) };
 
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx] = merge(tr[idx << 1], tr[idx << 1 | 1]);
    }
}
 
void solve() {
    cin >> n >> m;
    padded_n = bit_ceil((unsigned int)n);
    nums.assign(2*padded_n, 0);
    tr.assign(2*padded_n, {0,0,0,0});
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        update(i, nums[i]);
    }
    int k,x;
    while (m--) {
        cin >> k >> x;
 
        update(k-1, x);
        cout << tr[1].ans << "\n";
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