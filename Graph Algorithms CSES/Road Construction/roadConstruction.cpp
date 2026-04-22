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
#define dbg(x)
#endif
 
 
 
// --- Constants ---
const int MOD = 1e9+7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
vector<int> parent;
vector<int> sz;
int find (int x) {
    if (parent[x]!=x) {
        return parent[x]=find(parent[x]);
    }
    return x;
}
 
bool unite(int x, int y) {
    int px = find(x);
    int py= find(y);
 
    if (py==px)return false;
    if (sz[px]>sz[py]) {
        sz[px]+=sz[py];
        parent[py]=px;
    }else {
        sz[py]+=sz[px];
        parent[px]=py;
    }
    return true;
 
}
 
void solve() {
    int n,m;
    cin >> n >> m;
 
    parent = vector<int>(n+1);
    sz = vector<int>(n+1, 1);
 
    for (int i = 1; i <= n; i++) {
        parent[i]=i;
    }
    int v1, v2, components = n, msize = 1;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        bool merged = unite(v1, v2);
        if (merged) {
            components--;
            msize = max(msize, sz[find(v1)]);
        }
        cout << components << " " << msize << "\n";
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