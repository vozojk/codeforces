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
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    if (n==1) {
        if (a[0]==1) {
            cout << "2\n";
        }else {
            cout << "0\n";
        }
        return;
    }

    vector<int> state(n,-1); //0==L, 1==R

    for (int i = 0; i < n-1; i++) {
        if (a[i]<a[i+1]) {
            state[i]=0;
            state[i+1]=0;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (a[i]>a[i+1]) {
            if (state[i]==0 || state[i+1]==0) {
                cout << "0\n";
                return;
            }
            state[i]=1;
            state[i+1]=1;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (a[i]==a[i+1]) {
            if (state[i]!=-1) {
                if (state[i+1]==state[i]) {
                    cout << 0 << "\n";
                    return;
                }
                state[i+1]=(state[i]+1)%2;
            }else if (state[i+1]!=-1){
                state[i]=(state[i+1]+1)%2;
            }
        }
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i]==a[i-1]) {
            if (state[i]!=-1) {
                if (state[i-1]==state[i]) {
                    cout << 0 << "\n";
                    return;
                }
                state[i-1]=(state[i]+1)%2;
            }else if (state[i-1]!=-1){
                state[i]=(state[i-1]+1)%2;
            }
        }
    }

    int cnt = 0;
    for (int f : state) {
        if (f==-1)cnt++;
    }
    if (cnt==0) {
        vector<int> pref_left(n);
        vector<int> post_right(n);

        int left = 0;
        int right = 0;

        for (int i = 0; i < n; i++) {
            if (state[i]==0) {
                left++;
            }
            pref_left[i] = left;
        }
        for (int i = n-1; i >= 0; i--) {
            if (state[i]==1) {
                right++;
            }
            post_right[i] = right;
        }
        for (int i = 0; i < n; i++) {
            if (pref_left[i]+post_right[i]!=a[i]) {
                cout << "0\n";
                return;
            }
        }
        cout << "1\n";
    }else {
        int total = 0;
        for (int f = 0; f < 2; f++) {

            vector<int> new_state(n);

            for (int i = 0; i < n; i++) {
                new_state[i] = (i + f) % 2;
            }
            vector<int> pref_left(n);
            vector<int> post_right(n);

            int left = 0;
            int right = 0;

            for (int i = 0; i < n; i++) {
                if (new_state[i]==0) {
                    left++;
                }
                pref_left[i] = left;
            }
            for (int i = n-1; i >= 0; i--) {
                if (new_state[i]==1) {
                    right++;
                }
                post_right[i] = right;
            }
            bool broken = false;
            for (int i = 0; i < n; i++) {
                if (pref_left[i]+post_right[i]!=a[i]) {
                    broken = true;
                }
            }
            if (!broken)total++;
        }
        cout << total << "\n";
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