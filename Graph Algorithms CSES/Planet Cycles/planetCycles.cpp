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
 
    int n;
    cin >> n;
 
    vector<int> edges(n+1, -1);
    vector<vector<int>> reverseEdges(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> cycle(n+1,0);
    vector<int> cycleSize(n+1,-1);
    vector<int> depth(n+1);
    vector<int> root(n+1);
    queue<int> q;
 
    for (int i = 1; i <= n; i++) {
       cin >> edges[i];
        indegree[edges[i]]++;
        reverseEdges[edges[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i]==0)q.push(i);
    }
 
    while (!q.empty()) {
        int node = q.front(); q.pop();
        indegree[edges[node]]--;
        if (indegree[edges[node]]==0)q.push(edges[node]);
    }
    int count = 1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i]>0 && cycle[i]==0) {
            int sizeCount = 1;
            int c = i;
            cycle[i] = count;
            c = edges[c];
            while (c != i) {
                cycle[c] = count;
                c = edges[c];
                sizeCount++;
            }
            cycleSize[count] = sizeCount;
            count++;
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (cycle[i] != 0) {
            root[i] = i;
            depth[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();
 
        for (int adj : reverseEdges[node]) {
            if (cycle[adj]!=0)continue;
            depth[adj] = depth[node]+1;
            root[adj] = root[node];
            q.push(adj);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (cycle[i]!=0) {
            cout << cycleSize[cycle[i]] << "\n";
        }else {
            cout << depth[i] + cycleSize[cycle[root[i]]] << "\n";
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