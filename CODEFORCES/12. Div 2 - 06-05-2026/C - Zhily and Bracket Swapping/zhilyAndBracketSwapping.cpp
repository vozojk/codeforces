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


void solve() {

    int n;
    cin >> n;

    string b1;
    string b2;
    cin >> b1 >> b2;

    int c1a = 0, c1b = 0, c2a = 0, c2b = 0;
    for (char c : b1) {
        if (c == '(')c1a++;
        else c1b++;
    }
    for (char c : b2) {
        if (c == '(')c2a++;
        else c2b++;
    }

    if (b1[0] == ')' || b2[0] == ')' || b1[n-1] == '(' || b2[n-1] == '(' || c1a+c2a!=c1b+c2b) {
        cout << "NO" << "\n";
        return;
    }
    //number of ( must be bigger than ) and at the end ( and ) must be equal
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++) {
        if (b1[i]=='(') {
            c1++;
        }else c1--;
        if (b2[i]=='(') {
            c2++;
        }else c2--;
        if (b2[i]!=b1[i]) {
            if (c1 > c2 && c1 >= 2) {
                if (b1[i] == '(') {
                    c1-=2;
                    c2+=2;
                }
            }else if (c2 > c1 && c2 >= 2){
                if (b2[i]== '(') {
                    c1+=2;
                    c2-=2;
                }
            }
        }
        if (c1 < 0 || c2 < 0) {
            cout << "NO" << "\n";
            return;
        }
    }

    if (c1==0 && c2==0) {
        cout << "YES" << "\n";
    }else cout << "NO" << "\n";




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