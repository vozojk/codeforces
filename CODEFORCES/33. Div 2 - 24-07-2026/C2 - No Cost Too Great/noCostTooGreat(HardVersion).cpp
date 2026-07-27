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
constexpr ll INF = 1e9+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

vector<ll> factors(ll n) {
    vector<ll> f;
    for (ll x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

void solve() {

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    ll sofar = 2*INF;
    vector<ll> b(n);
    ll first = INF;
    ll sec = INF;
    int min_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i]<b[min_idx]) min_idx=i;
        if (a[i]%2==1 && b[i]<first) {
            sec = first;
            first = b[i];

        }else if (a[i]%2==1 && b[i]<sec) {
            sec=b[i];
        }
    }
    //check next number for odd and even
    unordered_map<ll, int> cnts, facts;
    cnts.reserve(500);
    facts.reserve(500);
    bool even = false;

    for (int i = 0; i < n; i++) {
        if (even && a[i]%2==0) {
            cout << 0 << "\n";
            return;
        }
        if (a[i]%2==0)even=true;
        if (cnts[a[i]]>0 && a[i]!=1) {
            cout << 0 << "\n";
            return;
        }
        cnts[a[i]]++;
        for (ll f : factors(a[i])) {
            facts[f]++;
        }
    }
    for (ll num : a) {
        vector<ll> primepre = factors(num);
        for (ll f : primepre) {
            facts[f]--;
        }
        for (ll f : primepre) {
            if (facts.count(f)>0 && facts[f]>0) {
                cout << 0 << "\n";
                return;
            }
        }
        for (ll f : primepre) {
            facts[f]++;
        }
    }
    if (even) {
        sofar = min(sofar, first);
    }

    for (int i = 0; i < n; i++) {
        ll cost = b[i];
        vector<ll> primepre = factors(a[i]);
        for (ll f : primepre) {
            facts[f]--;
        }
        // Everyone only gets checked for +1
        ll added = a[i] + 1;
        vector<ll> primesadd = factors(added);
        for (ll f : primesadd) {
            if (facts.count(f)>0 && facts[f]>0) {
                sofar = min(cost, sofar);
            }

        }

        if (i == min_idx) {
            for (auto& kv : facts) {
                if (kv.second > 0) {
                    ll p = kv.first;
                    ll req = (p - (a[i] % p)) % p;
                    if (req > 0) sofar = min(sofar, b[i] * req);
                }
            }
        }
        for (ll f : primepre) {
            facts[f]++;
        }
    }
    ll m = first+sec;
    cout << min(m, sofar) << "\n";
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