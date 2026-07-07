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

int lcsRec(vector<ll> &s1, vector<ll> &s2, int m, int n, vector<vector<int>> &memo) {

    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcsRec(s1, s2, m - 1, n - 1, memo);

    return memo[m][n] = max(lcsRec(s1, s2, m, n - 1, memo), lcsRec(s1, s2, m - 1, n, memo));
}
int lcs(vector<ll> &s1,vector<ll> &s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return lcsRec(s1, s2, m, n, memo);
}

void solve() {

   string a,b;
    cin >> a >> b;

    vector<ll> pa(a.size());
    vector<ll> pb(b.size());
    ll sum = 0;
    int idx = 0;
    for (const char c : a) {
        sum = (sum+c-'0')%10;
        pa[idx]=sum;
        idx++;
    }

    ll sum2 = 0;
    idx = 0;
    for (const char c : b) {
        sum2 = (sum2+c-'0')%10;
        pb[idx]=sum2;
        idx++;
    }
    if (sum2!=sum) {
        cout << -1 << "\n";
        return;
    }
    const ll l = lcs(pa,pb);
    cout <<l << "\n";
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