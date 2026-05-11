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
 
vector<vector<int>> edges;
vector<int> sz;
 
void dfs(int node, int parent) {
 
    for (int nei : edges[node]) {
        if (nei != parent) {
            dfs(nei, node);
            sz[node]+=sz[nei];
        }
    }
 
}
 
void solve() {
 
    int n,a,b;
    cin >> n;
    edges.assign(n, vector<int>(0));
    sz.assign(n,1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    int maxsz = sz[0];
    int centroid = 0;
    vector<int> visited(n, 0);
    visited[0]=1;
    bool ran = true;
    while (ran) {
        ran = false;
        for (int nei : edges[centroid]) {
            if (sz[nei]>n/2 && visited[nei]==0) {
                visited[nei]=1;
                centroid=nei;
                maxsz=sz[centroid];
                ran = true;
            }
        }
    }
    cout << centroid+1;
 
 
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