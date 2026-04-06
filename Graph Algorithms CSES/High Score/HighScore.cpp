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
const int MOD = 1e9 + 7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve() {
 
    int n,m,a,b,x;
 
    cin >> n >> m;
 
    struct Edge {
        int start;
        int end;
        ll weight;
    };
    vector<Edge> edges(m);
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        Edge& e = edges[i];
        e.start = a;
        e.end = b;
        e.weight = x;
    }
 
    vector<ll> dist(n+1, -INF);
    dist[1] = 0;
 
 
    for (int i = 1; i <= n; i++) {
        for (auto& e : edges) {
            if (dist[e.start] != -INF) {
                dist[e.end] = max(dist[e.start]+e.weight, dist[e.end]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto& e : edges) {
            if (dist[e.start] != -INF && dist[e.start] +e.weight > dist[e.end] || dist[e.start] == INF) {
                dist[e.end] = INF;
            }
        }
    }
 
    cout << (dist[n]==INF ? -1 : dist[n]);
 
 
 
 
 
 
 
 
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