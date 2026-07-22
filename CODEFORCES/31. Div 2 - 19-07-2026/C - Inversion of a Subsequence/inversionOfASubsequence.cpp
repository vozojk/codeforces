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


void solve() {

    //set any number of 0s for a 1 ->
    //everything where we add 0s is possible?
    //trade one 1 for any number of 1s from zeros (can upto achieve n-1 ones if theres a 1)
    //1 to 0 means choosing an odd number of 1s and changing them -> if even, odd+1.
    //only impossible state is a!=b and b=2^c-1 for some c

    int n;
    cin >> n;
    int a0=0,a1=0,b0=0, b1=0;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        if (f==1)a1++;
        else a0++;
        a[i]=f;
    }
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        b[i]=f;
        if (f==1)b1++;
        else b0++;
    }
    bool diff = true;
    int to0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]!=b[i]) {
            if (a[i]==1)to0++;
            diff=false;
        }
    }
    if (diff) {
        cout << 0 << "\n";
        return;
    }
    if (b1==n || a0==n) {
        cout << -1 << "\n";
        return;
    }

    int g;
    (to0)%2==0 ? g=2 : g=1;
    cout << g << "\n";




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