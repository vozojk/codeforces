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

#include <iostream>

using namespace std;

ll exp(int a, int b) {
    if (b == 0 || b<0) {
        return 1;
    }
    if (b%2==1) {
        return a * exp(a, b-1) % MOD;
    }
    ll res =  exp(a, b/2);
    return res*res % MOD;
}
void solve() {

    int n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll,ll> cnts;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnts[a[i]]++;
    }
    bool neg = a[0]==-1 ? true : false;
    ll next = 0;
    for (auto p : cnts) {
        if (cnts.count(p.first+1)>0 && neg)next++;
    }
    ll total = exp(2, n-cnts.size());
    cout << total*(1+next)%MOD << "\n";

    //sum is even, can find elements to divide it into 2 same halves
    //find tuples that sum to other tuples. group them?

    //even sequence length we need pairs if >0 ones at most dec by 1
    //compress into number of subsequences, we can also use with 1 bigger if a -1 is available



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