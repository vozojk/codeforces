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

vector<int> parent;
vector<int> sz;


int find(int x) {
    if (parent[x]!=x) {
        return parent[x] = find(parent[x]);
    }
    return x;

}
bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false;
    if (sz[rootX]>sz[rootY]) {
        sz[rootX]=sz[rootX]+sz[rootY];
        parent[rootY]=rootX;
    }else {
        sz[rootY]=sz[rootX]+sz[rootY];
        parent[rootX]=rootY;
    }
    return true;
}
void solve() {
    struct Edge{
        int weight, u, v;

        bool operator<(const Edge& a) const {
            return weight < a.weight;
        }
    };
    int n, m, temp1, temp2, temp3;
    cin >> n >> m;
    parent = vector<int>(n+1);
    sz = vector<int>(n+1);
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        edges.push_back({temp3, temp1, temp2});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    ll cost = 0;
    int eUsed = 0;

    for (auto & edge : edges) {
        if (unite(edge.u, edge.v)) {
            cost+=edge.weight;
            eUsed++;
        }

    }
    if (eUsed==n-1) {
        cout << cost;
    }else cout << "IMPOSSIBLE";









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