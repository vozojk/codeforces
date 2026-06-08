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

    int n,ma = 0, idx = -1;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]>ma) {
            ma=v[i];
            idx = i;
        }
    }
    rotate(v.begin(), v.begin()+idx, v.end());
    vector<ll> result(n);
    for (int g = 0; g < n; g++) {
        ll m = 0;
        ll sum = 0;
        for (int i = g; i > 0; i--) {
            m = max(m, v[i]);
            sum += m;
        }
        m=0;
        for (int i = g+1; i < n; i++) {
            m = max(m, v[i]);
            sum += m;
        }
        result[(g+idx+1)%n] = sum;
    }
    for (ll a : result) {
        cout << a << " ";
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