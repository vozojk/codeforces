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

vector<int> digits;
ll bestv;
ll bestd;
string s;
ll target;

void update(ll val) {
    ll diff = abs(val-target);
    if (diff <= bestd) {
        bestv = val;
        bestd = diff;
    }
}

void dfs(int idx, bool greater, bool less, ll val) {
    if (idx == s.length()) {
        update(val);
        return;
    }

    if (less || greater) {
        int d = greater ? digits.front() : digits.back(); // Min if greater, Max if less
        while (idx < s.length()) {
            val = val * 10 + d; // Math append, NO strings
            idx++;
        }
        update(val);
        return;
    }

    for (int d : digits) {
        dfs(idx+1, d > s[idx]-'0', d < s[idx]-'0', val*10+d);
    }

}

void solve() {

    ll a;
    int n, b;
    cin >> a >> n;
    s = to_string(a);
    target = a;
    bestd = 2e18;
    bestv = -1;
    for (int i = 0; i < n; i++) {
        cin >> b;
        digits.push_back(b);
    }

    //size n-1
    if (s.length() > 1) {
        ll val = 0;
        for (int i = 1; i < s.length(); i++) {
            val = val*10+digits.back();
        }
        update(val);
    }

    if (s.length() < 18) {
        int smallest = -1;
        for (int c : digits) {
            if (c!=0) {
                smallest = c;
                break;
            }
        }

        ll val = smallest;
        for (int i = 0; i < s.length(); i++) {
            val = val*10 + digits.front();
        }
        smallest != -1 ? update(val) : update(0);
    }

    dfs(0, false, false, 0);
    digits.clear();
    cout << bestd << "\n";


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