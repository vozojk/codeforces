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
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};


ll choose2(ll x) {
    if (x<2) return 0;
    return x*(x-1)/2;
}

ll choose3(ll x) {
    if (x<3) return 0;
    return x*(x-1)*(x-2)/6;
}

void solve() {

    int n;
    cin >> n;
    vector<int> w(n);
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    int a,b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> parent(n, -1);
    vector<int> indeg(n,0);
    vector<int> visited(n, 0);
    visited[0]=1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nei : edge[node]) {
            if (!visited[nei]) {
                q.push(nei);
                parent[nei]=node;
                visited[nei]=1;
                indeg[node]++;
            }
        }

    }

    while (!q.empty())q.pop();

    for (int i = 0; i < n; i++) {
        if (indeg[i]==0)q.push(i);
    }
    vector<int> subtree(n, 1);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (parent[node]==-1)continue;
        subtree[parent[node]]+=subtree[node];

        indeg[parent[node]]--;
        if (indeg[parent[node]]==0)q.push(parent[node]);
    }

    ll total3 = 1LL*(n-1)*(n-2)*(n-3)/6;
    ll total2 = 1LL*(n-1)*(n-2)/2; // Add total pairs for when 'c' is in the triplet
    ll res = 0;

    for (int i = 0; i < n; i++) {
        ll s_val = sqrt(w[i]);
        if (s_val * s_val == w[i]) {
            ll bad3 = 0;
            ll bad2 = 0;
            for (int nei : edge[i]) {
                if (nei != parent[i]) {
                    ll sz = subtree[nei];
                    bad3 += choose3(sz)+choose2(sz)*((n-1)-sz);
                    bad2 += choose2(sz);
                }
            }
            ll g = n-subtree[i];
            bad3 += choose3(g)+choose2(g)*((n-1)-g);
            bad2 += choose2(g);

            res += (total3-bad3)+(total2-bad2);
        }
    }

    cout << res << "\n";

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