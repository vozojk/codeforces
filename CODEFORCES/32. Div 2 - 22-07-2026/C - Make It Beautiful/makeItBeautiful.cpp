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
constexpr ll INF = 1e18+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

ll lowest_to_set(ll x) {
    ll div = 1;
    while ((x&div)!=0) {
        div*=2;
    }
    return div;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    while (k>0) {
        vector<ll> idx;
        idx.push_back(0);
        ll lowest = INF;
        for (int j = 0; j < n; j++) {
            ll cur = lowest_to_set(a[j]);
            if (lowest>cur) {
                lowest = cur;
                idx.clear();
                idx.push_back(j);
            }else if (lowest==cur) {
                idx.push_back(j);
            }
        }
        bool stop = false;
        for (ll f : idx) {
            if (k<lowest) {
                stop=true;
                break;
            }
            a[f]+=lowest;
            k-=lowest;
        }
        if (stop)break;
    }
    ll total = 0;
    for (ll f : a) {
        total += __builtin_popcountll(f);
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