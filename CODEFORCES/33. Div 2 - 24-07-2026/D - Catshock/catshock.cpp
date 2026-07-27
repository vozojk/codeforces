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
    vector<vector<int>> edges(n);
    int a,b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> dist(n,0);
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(n-1);
    vis[n-1]=1;
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int nei : edges[node]) {
            if (!vis[nei]) {
                vis[nei]=1;
                q.push(nei);
                dist[nei]=dist[node]+1;
            }
        }
    }

    vector<int> back(n);
    q.push(0);
    vis.assign(n,0);
    vis[0]=1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node==n-1)break;
        for (int nei : edges[node]) {
            if (!vis[nei]) {
                vis[nei]=1;
                q.push(nei);
                back[nei]=node;
            }
        }
    }
    vector<int> need(n,0);
    need[0]=1;
    int node = n-1;
    while (node!=0) {
        need[node]=1;
        node = back[node];
    }

    priority_queue<pii> pq;
    for (int i = 0; i < n; i++) {
        if (!need[i])pq.push({dist[i], i});
    }
    int d = dist[0] % 2;
    string response;
    int messages = 0;
    cout << 3*n << "\n";
    while (!pq.empty()) {
        pii node = pq.top(); pq.pop();
        if (node.first%2==d%2) {
            cout << "1\n";
            d = !d;
            messages++;
        }
        cout << "2 " << node.second+1 << "\n1\n";
        messages+=2;
        d = !d;
    }
    for (int i = 0; i < n; i++) {
        if (need[i])pq.push({dist[i], i});
    }
    while (pq.size()>1) {
        pii node = pq.top(); pq.pop();
        if (node.first%2==d%2) {
            cout << "1\n";
            d = !d;
            messages++;
        }
        cout << "2 " << node.second+1 << "\n1\n";
        messages+=2;
        d = !d;
    }
    while (messages<3*n) {
        cout << "1\n";
        messages++;
    }

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