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

vector<ll> valid_nums[10][10];

void precompute() {
    for (int d1 = 0; d1 <= 9; d1++) {
        for (int d2 = d1 + 1; d2 <= 9; d2++) {
            valid_nums[d1][d2].reserve(524286);
            for (int len = 1; len <= 18; len++) {

                int combs = 1 << len;

                for (int mask = 0; mask < combs; mask++) {
                    ll current_val = 0;
                    ll mult = 1;

                    for (int j = 0; j < len; j++) {
                        if (mask & (1 << j)) {
                            current_val += d2 * mult;
                        } else {
                            current_val += d1 * mult;
                        }
                        mult *= 10;
                    }

                    valid_nums[d1][d2].push_back(current_val);
                }
            }
            sort(valid_nums[d1][d2].begin(), valid_nums[d1][d2].end());
            valid_nums[d1][d2].erase(unique(valid_nums[d1][d2].begin(), valid_nums[d1][d2].end()), valid_nums[d1][d2].end());
        }
    }
}

void solve() {

    ll a;
    int n, d1, d2;
    cin >> a >> n >> d1 >> d2;
    const vector<ll>& options = valid_nums[d1][d2];

    auto it = lower_bound(options.begin(), options.end(), a);
    ll best = INF;
    if (it != options.end()) {
        best = min(best, abs(a - *it));
    }

    // Check the number strictly < a (the one right before it)
    if (it != options.begin()) {
        it--;
        best = min(best, abs(a - *it));
    }

    cout << best << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    precompute();

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}