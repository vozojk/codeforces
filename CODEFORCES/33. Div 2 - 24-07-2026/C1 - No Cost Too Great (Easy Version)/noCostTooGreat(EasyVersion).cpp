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

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    int bi = 0;
    for (int i = 0; i < n; i++)cin >> bi;

    vector<int> cnts(2e5+1,0);
    vector<int> facts(2e5+1, 0);
    bool even = false;
    bool one = false;

    for (int i = 0; i < n; i++) {
        if (even && a[i]%2==0) {
            one = true;
        }
        if (a[i]%2==0)even=true;
        if (cnts[a[i]]>0 && a[i]!=1) {
            cout << 0 << "\n";
            return;
        }
        cnts[a[i]]++;
        for (int f : factors(a[i])) {
            facts[f]++;
        }
    }
    if (one) {
        cout << 0 << "\n";
        return;
    }
    for (int num : a) {
        vector<int> primepre = factors(num);
        for (int f : primepre) {
            facts[f]--;
        }
        for (int f : primepre) {
            if (facts[f]>0) {
                cout << 0 << "\n";
                return;
            }
        }
        for (int f : primepre) {
            facts[f]++;
        }
    }
    if (even) {
        cout << "1\n";
        return;
    }

    for (int num : a) {
        vector<int> primepre = factors(num);
        int added = num+1;
        vector<int> primesadd = factors(added);
        for (int f : primepre) {
            facts[f]--;
        }
        for (int f :primesadd) {
            if (facts[f]>0) {
                cout << 1 << "\n";
                return;
            }

        }
        for (int f : primepre) {
            facts[f]++;
        }
    }

    cout << "2\n";

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