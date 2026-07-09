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

#include <iostream>
#include <string>

using namespace std;
vector<ll> vals;
vector<unordered_map<ll, vector<int>>> edge;
vector<unordered_map<ll,ll>> memo;
ll dfs(ll idx, ll next) {
    if (memo[idx].count(next)>0) {
        return memo[idx][next];
    }
    ll total = 1;
    for (ll nei : edge[idx][next]) {
        total=(total+dfs(nei, next+vals[idx]))%MOD;
    }
    memo[idx][next]=total;
    return total;
}

void solve() {

    int n,m;
    cin >> n >> m;
    vals = vector<ll>(n+1);
    for (int i = 1; i <= n; i++)cin >> vals[i];
    edge = vector<unordered_map<ll, vector<int>>>(n+1);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        edge[a][vals[b]].push_back(b);
    }
    memo = vector<unordered_map<ll,ll>>(n+1);
    ll ans = 0;
    for (int i = 1; i <=n; i++) {
        for (auto p : edge[i]) {
            for (int idx : p.second) {
                ans=(ans+dfs(idx, vals[i]+vals[idx]))%MOD;
            }
        }
    }
    cout << ans << "\n";
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