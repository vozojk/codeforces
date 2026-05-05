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
    if (n==1) {
        cout << 0;
        return;
    }
    vector<vector<int>> edge(n);
    vector<int> deg(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    queue<int> q;
    vector<int> con(n, 0);
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (deg[i]==1) {
         visited[i]=1;
            q.push(i);
        }
    }
 
    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nei : edge[node]) {
            if (con[node]==0 && con[nei]==0) {
                con[node]=1;
                con[nei]=1;
                count++;
            }
            deg[nei]--;
            if (deg[nei]==1) {
                q.push(nei);
            }
        }
    }
    cout << count;
 
 
 
 
 
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