#include <bits/stdc++.h>

using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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


void solve(){

    int a, b;
    cin >> a >> b;

    vector<vector<ll>> dp(a+1, vector<ll>(b+1,INF));
    //number of cuts for rectangle i,j

    for (int i = 0; i <= min(a,b); i++) {
        dp[i][i]=0;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i==j)continue;
            ll hor = INF;
            ll vert = INF;
            for (int k = 0; k < j; k++) {
                hor=min(dp[i][k]+dp[i][j-k], hor);
            }
            for (int k = 0; k < i; k++) {
                vert=min(dp[k][j]+dp[i-k][j], vert);
            }
            dp[i][j]=min(hor,vert)+1;
        }
    }
    cout << dp[a][b];

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