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
    ll count = 0;
    cin >> n >> m;

    vector<int> indeg = vector<int>(n+1, 0);
    vector<vector<int>> edges = vector<vector<int>>(n+1);

    queue<int> q;
    vector<int> paths(n+1,0);
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        indeg[temp2]++;
        edges[temp1].push_back(temp2);
    }

    for (int i = 1; i <= n; i++) {
        if (indeg[i]==0) q.push(i);
    }
    paths[1]=1;
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int adj : edges[node]) {
            paths[adj] = (paths[adj] + paths[node])%MOD;
            indeg[adj]--;

            if (indeg[adj]==0) {
                q.push(adj);
            }
        }
    }
    cout << paths[n];







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