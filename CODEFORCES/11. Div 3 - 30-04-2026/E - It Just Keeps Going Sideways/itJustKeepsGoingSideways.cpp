#include <bits/stdc++.h>

using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void solve(){

    int n;
    cin >> n;
    vector<ll> he(n);
    for (int i = 0; i < n; i++) {
        cin >> he[i];
    }

    vector<ll> suffix(n);
    suffix[n - 1] = he[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = min(he[i], suffix[i + 1]);
    }

    ll noDelete = 0;
    for (int i = 0; i < n; i++) {
        noDelete += he[i] - suffix[i];
    }
    vector<int> shorterLeft(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && he[st.top()] >= he[i]) st.pop();
        if (!st.empty()) shorterLeft[i] = st.top();
        st.push(i);
    }


    ll maxGain = 0;
    for (int k = 0; k < n; k++) {

        ll nextMin = (k+1 < n) ? suffix[k+1] : 10e8;

        if (he[k] <= nextMin) {
            ll gain = k - shorterLeft[k];
            maxGain = max(maxGain, gain);
        }
    }

    cout << (noDelete + max((ll)0,maxGain-1)) << "\n";





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