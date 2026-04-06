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
 
    int n,m,a,b,c;
 
    cin >> n >> m;
 
    struct Edge {
        int end;
        ll weight;
    };
    vector<vector<Edge>> edges(n+1);
 
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
 
        edges[a].push_back({b,c});
    }
 
    struct Node {
        ll costTo;
        int id;
        int layer;
    };
 
    vector<vector<ll>> dist(2, vector<ll>(n+1,INF));
    priority_queue<Node, vector<Node>, decltype([](Node& a, Node& b) {
        return a.costTo>b.costTo;
    })> pq;
 
    pq.push({0,1,0});
    
    dist[0][1] = 0;
 
    while (!pq.empty()) {
 
        Node popped = pq.top(); pq.pop();
 
        if (popped.costTo > dist[popped.layer][popped.id]) continue;
 
        for (auto e : edges[popped.id]) {
            if (popped.layer == 0) {
                if (dist[1][e.end] > dist[0][popped.id] + e.weight/2) {
                    dist[1][e.end] = min(dist[1][e.end], dist[0][popped.id] + e.weight/2);
                    pq.push({dist[1][e.end], e.end, 1});
                }
                if (dist[0][e.end] > dist[0][popped.id] + e.weight) {
                    dist[0][e.end] = min(dist[0][e.end], dist[0][popped.id] + e.weight);
                    pq.push({dist[0][e.end], e.end, 0});
                }
            }else {
                if (dist[1][e.end] > dist[1][popped.id] + e.weight) {
                    dist[1][e.end] = dist[1][popped.id] + e.weight;
                    pq.push({dist[1][e.end], e.end, 1});
                }
            }
 
 
        }
    }
 
    cout << dist[1][n];
 
 
 
 
 
 
 
 
 
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