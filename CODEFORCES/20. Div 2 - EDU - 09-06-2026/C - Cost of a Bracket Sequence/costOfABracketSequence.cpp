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

    int n,k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> options(n, vector<int>(n,0));
    pair<int,int> global = {1e9,-1};
    for (int j = 0; j < n; j++) {
        int changes = k;

        for (int i = 0; i < j; i++) {
            if (s[i]=='(' && changes > 0) {
                options[j][i]=1;
                changes--;
            }
        }
        for (int i = n-1; i > j; i--) {
            if (s[i]==')' && changes > 0) {
                options[j][i]=1;
                changes--;
            }
        }
        int left = 0, m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i]=='(' && options[j][i]==0) {
                    left++;
            }else {
                if (options[j][i]==0) {
                    if (left>0) {
                        left--;
                        m+=2;
                    }
                }
            }
        }
        if (m<global.first) {
            global = {m,j};
        }
    }
    for (int f : options[global.second]) {
        cout << f;
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