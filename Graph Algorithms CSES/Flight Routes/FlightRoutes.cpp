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

    struct Edge {
        int from, to;
        ll len;
    };
    int n,m,k,temp1, temp2, temp3;
    cin >> n >> m >> k;
    vector<vector<Edge>> edges(n+1);
    vector<vector<ll>> dist(n+1, vector<ll>(k, INF));

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        edges[temp1].push_back({temp1, temp2, temp3});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;

    pq.push({0,1});

    while (!pq.empty()) {
        pair<ll,ll> node = pq.top(); pq.pop();
        if (node.first > dist[node.second][k-1])continue;
        for (Edge e : edges[node.second]) {
            ll newDist = node.first + e.len;
            if (dist[e.to][k-1] > newDist) {
                dist[e.to][k-1] = newDist;
                pq.push({newDist,e.to});
                sort(dist[e.to].begin(), dist[e.to].end());
            }

        }
    }
    for (ll a : dist[n]) {
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