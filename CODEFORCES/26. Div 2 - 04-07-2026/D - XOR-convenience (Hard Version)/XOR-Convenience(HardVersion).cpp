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

void solve() {
    //for hard chain them up?
    //lower=higher^idx_lower -> higher=lower^idx_lower
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 2; i < n; i++) {
        res[i-1] = i^1;
    }
    res[n-1]=1;
    if (__builtin_popcountll(n)==1) {
        cout << -1 << '\n';
        return;
    }
    if (n%2==0) {
        res[0] =  res[(1 << __builtin_ctzl(n))-1];
        res[(1 << __builtin_ctzl(n))-1] = n;
    }else res[0]=n^1;
    for (int i = 0; i < n; i++)cout << res[i] << " ";
    cout << '\n';

    //1234(-)(2^1=3 -> 1)(3^1=2 -> 1)(4^1=5 -> 1), 3^1^1=3 2^2^1=1 1^2^1=2
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