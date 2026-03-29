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
#define dbg(x)
#endif
 
 
 
// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
void solve() {
    int n;
    cin >> n;
 
    int count = 0;
 
    vi nums(n);
    vi stupid(n);
 
 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> stupid[i];
    }
    int gcd1 = gcd(nums[0],nums[1]);
    if (gcd1<nums[0]) {
        nums[0] = gcd1;
        count++;
    }
    for (int i = 1; i < n-1; i++) {
        int gcd1 = gcd(nums[i-1], nums[i]), gcd2 = gcd(nums[i],nums[i+1]);
        int res = lcm(gcd1, gcd2);
        if (res<nums[i]) {
            nums[i] = res;
            count++;
        }
    }
    gcd1 = gcd(nums[n-1], nums[n-2]);
    if (gcd1 < nums[n-1])count++;
 
 
 
    //need to check all except for that one
    //delete factors that are not shared with anything else
    cout << count << "\n";
 
 
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