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
    int n;
    cin >> n;
    ll pairs = 0, odds = 0, oddsused = 0, total = 0, singles = 0, pairtypes = 0;
    vector<ll> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        odds += cards[i]==1 ? 1 : 0;
        pairs += cards[i]/2;
        if (cards[i]/2>0)pairtypes++;
        singles += (cards[i]>1 && cards[i]%2==1) ? 1 : 0;
        if (cards[i]>2) {
            oddsused += (cards[i]/2-1);
        }
        if (total <= 3)total += cards[i];
    }
    if (pairtypes==1 && pairs >= 2)oddsused++;

    if (total < 3 || pairs == 0) {
        cout << 0 << "\n";

    }else if (pairs == 1) {
        if (total == 3)cout << 3 << "\n";
        if (total > 3)cout << 2+singles+1 << "\n";

    }else {
        cout << 2*pairs + singles + (oddsused > odds ? odds : oddsused) << "\n";
    }


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