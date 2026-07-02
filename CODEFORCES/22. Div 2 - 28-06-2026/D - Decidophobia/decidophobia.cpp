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


void solve() {

    int n,d;
    cin >> n >> d;
    vector<ll> w(n);
    for (int i = 0; i < n; i++)cin >> w[i];

    ll sum = 0;
    int right = 0;
    while (right <= 2*d) {
        if (right==d) {
            right++;
            continue;
        }
        sum += w[right];
        right++;
    }
    int it = 0;
    ll total = 0;
    int left = 0; right = 2*d;
    for (int i = d; it < n; it++) {
        if (w[i]*2*d>sum) {
            total+=2*d*w[i]-sum;
        }
        sum-=w[left];
        left=(left+1)%n;
        right=(right+1)%n;
        sum+=w[right];
        sum+=w[i];
        i = (i+1)%n;
        sum-=w[i];
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
