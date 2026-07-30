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
constexpr ll INF = 1e9+1;

// 4-Directional Grid Movement
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_char[4] = {'U', 'D', 'L', 'R'};
// For 8-directional movement (Kings/Queens):
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#include <iostream>

using namespace std;

void solve() {

    int n;
    cin >> n;

    //create groups, merge smallest ones until we get 1.
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> groups;
    for (int i = 1; i <= n; i++) {
        groups.push({1, {i}});
    }

    while (true) {
        auto v1 = groups.top().second; groups.pop();
        auto v2 = groups.top().second; groups.pop();

        for (int a : v1) {
            for (int b : v2) {
                cout << a << " " << b << endl;
                int in = 0;
                cin >> in;
                if (in==1)return;
            }
        }
        vector<int> v12(v1.size()+v2.size());
        for (int i = 0; i < v1.size(); i++) {
            v12[i] = v1[i];
        }
        for (int i = 0; i < v2.size(); i++) {
            v12[i+v1.size()] = v2[i];
        }
        groups.push({v12.size(), v12});
    }
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