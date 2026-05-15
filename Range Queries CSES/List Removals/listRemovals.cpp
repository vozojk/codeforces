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
int n, padded_n;
 
void update(int idx, int val) {
    idx += padded_n;
    tr[idx] = val;
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx]=tr[idx << 1] + tr[idx << 1 | 1];
    }
}
int query(int idx) {
    int res = 0;
    for (idx += padded_n; idx > 0; idx >>= 1) {
        res += tr[idx];
    }
    return res;
}
 
void solve() {
    int a;
    cin >> n;
    padded_n = bit_ceil((unsigned int)n);
    tr.assign(2*padded_n, 0);
 
    vector<int> vals(n+1);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        update(i, 1);
    }
 
 
    for (int i = 0; i < n; i++) {
        cin >> a;
        int node = 1;
        while (node < padded_n) {
            if (tr[node << 1] >= a) {
                node = node << 1;
            }else {
                a -= tr[node << 1];
                node = node << 1 | 1;
            }
        }
        int idx = node - padded_n;
        update(idx, 0);
        cout << vals[idx] << " ";
 
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