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
 
    int n,m,temp1,temp2,temp3;
    cin >> n >> m;
 
    vector<vector<pair<ll,ll>>> endWeight(n+1); //len, node
    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> nodes; //{dist,node}
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        endWeight[temp1].push_back({temp3, temp2});
    }
    dist[1] = 0;
    nodes.push({0,1});
    while (!nodes.empty()){
        pair<ll,ll> node = nodes.top(); nodes.pop();
        ll nodeIdx = node.second;
 
        if (node.first > dist[nodeIdx])continue;
        
        for (pair<ll,ll> a : endWeight[nodeIdx]) {
            ll neighbourIdx = a.second;
            if (dist[neighbourIdx]>a.first + dist[nodeIdx]) {
                dist[neighbourIdx] = dist[nodeIdx] + a.first;
                nodes.push({dist[neighbourIdx], neighbourIdx});
            }
        }
    }
 
    for (int i = 1 ; i <= n; i++) {
        cout << dist[i] << " ";
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