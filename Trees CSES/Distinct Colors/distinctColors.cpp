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
vector<set<int>> colors;
vector<int> realcount;
void dfs(int node, int parent) {
    int biggest = 0;
    int idx = -1;
    for (int nei : edges[node]) {
        if (nei != parent) {
            dfs(nei, node);
            if (biggest < colors[nei].size()) {
                biggest = colors[nei].size();
                idx = nei;
            }
        }
    }
    if (idx != -1) {
        swap(colors[idx], colors[node]);
        for (int nei : edges[node]) {
            if (nei != parent) {
                for (int c : colors[nei]) {
                    colors[node].insert(c);
                }
            }
        }
    }
    realcount[node]=colors[node].size();
 
 
}
 
void solve() {
 
    int n,a,b;
    cin >> n;
    edges.assign(n, vector<int>(0));
    colors.assign(n, set<int>());
    realcount.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        colors[i].insert(a);
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
 
    dfs(0, -1);
    for (int a : realcount) {
        cout << a << " ";
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