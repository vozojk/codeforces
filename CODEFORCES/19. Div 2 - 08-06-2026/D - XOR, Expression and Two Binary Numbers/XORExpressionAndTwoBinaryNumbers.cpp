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
    cin >> n >> k;

    string a,b;
    cin >> a >> b;
    ll a1=0,a0=0,b1=0,b0=0,c1=0,c0=0;
    for (int i = 0; i < n; i++) {
        int first = a[i]-'0';
        int second = b[i]-'0';
        if (first==1)a1++;
        else a0++;
        if (second==1)b1++;
        else b0++;

        if (first^second)c1++;
        else c0++;
    }
    ll af = a0*a1, bf = b0*b1, cf = c0*c1;
    ll count = (1 << k)+1;
    if (k%2==1) {
        cout << (count/3)*(af+bf+cf) << "\n";
    }else {
        cout << (count/3)*(af+bf+cf)+af+bf << "\n";
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