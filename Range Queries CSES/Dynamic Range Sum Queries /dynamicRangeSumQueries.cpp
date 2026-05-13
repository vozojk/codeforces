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
constexpr ll INF = 1e10;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
vector<ll> tr;
vector<int> nums;
int n;
 
ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += tr[l++];
        if (r & 1) res += tr[--r];
    }
    return res;
}
void init (){
    for (int i = 0; i < n; i++) {
        int idx = i;
        for (idx += n; idx > 0; idx >>= 1) {
            tr[idx]+=nums[i];
        }
    }
}
void update (int idx, ll val) {
    ll delta = val - tr[idx+n];
    tr[idx+n] = val;
    idx += n;
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx] += delta;
    }
}
 
void solve() {
 
    int q,a,b;
    cin >> n >> q;
    nums.assign(n,0);
    tr.assign(2*n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
 
    init();
 
    while (q--) {
        int c;
        cin >> a >> b >> c;
        b--;
        if (a==1) {
            update(b, c);
        }else {
            cout << query(b, c) << "\n";
        }
 
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