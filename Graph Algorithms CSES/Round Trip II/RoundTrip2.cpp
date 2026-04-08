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

vector<int> parent;
vector<vector<int>> edges;
vector<int> visited;
bool cycle = false;
void dfs(int node) {
    if (visited[node]==2 || cycle)return;
    if (visited[node]==1) {

        cycle = true;
        vector<int> nodes;
        nodes.push_back(node);
        node = parent[node];

        while (node!=nodes[0]) {
            nodes.push_back(node);
            node = parent[node];
        }

        nodes.push_back(node);
        reverse(nodes.begin(), nodes.end());
        cout << nodes.size() << "\n";
        for (int i : nodes) cout << i << " ";
    }

    visited[node]=1;

    for (int e : edges[node]) {
        parent[e] = node;
        dfs(e);
    }
    visited[node]=2;
}

void solve() {

    struct Edge {
        int from, to;
        ll len;
    };
    int n,m,temp1, temp2;
    cin >> n >> m;
    edges = vector<vector<int>>(n+1);
    parent = vector<int>(n+1);
    visited = vector<int>(n+1,0);

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        edges[temp1].push_back(temp2);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    if (!cycle) cout << "IMPOSSIBLE";



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