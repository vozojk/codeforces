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

bool isPal(ll a) {
    ll div = 10;
    vector<ll> digits;
    while (a!=0) {
        ll last = a%div;
        a -= last;
        digits.push_back(last);
    }
    int l = 0, r = digits.size()-1;
    while (l<r) {
        if (digits[l]!=digits[r])return false;
        l++;
        r--;
    }
    return true;
}
int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;

    if (isOdd)
        n /= b;

    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
void solve() {
    ll n;
    cin >> n;
    //n==a mod 12
    if (n%12==10 && n < 22)cout << -1 << "\n";
    else if (n%12==10)cout << 22 << " " << n-22 << "\n";
    else cout << n%12 << " " << n-n%12 << "\n";

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