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

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 2e18; // Upgraded to ll to prevent overflow during bad increment paths

    // Z is the target minimum trailing zeros forced across the entire array
    for (int Z = 0; Z <= 17; Z++) {
        ll total = 0;

        for (int num : a) {
            ll mi = 2e18;

            // Find the distance to the next multiple of 2^Z
            ll rem = num % (1LL << Z);
            ll add = (rem == 0) ? 0 : (1LL << Z) - rem;

            // Check the first few valid multiples of 2^Z
            for (int k = 0; k < 15; k++) {
                ll v = num + add + k * (1LL << Z);
                // The true invariant cost for a single isolated element
                ll cost = (v - num) + __popcount(v) + __bit_width(v) - 1;
                mi = min(mi, cost);
            }
            total += mi;
        }

        // Apply the global division discount for the shared trailing zeros
        total -= 1LL * (n - 1) * Z;
        res = min(res, total);
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