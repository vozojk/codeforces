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




void solve(){

    int n, a;
    cin >> n;
    vector<pair<ll,ll>> dp(n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    dp[0]={nums[0],0};
    cout << nums[0] << " ";
    for (int i = 1; i < n; i++) {
        ll total = (i)*dp[i-1].first+dp[i-1].second+nums[i];
        dp[i].first=min(total/(i+1), dp[i-1].first);
        dp[i].second = total-dp[i].first*(i+1);
        cout << dp[i].first << " ";
    }
    cout << "\n";


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