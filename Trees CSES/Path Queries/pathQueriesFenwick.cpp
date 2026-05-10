#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
vector<int> in, out;
vector<ll> nodes, bit;
int n, timer = 1; // Timer MUST start at 1 for Fenwick Tree bitwise math
vector<vector<int>> edges;
 
// Standard Euler Tour
void dfs(int node, int parent) {
    in[node] = timer++;
    for (int nei : edges[node]) {
        if (nei != parent) {
            dfs(nei, node);
        }
    }
    out[node] = timer; // The exact index where the subtree ends
}
 
// Fenwick Core: Add val to idx
void add(int idx, ll val) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}
 
// Fenwick Core: Prefix Sum up to idx
ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}
 
// The Roadblock Logic
void update_path(int idx, ll val) {
    ll delta = val - nodes[idx];
    nodes[idx] = val;
 
    // Drop the +delta at the node's start time
    add(in[idx], delta);
 
    // Drop the -delta roadblock right after the subtree finishes
    // We check <= n to ensure we don't try to place a roadblock out of bounds
    if (out[idx] <= n) {
        add(out[idx], -delta);
    }
}
 
void solve() {
    int queries, a, b;
    cin >> n >> queries;
 
    in.assign(n, 0);
    out.assign(n, 0);
    nodes.assign(n, 0);
    edges.assign(n, vector<int>(0));
 
    // Fenwick tree strictly needs size N + 1
    bit.assign(n + 2, 0);
 
    vector<ll> initial(n);
    for (int i = 0; i < n; i++) {
        cin >> initial[i];
    }
 
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
 
    // Flatten the 3D tree into a 1D timeline starting at Root (0)
    dfs(0, -1);
 
    // Populate the initial values using the Difference Array logic
    for (int i = 0; i < n; i++) {
        update_path(i, initial[i]);
    }
 
    while (queries--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx; ll val;
            cin >> idx >> val;
            idx--;
            update_path(idx, val);
        } else {
            int idx;
            cin >> idx;
            idx--;
            // Sweep the timeline from the start up to the target node
            cout << query(in[idx]) << "\n";
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while(t--) {
        solve();
    }
 
    return 0;
}