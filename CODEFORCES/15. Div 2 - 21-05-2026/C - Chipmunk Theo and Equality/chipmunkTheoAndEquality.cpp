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

vector<pair<int, int>> costs;

void calc(int num) {
    int cost = 0;
    bool vis2 = false, vis1 = false;
    while (num > 0) {
        if ((num==1 || num==2) && vis1 && vis2)break;
        if (num==2)vis2 = true;
        if (num==1)vis1 = true;
        costs.push_back({num, cost});
        cost++;
        if (num%2==1) {
            num+=1;
        }else num/=2;
    }
}

void solve(){

    int n;
    cin >> n;
    costs.clear();
    costs.reserve(n * 30);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        calc(nums[i]);
    }
    sort(costs.begin(), costs.end());

    int ans = 2e9;
    int m = costs.size();

    for (int i = 0; i < m; ) {
        int j = i;
        int count = 0;
        int csum = 0;

        while (j < m && costs[j].first == costs[i].first) {
            csum += costs[j].second;
            count++;
            j++;
        }
        if (count == n) {
            ans = min(ans, csum);
        }
        i = j;
    }
    cout << ans << "\n";



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