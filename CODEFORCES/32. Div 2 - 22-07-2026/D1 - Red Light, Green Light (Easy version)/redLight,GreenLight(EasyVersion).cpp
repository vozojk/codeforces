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


ll safe_mod(ll x, ll k) {
    return (x % k + k) % k;
}

void solve() {
    ll n,k;
    cin >> n >> k;

    vector<ll> lights(n);
    for (int i = 0; i < n; i++)cin >> lights[i];

    vector<ll> delays(n);
    for (int i = 0; i < n; i++)cin >> delays[i];

    int q;
    cin >> q;
    static bool vis[505][505][2]; // Fixed size array outside query loop
    //if you arrive at the same node at the same time mod k its done
    while (q--) {
        memset(vis, 0, sizeof(vis));
        ll time = 0;
        ll pos;
        cin >> pos;
        ll inv = safe_mod(-pos,k);
        bool done = false;
        int last_bounce = -1;
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (lights[i]<pos)continue;
                if (i == last_bounce) continue;
                if (safe_mod(delays[i]-lights[i],k)==inv) {
                    time = safe_mod(time + lights[i] - pos, k);
                    pos = lights[i];
                    inv = safe_mod(time+pos,k);
                    if (vis[i][inv][0]) {
                        cout << "NO\n";
                        done = true;
                        break;
                    }
                    vis[i][inv][0] = true;
                    found = true;
                    last_bounce = i;
                    break;
                }
            }
            if (done)break;
            if (!found) {
                cout << "yes\n";
                break;
            }
            found = false;
            for (int i = n-1; i >= 0; i--) {
                if (lights[i]>pos)continue;
                if (i == last_bounce) continue;
                if (safe_mod(delays[i]+lights[i],k)==inv) {
                    time = safe_mod(time + pos - lights[i], k);
                    pos = lights[i];
                    inv = safe_mod(time-pos,k);
                    if (vis[i][inv][1]) {
                        cout << "NO\n";
                        done = true;
                        break;
                    }
                    vis[i][inv][1] = true;
                    found = true;
                    last_bounce = i;
                    break;
                }
            }
            if (done)break;
            if (!found) {
                cout << "yes\n";
                break;
            }
        }
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