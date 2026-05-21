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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mina = 0;

    vector<int> group(n,-1);
    for (int i = 0; i < n-1; i++) {
        if (nums[i]>nums[i+1]) {
            mina = max(mina, nums[i]-nums[i+1]);
            if (group[i] == 1) {
                cout << "NO\n";
                return;
            }
            group[i]=0;
            group[i+1]=1;
        }

    }
    if (mina == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n-1; i++) {
        if (group[i]==1 && nums[i]+mina > nums[i+1]) {
           if (group[i+1]==0) {
               cout << "NO\n";
               return;
           }
            group[i+1]=1;
        }
    }
    for (int i = n-2; i >= 0; i--) {
        if (group[i+1]==0 && nums[i]+mina>nums[i+1]) {
            if (group[i]==1) {
                cout << "NO\n";
                return;
            }
            group[i]=0;
        }
    }
    cout << "YES\n";



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