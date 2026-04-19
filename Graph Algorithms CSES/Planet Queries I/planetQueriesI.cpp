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
 
    int n,q;
    cin >> n >> q;
 
    vector<vector<int>> jump(n+1, vector<int>(30,-1));
 
    for (int i = 1; i <= n; i++) {
        cin >> jump[i][0];
    }
 
    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= n; j++) {
            jump[j][i] = jump[jump[j][i-1]][i-1];
        }
    }
    ll node, times;
    for (int i = 0; i < q; i++) {
        cin >> node >> times;
 
        for (int p = 0; p < 30; p++) {
            if ((times >> p) & 1) {
                node = jump[node][p];
            }
        }
        cout << node << "\n";
 
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