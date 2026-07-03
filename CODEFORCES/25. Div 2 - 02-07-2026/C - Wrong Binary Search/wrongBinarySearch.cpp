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

#include <iostream>
#include <string>

using namespace std;

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeroes = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (s[i]=='0')zeroes++;
        if (s[i]=='1') {
            if (zeroes==1) {
                cout << "no\n";
                return;
            }
            zeroes = 0;
        }
    }
    if (zeroes==1) {
        cout << "no\n";
        return;
    }
    cout << "YES\n";
    zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='0')zeroes++;
        if (s[i]=='1') {
            int end = i-1;
            int start = i-zeroes;
            if (zeroes%2==1) {
                cout << cnt+2 << " " << cnt+1 << " " << cnt << " ";
                cnt += 3;
                start+=3;
                zeroes-=3;
            }
            if (zeroes%2==0 && zeroes!=0) {
                for (int idx = start; idx < end; idx=idx+2) {
                    cout << cnt+1 << " " << cnt << " ";
                    cnt+=2;
                }
            }
            zeroes=0;
            cout << cnt << " ";
            cnt++;
        }
    }

    if (zeroes!=0) {
        for (int i = cnt+zeroes-1; i >= cnt; i--) {
            cout << i << " ";
        }
    }
    cout << "\n";
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