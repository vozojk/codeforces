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
constexpr int MOD = 998244353;
constexpr ll INF = 1e9;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};



void solve() {

    //remove n 1s, n>0, n%2==0 (additionally even numbers of positions of each removed 1), track 1s for all numbers for each position
    //make sure the count for at least 1 position is odd on each move
    //the recurring condition to guarantee a win is to never pass an array with all even counts back
    //so we count the numbers of arrays b we can create so the new array a has at least 1 odd count at any position?

    //handing an array which is all 0s or has 1 number of any value makes them lose
    ll total = 0;
    ll x = 0;
    ll n;
    cin >> n;
    vector<ll> nums(n);
    int ab0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        x ^= nums[i];
        if (nums[i]!=0)ab0++;
    }
    if (ab0<2) {
        cout << 0 << "\n";
        return;
    }
    if (x==0)total++;
    for (int i = 0; i < nums.size(); i++) {
        ll reqXor = x^nums[i];

        if (reqXor < nums[i])total++;
    }
    cout << total << "\n";
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