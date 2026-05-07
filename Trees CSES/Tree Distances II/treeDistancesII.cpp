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
 
vector<vector<int>> edge;
vector<pair<ll,ll>> dist; //val, count
vector<ll> ans;
int n;
void dfs_in(int node, int parent) {
    dist[node].second = 1; // Count the node itself
    for (int nei : edge[node]) {
        if (nei!=parent) {
            dfs_in(nei, node);
            dist[node].first += dist[nei].first + dist[nei].second;
            dist[node].second += dist[nei].second;
        }
    }
}
void dfs_out(int node, int parent) {
 
    for (int nei : edge[node]) {
        if (nei!=parent) {
            ans[nei]=ans[node]-dist[nei].second+(n-dist[nei].second);
            dfs_out(nei, node);
        }
    }
}
 
void solve() {
 
    int a, b;
    cin >> n;
    edge.assign(n, vector<int>(0));
    dist.assign(n, {0,0});
    ans.assign(n,0);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs_in(0, -1);
    ans[0]=dist[0].first;
    dfs_out(0, -1);
    for (ll c : ans)cout << c << " ";
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