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

#ifdef lOCAl
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
//#define dbg(x)
#endif

// --- Constants ---
constexpr int MOD = 998244353;
constexpr ll INF = 1e9+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

void solve() {

    int n;
    cin >> n;

    struct Edge {
        int v1;
        int v2;
        int c1;
        int c2;
    };

    vector<Edge> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        int v1,v2,c1,c2;
        cin >> v1 >> v2 >> c1 >> c2;
        edges[i] = {v1-1,v2-1,c1,c2};
    }

    vector<int> p(n,-1);
    vector<vector<int>> topo(n);
    vector<int> indeg(n,0);
    for (int i = 0; i < n-1; i++) {
        Edge e = edges[i];
        if (e.c1>e.c2) {
            topo[e.v1].push_back(e.v2);
            indeg[e.v2]++;
        }else {
            topo[e.v2].push_back(e.v1);
            indeg[e.v1]++;
        }
    }
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indeg[i]==0)q.push(i);
    }
    int cur = n;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        p[node]=cur;
        cur--;
        for (int nei : topo[node]) {
            indeg[nei]--;
            if (indeg[nei]==0) {
                q.push(nei);
            }
        }
    }

    for (int c : p) {
        cout << c << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}