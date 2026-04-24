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
 
stack<int> st;
vector<vector<int>> edges;
vector<vector<int>> rEdges;
vector<int> visited;
vector<int> components;
 
void visit(int x) {
    for (int adj : edges[x]) {
        if (visited[adj]!=1) {
            visited[adj]=1;
            visit(adj);
        }
    }
    st.push(x);
}
void rvisit(int x, int k) {
    components[x]=k;
    for (int adj : rEdges[x]) {
        if (components[adj]==-1) {
            rvisit(adj, k);
        }
    }
}
 
void solve() {
    int n,m,v1,v2;
    cin >> n >> m;
 
    edges = vector<vector<int>>(n+1);
    rEdges = vector<vector<int>>(n+1);
    visited = vector<int>(n+1, 0);
    components = vector<int>(n+1, -1);
    vector<ll> values(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        rEdges[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]==0) {
            visited[i]=1;
            visit(i);
 
        }
    }
    int k = 1;
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (components[node]==-1) {
            rvisit(node, k);
            k++;
        }
    }
    k--;
    vector<ll> sizes(k+1);
 
 
    for (int i = 1; i <= n; i++) {
        sizes[components[i]]+=values[i];
    }
 
    vector<vector<int>> newEdg(n+1);
    vector<int> indeg(k+1);
    for (int i = 1; i <= n; i++) {
        for (int adj : edges[i]) {
            if (components[i]!=components[adj]) {
                newEdg[components[i]].push_back(components[adj]);
                indeg[components[adj]]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= k; i++) {
        if (indeg[i]==0)q.push(i);
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);
        for (int adj : newEdg[node]) {
            indeg[adj]--;
            if (indeg[adj]==0)q.push(adj);
        }
    }
    vector<ll> dp(k + 1, 0);
    for(int i = 1; i <= k; i++) {
        dp[i] = sizes[i];
    }
    ll ma = -1;
    for (int node : topo) {
        if (node == 0)continue;
        ma = max(ma, dp[node]);
        for (int adj : newEdg[node]) {
            dp[adj] = max(dp[adj], dp[node]+sizes[adj]);
        }
    }
 
    cout << ma;
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