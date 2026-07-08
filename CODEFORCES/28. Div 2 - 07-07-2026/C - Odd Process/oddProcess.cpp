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
#include <string>

using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<ll> a(n);
    int e=0,o=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]%2==0)e++;
        else o++;
    }

    vector<ll> odd(o);
    vector<ll> even(e);
    int idxo = 0;
    int idxe = 0;
    ll biggestOdd = 0;

    for (int i = 0; i < n; i++) {
        if (a[i]%2==0) {
            even[idxe]=a[i];
            idxe++;
        }else {
            biggestOdd = max(biggestOdd, a[i]);
            odd[idxo]=a[i];
            idxo++;
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    vector<ll> prefE(e);
    int idx = 0;
    ll sum = 0;
    for (int i = e-1; i >= 0; i--) {
       sum += even[i];
        prefE[idx]=sum;
        idx++;
    }
    for (int k = 1; k <= n; k++) {
        if (o==0) {
            cout << 0 << " ";
            continue;
        }
        if (k>e+1) {
            //give up smallest ones, if k%2==0?
            //if k-(e)%2==0 -> use smallest even
            //else e+1
            if (e==0) {
                if (k%2==0) {
                    cout << 0 << " ";
                }else cout << biggestOdd << " ";
                continue;
            }
            if ((k-e)%2==0) { // odd of odds, if k-e==o else, odd+1 of odds, and then odd+e-1
                if (k-e==o) {
                    cout << 0 << " ";
                }else if (e==1) {
                    cout << biggestOdd << " ";
                }else cout << biggestOdd+prefE[prefE.size()-2] << " ";
            }else {
                cout << biggestOdd+prefE.back() << " ";
            }
        }else {
            if (k==1) {
                cout << biggestOdd << " ";
            }else cout << biggestOdd+prefE[k-2] << " ";
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