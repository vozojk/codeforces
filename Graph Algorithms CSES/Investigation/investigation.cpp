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


    vector<vector<pair<int,int>>> edges = vector<vector<pair<int,int>>>(n+1);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    vector<ll> dist(n+1, INF);
    vector<int> paths(n+1,0);
    vector<int> shortest(n+1, 10e6);
    vector<int> longest(n+1, 0);

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        edges[temp1].push_back({temp3, temp2});
    }
    paths[1] = 1;
    dist[1] = 0;
    shortest[1] = 0;
    longest[1] = 0;
    pq.push({0,1});

    while (!pq.empty()) { //when pq pop i got shortest dist
        pair<ll,int> node = pq.top(); pq.pop();

        int id = node.second;
        ll costNode = node.first;

        if (costNode>dist[id])continue;

        for (pair<ll,int> adj : edges[id]) {
            int adjId = adj.second;
            ll adjCost = adj.first;

            if (dist[adjId] == dist[id]+adjCost) {
                shortest[adjId] = min(shortest[adjId], shortest[id]+1);
                longest[adjId] = max(longest[adjId], longest[id]+1);
                paths[adjId]=(paths[adjId]+paths[id])%MOD;

            }else if (dist[adjId] > dist[id]+adjCost) {

                shortest[adjId] =  shortest[id]+1;
                longest[adjId] = longest[id]+1;
                paths[adjId] = paths[id];
                dist[adjId] = dist[id]+adjCost;
                pq.push({dist[adjId], adjId});
            }

        }
    }
    cout << dist[n] << " " << paths[n] << " " << shortest[n] << " " << longest[n];







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