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

#ifdef lOCAl
#define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
//#define dbg(x)
#endif

// --- Constants ---
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    vector<pii> comp;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int last = nums[0];
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i]==last) {
            c++;
        }else {
            comp.push_back({last, c});
            last = nums[i];
            c=1;
        }
    }
    comp.push_back({last, c});
    int closest = -1;
    for (int i = comp.size()-1; i >= 0; i--) {
        if (closest != -1 && comp[closest].first-comp[i].first<=k) {
            cout << "YES\n";
            return;
        }
        if (comp[i].second%2==0) {
            cout << "YES\n";
            return;
        }

        if (comp[i].second%2==1)closest = i;
    }

    cout << "NO\n";
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