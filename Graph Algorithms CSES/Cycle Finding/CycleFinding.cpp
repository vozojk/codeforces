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
 
 
 
 
    //cycle through possible middle vertices, then start-end combs
    //cycle again, if i find something theres a cycle
 
    int n,m,a,b,c;
    cin >> n >> m;
    struct Edge {
        int start;
        int end;
        ll length;
    };
    vector<int> parent(n+1, -1);
    vector<Edge> edges(m);
    vector<ll> dist(n+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = {a,b,c};
 
    }
 
    for (int i = 1; i < n; i++) {
        for (auto& edge : edges) {
            if (dist[edge.end] > dist[edge.start] + edge.length) {
                dist[edge.end] = dist[edge.start] + edge.length;
                parent[edge.end] = edge.start;
            }
 
        }
    }
    int cycle = -1;
        for (auto& edge : edges) {
                if (dist[edge.end] > dist[edge.start] + edge.length) {
                    cycle = edge.end;
                    parent[edge.end] = edge.start;
                    break;
            }
        }
    if (cycle == -1) {
        cout << "NO";
    }else {
        cout << "YES\n";
 
        for (int i = 0; i < n; i++) {
            cycle = parent[cycle];
        }
 
        vector<int> res;
 
        res.push_back(cycle);
        int start = cycle;
        cycle = parent[cycle];
 
        while (start != cycle) {
            res.push_back(cycle);
            cycle = parent[cycle];
        }
        res.push_back(cycle);
 
        reverse(res.begin(), res.end());
 
        for (int i : res) {
            cout << i << " ";
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