
Codeforces
In English По-русски
vozojk | Logout

HomeTopCatalogContestsGymProblemsetGroupsRatingEduAPICalendarHelp


ProblemsSubmit CodeMy SubmissionsStatusHacksRoomStandingsCustom Invocation
    
General
  
377376777	Virtual:
vozojk#	2128A - 40	C++20 (GCC 13-64)	Accepted	31 ms	12 KB	2026-06-05 12:53:02	2026-06-05 12:53:03	Add to favourites	Compare
→ SourceCopy
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
 
    int n,c;
    cin >> n >> c;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    int a = 0;
    for (int i = 0; i < n; i++) {
        sort(nums.begin(), nums.end());
        auto it = upper_bound(nums.begin(), nums.end(), c);
        if (it == nums.begin())break;
        it--;
        *it = 1e18;
        a++;
        for (int j = 0; j < n; j++)if (nums[j] <= c)nums[j]*=2;
    }
    cout << n-a << "\n";
 
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