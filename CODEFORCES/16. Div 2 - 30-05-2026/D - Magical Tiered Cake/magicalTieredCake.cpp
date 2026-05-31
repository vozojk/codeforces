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

int n;
vector<int> above;
vector<vector<int>> ops;

void solve(int layer, int source, int target) {
    if (layer<0)return;

    int aux = 6 - source - target;

    int req = above[layer];

    if (req == 0) {
        solve(layer-1, source, aux);
        ops.push_back({layer, source, target});
        solve(layer-1, aux, target);
    }else {
        int excess = layer - req - 1;

        solve(excess, source, aux);

        ops.push_back({layer, source, target});

        solve(excess, aux, source);

        solve(layer-1, source, target);
    }
}

void solve(){

    cin >> n;
    above.assign(n, 0);

    bool possible = true;
    for (int i = 0; i < n; i++) {
        cin >> above[i];
        if (above[i]>i)possible = false;
    }
    if (!possible) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    solve(n-1, 1, 3);

    cout << ops.size() << "\n";
    for (auto v : ops) {
        cout << v[0]+1 << " " << v[1] << " " << v[2] << "\n";
    }
    ops.clear();


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