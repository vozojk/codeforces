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

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> val(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    if (val[1]==0) {
        for (int i = 0; i <= m; i++) {
            dp[1][i]=1;
        }
    }else {
        dp[1][val[1]]=1;
    }
    for (int i = 2; i <= n; i++) {
        if (val[i]!=0) {
            int num = val[i];
            ll before = num > 1 ? dp[i-1][num-1] : 0;
            ll after = num < m ? dp[i-1][num+1] : 0;
            dp[i][num] = (dp[i-1][num] + before + after)%MOD;
            continue;
        }
        for (int last = 1; last <= m; last++) {
            ll before = last > 1 ? dp[i-1][last-1] : 0;
            ll after = last < m ? dp[i-1][last+1] : 0;
            dp[i][last] = (dp[i-1][last] + before + after)%MOD;
        }
    }
    ll total = 0;
    for (int i = 1; i <= m; i++) {
        total = (total + dp[n][i])%MOD;
    }
    cout << total;






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