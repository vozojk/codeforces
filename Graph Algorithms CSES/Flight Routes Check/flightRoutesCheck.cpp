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
 
void solve() {
    int n,m, v1, v2;
    cin >> n >> m;
 
    vector<vector<int>> edges(n+1);
    vector<vector<int>> rEdges(n+1);
 
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        rEdges[v2].push_back(v1);
    }
 
    vector<int> visited(n+1, 0);
    vector<int> rVisited(n+1, 0);
    visited[1]=1;
    rVisited[1]=1;
    queue<int> q;
    q.push(1);
 
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int adj : edges[node]) {
            if (visited[adj]==0) {
                q.push(adj);
                visited[adj]=1;
            }
        }
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cnt1+=visited[i];
    }
    q.push(1);
    while (!q.empty()) {
        int node = q.front(); q.pop();
 
        for (int adj : rEdges[node]) {
            if (rVisited[adj]==0){
                q.push(adj);
                rVisited[adj]=1;
            }
        }
    }
    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt2+=rVisited[i];
    }
    if (cnt2+cnt1==2*n) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
        for (int i = 1; i <= n; i++) {
            if (visited[i]==0) {
                cout << 1 << " " << i << "\n";
                return;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (rVisited[i]==0) {
                cout << i << " " << 1 << "\n";
                return;
            }
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