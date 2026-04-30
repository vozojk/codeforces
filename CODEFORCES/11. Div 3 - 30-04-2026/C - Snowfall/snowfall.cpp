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
const int MOD = 676767677;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};


void solve(){

    int n, a;
    cin >> n;

    vector<int> nums6;
    vector<int> nums2;
    vector<int> nums3;
    vector<int> other;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a%6==0) {
            nums6.push_back(a);
        }else if (a%2==0) {
            nums2.push_back(a);
        }else if (a%3==0) {
            nums3.push_back(a);
        }else {
            other.push_back(a);
        }
    }
    for (int b : nums6) {
        nums.push_back(b);
    }
    for (int b : nums2) {
        nums.push_back(b);
    }
    for (int b : other) {
        nums.push_back(b);
    }
    for (int b : nums3) {
        nums.push_back(b);
    }
    for (int b : nums)cout << b << " ";
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