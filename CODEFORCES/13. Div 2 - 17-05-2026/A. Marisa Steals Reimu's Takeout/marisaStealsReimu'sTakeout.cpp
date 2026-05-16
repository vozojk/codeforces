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
constexpr ll INF = 2*1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};




void solve() {

    int n, count1 = 0, count2 = 0, total = 0, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a==0)total++;
        else if (a==1)count1++;
        else if (a==2)count2++;
    }
    int sums = min(count1, count2);
    total += sums;
    count1 -= sums;
    count2 -= sums;

    total += (count2/3);
    total += count1/3;

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