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

    int t, temp, maxn = 0;
    cin >> t;
    vector<int> ns(t);
    for (int i = 0; i < t; i++) {
        cin >> ns[i];
        maxn = max(ns[i], maxn);
    }
    vector<vector<ll>> dp(maxn+1, vector<ll>(2,0));
    dp[1][0]=1;
    dp[1][1]=1;
    for (int i = 2; i <= maxn; i++) {
        dp[i][0]=(1*dp[i-1][1]+4*dp[i-1][0])%MOD;
        dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%MOD;
    }
    for (int i = 0; i < t; i++) {
        cout << (dp[ns[i]][0]+dp[ns[i]][1])%MOD << "\n";
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