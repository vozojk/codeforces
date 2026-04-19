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

    int n,m,temp1,temp2;

    cin >> n >> m;

    vector<int> indeg = vector<int>(n+1, 0);
    vector<vector<int>> edges = vector<vector<int>>(n+1);
    vector<int> parent(n+1, -1);
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    queue<int> q;

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        indeg[temp2]++;
        edges[temp1].push_back(temp2);
    }

    for (int i = 1; i <= n; i++) {
        if (indeg[i]==0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int adj : edges[node]) {
            indeg[adj]--;
            if (dist[node]!=-1 && dist[node]+1>dist[adj]) {
                parent[adj]=node;
                dist[adj]=dist[node]+1;
            }
            if (indeg[adj]==0) {
                q.push(adj);
            }
        }
    }

    if (parent[n]==-1) {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<int> res;
    int node = n;
    while (node!=-1) {
        res.push_back(node);
        node = parent[node];
    }

    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int a : res) {
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