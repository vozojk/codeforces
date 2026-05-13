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
 
vector<int> tr;
vector<int> nums;
int n;
 
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res ^= tr[l++];
        if (r & 1) res ^= tr[--r];
    }
    return res;
}
void init (){
    for (int i = 0; i < n; i++) {
        tr[i+n]=nums[i];
    }
    for (int i = n-1; i > 0; --i) {
        tr[i] = tr[i << 1] ^ tr[i << 1 | 1];
    }
}
void update (int idx, int val) {
    idx+=n;
    tr[idx]=val;
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx] = tr[idx << 1] ^ tr[idx << 1 | 1];
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
        cin >> a >> b;
        a--;
        cout << query(a, b) << "\n";
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