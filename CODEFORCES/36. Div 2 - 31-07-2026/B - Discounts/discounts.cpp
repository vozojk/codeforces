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

    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> disc(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)cin >> disc[i];

    sort(a.begin(), a.end(), greater<>());
    sort(disc.begin(), disc.end());

    int idx = 0;
    ll total = 0;
    for (int discount : disc) {
        for (int i = idx; i < idx+discount-1; i++) {
            if (i>=n) {
                cout << total << "\n";
                return;
            }
            total += a[i];
        }
        idx = idx+discount;
    }
    while (idx<n) {
        total+=a[idx];
        idx++;
    }
    cout << total << "\n";

}
//18 9 7 3 2

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