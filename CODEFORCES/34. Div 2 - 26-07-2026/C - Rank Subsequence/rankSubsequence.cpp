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
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e9+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

void solve() {

    //pos from the left and right?
    //form nesting subarrays
    int n;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    vector<pii> left(n);
    vector<pii> right(n);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        left[i] = {a,b};
        cin >> a >> b;
        right[i] = {a,b};
    }
    //i==target chosen, j==chosen so far
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int idx = 0;
        for (int j = 1; j <= i; j++) {

            dp[i][j]=dp[i-1][j];

            int lr = j;
            int rr = i-j+1;


            while (idx<n) {
                bool l = left[idx].first>lr || left[idx].second<lr;
                bool r = right[idx].first>rr || right[idx].second<rr;
                if (l&&r) {
                    dp[i][j]=dp[i][j-1]+1;
                    idx++;
                    break;
                }
                idx++;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        res = max(res,dp[i][i]);
    }
    cout << res << "\n";

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