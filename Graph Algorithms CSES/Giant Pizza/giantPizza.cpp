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
const int MOD = 1e9+7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
stack<int> st;
vector<vector<int>> edges;
vector<vector<int>> rEdges;
vector<int> visited;
vector<int> components;
 
void visit(int x) {
    for (int adj : edges[x]) {
        if (visited[adj]!=1) {
            visited[adj]=1;
            visit(adj);
        }
    }
    st.push(x);
}
void rvisit(int x, int k) {
    components[x]=k;
    for (int adj : rEdges[x]) {
        if (components[adj]==-1) {
            rvisit(adj, k);
        }
    }
}
int get_opposite(int node, int m) {
    if (node > m) return node - m; // It was negative, make it positive
    else return node + m;          // It was positive, make it negative
}
// Assuming 'm' is a global or passed variable for the total toppings
int get_node(char sign, int val, int m) {
    if (sign == '+') return val;
    else return val + m;
}
void solve() {
    int n,m, v1, v2;
    char c1, c2;
    cin >> n >> m;
 
    edges = vector<vector<int>>(2*m+1);
    rEdges = vector<vector<int>>(2*m+1);
    visited = vector<int>(2*m+1, 0);
    components = vector<int>(2*m+1, -1);
 
    for (int i = 0; i < n; i++) {
        cin >> c1 >> v1 >> c2 >> v2;
 
        int node1 = get_node(c1, v1, m);
        int node2 = get_node(c2, v2, m);
        int not1 = get_opposite(node1, m);
        int not2 = get_opposite(node2, m);
        edges[not1].push_back(node2);
        rEdges[node2].push_back(not1);
 
        edges[not2].push_back(node1);
        rEdges[node1].push_back(not2);
    }
    for (int i = 1; i <= 2*m; i++) {
        if (visited[i]!=1) {
            visited[i]=1;
            visit(i);
        }
    }
    int k = 1;
    while (!st.empty())  {
        int node = st.top(); st.pop();
        if (components[node]==-1) {
            rvisit(node, k);
            k++;
        }
    }
    k--;
    for (int i = 1; i <= m; i++) {
        if (components[i]==components[i+m]) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (components[i] > components[i+m]) {
            cout << "+ ";
        }else
            cout << "- ";
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