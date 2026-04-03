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

int cycleStart = -1;
int cycleEnd = -1;
bool off = false;
vector<int> visited;
void findCycle(vector<vector<int>>& edges, int vertex) {
    for (int a : edges[vertex]) {

        if (a == visited[vertex])continue;

        if (visited[a]>0) {
            cycleEnd  = a;
            cycleStart = vertex;
            off = true;
            return;
        }
        visited[a]=vertex;

        findCycle(edges, a);
        if (off)return;
    }
}
void solve() {

    int n,m,temp1,temp2;
    cin >> n >> m;

    vector<vector<int>> edges(n+1);

    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2;
        edges[temp1].push_back(temp2);
        edges[temp2].push_back(temp1);
    }
    visited = vector<int>(n+1);

    for (int i = 1; i <= n; i++) {
        if (visited[i]>0)continue;
        visited[i]=i;
        findCycle(edges, i);
        if (off)break;
    }

    if (!off) {
        cout << "IMPOSSIBLE";
        return;
    }

    int cur = cycleStart;
    vector<int> res;

    while (cur!=cycleEnd) {
        res.push_back(cur);
        cur = visited[cur];
    }
    res.push_back(cycleEnd);
    res.push_back(cycleStart);

    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int a : res) cout << a << " ";


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