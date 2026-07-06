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

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    string nums;
    cin >> nums;

    if (nums[0] == '0' || nums[n-1] == '0') {
        cout << -1 << "\n";
        return;
    }

    ll total_mod = 1;
    ll total_c = 1;

    for (int k = 1; k < n; k++) {
        ll multiplier = 0;

        if (nums[k-1] == '1') {
            multiplier = 2;
        } else {
            multiplier = (k - 1);
        }

        total_mod = (total_mod * multiplier) % MOD;
        total_c = (total_c * multiplier) % c;
    }

    if (total_c == 0) {
        cout << -1;
    } else {
        cout << total_mod;
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