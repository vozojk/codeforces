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
vector<int> rooms;
int padded_n;
 
void update (int idx, int val) {
    idx += padded_n;
    tr[idx]=val;
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx] = max(tr[idx << 1], tr[idx << 1 | 1]);
    }
}
 
void solve() {
 
    int n,q,a;
    cin >> n >> q;
    padded_n = bit_ceil((unsigned int)n);
    vector<int> result(q, -1);
    rooms.assign(n+1,0);
    tr.assign(2*padded_n, 0);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
        update(i, rooms[i]);
    }
 
 
 
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (tr[1] < a) {
            result[i] = 0;
            continue;
        }
        int idx = 1;
        while (idx < padded_n) {
            if (tr[idx << 1] >= a) {
                idx <<= 1;
            }else {
                idx = (idx << 1 | 1);
            }
        }
        update(idx - padded_n, tr[idx] - a);
        result[i]=idx+1-padded_n;
    }
    for (int b : result)cout << b << " ";
 
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