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
const int MOD = 676767677;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 
void solve(){
 
    int n, m;
    cin >> n >> m;
    vector<int> first(n+1);
    vector<int> second(m+1);
    vector<vector<pair<int,int>>> back(n+1, vector<pair<int,int>>(m+1));
    back[1][1]={0,0};
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
    for (int i = 1; i <= n; i++) {
        cin >> first[i];
        dp[i][0]=0;
    }for (int i = 1; i <= m; i++) {
        cin >> second[i];
        dp[0][i]=0;
    }
    vector<int> seq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (first[i]==second[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int x = n, y = m;
    while (x != 0 && y != 0) {
        if (first[x]==second[y]) {
            seq.push_back(first[x]);
            x--;
            y--;
        }else {
            if (dp[x-1][y]>dp[x][y-1])x--;
            else y--;
        }
    }
    reverse(seq.begin(), seq.end());
    cout << dp[n][m] << "\n";
    for (int i : seq) {
        cout << i << " ";
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