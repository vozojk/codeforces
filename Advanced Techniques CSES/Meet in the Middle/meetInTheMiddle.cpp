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
 
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    vector<ll> h1(1 << n/2);
    vector<ll> h2(1 << (n-n/2));
 
    ll total = 0;
 
    for (int mask = 0; mask < (1 << n/2); mask++) {
        for (int i = 0; i < n/2; i++) {
            if ((mask >> i)%2==1) {
                h1[mask]+=nums[i];
            }
        }
    }
    for (int mask = 0; mask < 1 << (n-n/2); mask++) {
        for (int i = 0; i < n-n/2 ; i++) {
            if ((mask >> i) & 1) {
                h2[mask]+=nums[i+n/2];
            }
        }
    }
    sort(h1.begin(), h1.end());
 
    for (int i = 0; i < h2.size(); i++) {
        ll num = x-h2[i];
        auto lower = lower_bound(h1.begin(), h1.end(), num);
        auto upper = upper_bound(h1.begin(), h1.end(), num);
 
        total += upper-lower;
    }
    cout << total << "\n";
 
 
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
 
    //cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}