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
const int MOD = 676767677;
const ll INF = 1e18;
// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool fits(vector<int>& arr, int n) {
    vector<int> capacities;
    vector<int> needed(n, 1);
    vector<int> find;
    for (int a : arr) {
        if (a < n && needed[a]==1)needed[a]=0;
        else capacities.push_back((a-1)/2);
    }
    for (int i = 0; i < n; i++) {
        if (needed[i]==1)find.push_back(i);
    }
    int need = 0;
    int cap = 0;
    while (need < find.size() && cap < capacities.size()) {
        if (capacities[cap]>=find[need]) {
            need++;
            cap++;
        }else {
            cap++;
        }
    }
    if (need>=find.size())return true;
    return false;

}
void solve() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = n;
    int best = -1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (fits(arr, mid)) {
            best = max(best, mid);
            left = mid+1;
        }else {
            right = mid-1;
        }
    }
    cout << best << "\n";







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