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



void solve(){

    int a,b,x;
    cin >> a >> b >> x;

    vector<pii> as;
    vector<pii> bs;
    as.reserve(30);
    bs.reserve(30);
    as.push_back({a,0});
    bs.push_back({b,0});
    int c =0;
    while (a > 0) {
        a/=x;
        c++;
        as.push_back({a,c});
    }
    c=0;
    while (b>0) {
        b/=x;
        c++;
        bs.push_back({b,c});
    }
    int mi = 150;
    for (int i = 0; i < as.size(); i++) {
        for (int j = 0; j < bs.size(); j++) {
            int div = as[i].second+bs[j].second+abs(as[i].first-bs[j].first);
            mi = min(mi,div);
        }
    }
    cout << mi << "\n";

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