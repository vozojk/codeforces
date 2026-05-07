#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
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
//#define dbg(x)
#endif
 
 
 
// --- Constants ---
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e18;
 
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve() {
 
    int n, a, b;
    cin >> n;
    vector<vector<int>> edge(n);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    queue<int> q;
    vector<int> visited(n, 0);
    q.push(0);
    visited[0]=1;
    int last = 0;
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            last = q.front(); q.pop();
            for (int nei : edge[last]) {
                if (visited[nei] == 0) {
                    q.push(nei);
                    visited[nei]=1;
                }
            }
        }
        depth++;
    }
    depth--;
    q.push(last);
    visited.assign(n, 0);
    visited[last]=1;
    vector<int> dist(n, 0);
    int first = depth;
    depth = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            last = q.front(); q.pop();
            dist[last]=max(depth, first-depth);
            for (int nei : edge[last]) {
                if (visited[nei] == 0) {
                    q.push(nei);
                    visited[nei]=1;
                }
            }
        }
        depth++;
    }
    q.push(last);
    visited.assign(n, 0);
    visited[last]=1;
    depth = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            last = q.front(); q.pop();
            dist[last]=max(depth, dist[last]);
            for (int nei : edge[last]) {
                if (visited[nei] == 0) {
                    q.push(nei);
                    visited[nei]=1;
                }
            }
        }
        depth++;
    }
    for (int i : dist)cout << i << " ";
 
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