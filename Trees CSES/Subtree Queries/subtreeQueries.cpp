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
 
vector<int> in;
vector<int> out;
vector<int> nodes;
vector<ll> tr;
int n;
vector<vector<int>> edges;
int timer = 0;
 
void dfs(int node, int parent) {
    in[node]=timer;
    tr[timer+n] = nodes[node];
    timer++;
    for (int nei : edges[node]) {
        if (nei != parent) {
            dfs(nei, node);
        }
    }
    out[node]=timer;
}
 
ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)res += tr[l++];
        if (r & 1)res += tr[--r];
    }
    return res;
}
void update(int idx, int val) {
    int add = val-tr[idx+n];
    tr[idx+n]=val;
    idx += n;
    for (idx >>= 1; idx > 0; idx >>= 1) {
        tr[idx]+=add;
    }
}
void init() {
    for (int i = n - 1; i > 0; --i) {
        // Left child is at 2*i, Right child is at 2*i + 1
        tr[i] = tr[i << 1] + tr[i << 1 | 1];
 
    }
}
void solve() {
 
    int queries, a, b;
    cin >> n >> queries;
    in.assign(n,0);
    out.assign(n,0);
    nodes.assign(n, 0);
    edges.assign(n, vector<int>(0));
    tr.assign(2*n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    vector<int> visited(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(0, -1);
    init();
    while (queries--) {
        int type, idx, val;
        cin >> type;
        if (type==1) {
            cin >> idx >> val;
            idx--;
            update(in[idx], val);
        }else {
            cin >> idx;
            idx--;
            cout << query(in[idx], out[idx]) << "\n";
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