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
 
    int n,queries;
    cin >> n >> queries;
 
    vector<int> edges(n+1, -1);
    vector<vector<int>> reverseEdges(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> cycle(n+1,0);
    vector<int> cycleSize(n+1,-1);
    vector<int> cPos(n+1, -1);
    vector<int> depth(n+1);
    vector<int> root(n+1);
    vector<vector<int>> jump(n+1, vector<int>(30));
    queue<int> q;
 
    for (int i = 1; i <= n; i++) {
       cin >> edges[i];
        jump[i][0] = edges[i];
        indegree[edges[i]]++;
        reverseEdges[edges[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i]==0)q.push(i);
    }
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i <= n; i++) {
            jump[i][j] = jump[jump[i][j-1]][j-1];
        }
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
            cPos[c] = 0;
            c = edges[c];
            while (c != i) {
                cycle[c] = count;
                cPos[c] = sizeCount;
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
 
    while (queries--) {
        int from, to;
        cin >> from >> to;
        if (cycle[root[from]] != cycle[root[to]]) {
            cout << "-1\n";
            continue;
        }
        if (cycle[from]!=0 && cycle[to]!=0) {
            cout << (cPos[to]-cPos[from]+cycleSize[cycle[from]])%cycleSize[cycle[from]] << "\n";
 
        }else if (cycle[from]==0 && cycle[to]!=0) {
            cout << depth[from] + (cPos[root[to]]-cPos[root[from]]+cycleSize[cycle[to]])%cycleSize[cycle[to]] << "\n";
 
        }else if (cycle[to]==0 && cycle[from]!=0)cout << "-1\n";
 
        else if (cycle[to]==0 && cycle[from]==0) {
 
            if (depth[from]<depth[to])cout << "-1\n";
            else {
                int times = depth[from]-depth[to];
                for (int i = 0; i <= 29; i++) {
                    if ((times >> i) & 1) {
                        from = jump[from][i];
                    }
                }
                if (from==to) cout << times << '\n';
                else cout << "-1\n";
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