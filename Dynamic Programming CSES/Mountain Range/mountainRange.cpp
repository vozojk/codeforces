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
constexpr int MOD = 1e9+7;
constexpr ll INF = 1e18;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> seg;
int n;
void update(int i, int val) {
    for (seg[i += n] = val; i > 1; i >>= 1) {
        seg[i >> 1] = max(seg[i], seg[i ^ 1]);
    }
}

int query (int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l>>=1, r>>=1) {
        if (l & 1)res = max(res, seg[l++]);
        if (r & 1)res = max(res, seg[--r]);
    }
    return res;
}

void solve(){

    cin >> n;
    vector<int> he(n);
    vector<int> dp(n+1,0);
    for (int i = 0; i < n; i++) {
        cin >> he[i];
    }

    vector<int> before(n, -1);
    vector<int> after(n, n);
    stack<int> st;
    // build arrays with >= before/after
    for (int i = 0; i < n; i++) {
        while (!st.empty() && he[st.top()] < he[i]) {
            st.pop();
        }
        if (!st.empty()) {
            before[i]=st.top();
        }
        st.push(i);
    }
    while (!st.empty())st.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && he[st.top()] < he[i]) {
            st.pop();
        }
        if (!st.empty()) {
            after[i]=st.top();
        }
        st.push(i);
    }
    vector<pair<int,int>> heI(n);
    for (int i = 0; i < n; i++) {
        heI[i] =  {he[i], i};
    }
    sort(heI.begin(), heI.end());

    seg.assign(2*n, 0);

    int m = 0;
    for (int i = 0; i < n; i++) {
        const int idx = heI[i].second;
        int current = query(before[idx]+1, after[idx]) + 1;
        update(idx, current);
    }
    cout << seg[1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    //cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}