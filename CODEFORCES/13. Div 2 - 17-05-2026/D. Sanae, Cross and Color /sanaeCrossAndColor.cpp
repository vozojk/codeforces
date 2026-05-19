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

void solve() {

    //create vectors of unique x and y coords, sorted
    //find absolute minimums and maximums for each y
    //find prefix and suffix minimums and maximums for y
    //for all xs from 0 to size -2 user lower bound to find how many gaps are there through the established bounds, sum them up

    int n;
    cin >> n;
    vector<int> unique_x(n);
    vector<int> unique_y(n);
    vector<pii> points;
    for (int i = 0; i < n; i++) {
        cin >> unique_x[i] >> unique_y[i];
        points.push_back({unique_x[i], unique_y[i]});
    }
    sort(unique_y.begin(), unique_y.end());
    sort(unique_x.begin(), unique_x.end());
    unique_y.erase(unique(unique_y.begin(), unique_y.end()), unique_y.end());
    unique_x.erase(unique(unique_x.begin(), unique_x.end()), unique_x.end());

    vector<int> min_x(n+1, n+1);
    vector<int> max_x(n+1, 0);
    for (int i = 0; i < n; i++) {
        int cx = points[i].first;
        int cy = points[i].second;
        min_x[cx] = min(min_x[cx], cy);
        max_x[cx] = max(max_x[cx], cy);
    }
    vector<int> pref_min(n+1, n+1);
    vector<int> pref_max(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref_min[i] = min(pref_min[i-1], min_x[i]);
        pref_max[i] = max(pref_max[i-1], max_x[i]);
    }
    vector<int> suff_min(n+2, n+1);
    vector<int> suff_max(n+2, 0);
    for (int i = n; i >= 1; i--) {
        suff_min[i] = min(suff_min[i + 1], min_x[i]);
        suff_max[i] = max(suff_max[i + 1], max_x[i]);
    }
    ll total = 0;
    for (int i = 0; i < unique_x.size()-1; i++) {
        // current, floor, ceiling, diff in iter
        int cx = unique_x[i];

        int ceiling = min(pref_max[cx], suff_max[cx+1]);
        int floor = max(pref_min[cx], suff_min[cx+1]);

        auto upper_it = lower_bound(unique_y.begin(), unique_y.end(), ceiling);
        auto lower_it = lower_bound(unique_y.begin(), unique_y.end(), floor);

        int gaps = upper_it - lower_it;

        total += max(0, gaps);
    }
    cout << total << "\n";
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