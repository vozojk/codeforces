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

int mex = -1;
void find(vector<int>& seen) {
    sort(seen.begin(), seen.end());
    for (int i = 0; i < seen.size(); i++) {
        if (seen[i]==i)mex = max(mex, i);
    }
}
void solve(){
    mex = -1;
    int n;
    cin >> n;
    vector<int> nums(2*n);
    vector<pair<int,int>> index(2*n, {-1, -1});
    //all counts have to be in, for 1 number there is 1-2 counts
    for (int i = 0; i < 2*n; i++) {
        cin >> nums[i];
        if (index[nums[i]].first==-1) {
            index[nums[i]].first=i;
        }else {
            index[nums[i]].second=i;
        }
    }
    if (abs(index[0].first-index[0].second)==1) {//center
        int left = min(index[0].first, index[0].second);
        int right = max(index[0].first, index[0].second);
        vector<int> seen;
        while (left>=0 && right < 2*n && nums[left]==nums[right]) {
            seen.push_back(nums[left]);
            left--;
            right++;
        }
        find(seen);


    }else {
        int left = min(index[0].first, index[0].second);
        int right = min(index[0].first, index[0].second);
        vector<int> seen;
        while (left>=0 && right < 2*n && nums[left]==nums[right]) {
            seen.push_back(nums[left]);
            left--;
            right++;
        }
        find(seen);


        left = max(index[0].first, index[0].second);
        right = max(index[0].first, index[0].second);
        seen.clear();
        while (left>=0 && right < 2*n && nums[left]==nums[right]) {
            seen.push_back(nums[left]);
            left--;
            right++;
        }
        find(seen);


        left = min(index[0].first, index[0].second);
        right = max(index[0].first, index[0].second);
        int mid = (left+right)/2;
        if (left%2+right%2==1) {
            left = mid;
            right = mid+1;
        }else {
            left = mid;
            right = mid;
        }
        seen.clear();
        while (left>=0 && right < 2*n && nums[left]==nums[right]) {
            seen.push_back(nums[left]);
            left--;
            right++;
        }
        find(seen);


    }
    cout << mex+1 << "\n";




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