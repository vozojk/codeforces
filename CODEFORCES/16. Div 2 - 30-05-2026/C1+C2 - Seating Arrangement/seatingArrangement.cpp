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

    int n,s,t;
    cin >> n >> t >> s;
    //ambi new table only if extro wouldnt have a place to sit

    //kick out all first extro
    //intro only a table if i have too many tables
    ll opencap = 0;
    ll ambi = 0;
    ll total = 0;
    string sa;
    cin >> sa;
    for (int i = 0; i < n; i++) {
        char cur = sa[i];
        if (t > 0 && cur == 'I') {
            t--;
            opencap+=s-1;
            total++;
        }else if (cur == 'A') {
            if (opencap > 0) {
                opencap--;
                total++;
                ambi++;
            }else if (t > 0) {
                total++;
                opencap+=s-1;
                t--;
            }
        }else if (cur == 'E'){
            if (opencap > 0) {
                opencap--;
                total++;
            }else if (ambi > 0 && t > 0) {
                opencap+=s-1;
                ambi--;
                t--;
                total++;
            }
        }
    }
    cout << total << "\n";

    //go from back. give inst to ambi?

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