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
 
vector<int> seg;
int n;
void update(int i, int val) {
    for (seg[i += n] = val; i > 1; i >>= 1) {
        seg[i >> 1] = max(seg[i], seg[i ^ 1]);
    }
}
 
int query (int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l>>=1, r>>=1) {
        if (l & 1)res = max(res, seg[l++]);
        if (r & 1)res = max(res, seg[--r]);
    }
    return res;
}
 
void solve(){
 
    cin >> n;
    vector<pair<int,int>> he(n);
    vector<int> dp(n+1,0);
    for (int i = 0; i < n; i++) {
        cin >> he[i].first;
        he[i].second = -i;
    }
    sort(he.begin(), he.end());
    vector<int> ranked(n);
    for (int i = 0; i < n; i++) {
        ranked[i]=-he[i].second;
    }
    int a = 0;
    seg.assign(2*n, 0);
    for (int i = 0; i < n; i++) {
        int c = query(0, ranked[i])+1;
        update(ranked[i], c);
        a = max(a,c);
    }
    cout << a;
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