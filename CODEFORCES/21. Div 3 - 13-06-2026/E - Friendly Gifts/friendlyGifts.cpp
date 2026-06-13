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

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> mip((n+1) * (n+1), INF);
    vector<int> map((n+1) * (n+1), -INF);

    auto gidx = [&](int min_v, int max_v) {
        return min_v * (n + 1) + max_v;
    };

    for (int i = 0; i < n; i++) {
        int min_val = a[i];
        int max_val = a[i];

        vector<bool> seen(n + 1, false);

        for (int j = i; j < n; j++) {
            if (seen[a[j]]) break;
            seen[a[j]] = true;

            min_val = min(min_val, a[j]);
            max_val = max(max_val, a[j]);
            if (max_val - min_val == j - i) {
                int idx = gidx(min_val, max_val);
                mip[idx] = min(mip[idx], i);
                map[idx] = max(map[idx], i);
            }
        }
    }


    int ans = 0;
    for (int l = n/2; l >= 1; l--) {
        bool possible = false;

        for (int x = 1; x+2*l-1 <= n; x++) {
            int y1 = x+l-1;
            int x2 = x+l;
            int y2 = x+2*l-1;
            int idx1 = gidx(x, y1);
            int idx2 = gidx(x2, y2);

            if (mip[idx1] == INF || mip[idx2] == INF) continue;

            if (mip[idx1] + l - 1 < map[idx2]) {
                possible = true;
                break;
            }
            if (mip[idx2] + l - 1 < map[idx1]) {
                possible = true;
                break;
            }
        }
        if (possible) {
            ans = l;
            break;
        }
    }

    cout << ans << "\n";
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