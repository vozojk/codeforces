#include <bits/stdc++.h>
 
using namespace std;
#include <climits>
#include <string>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// 2. Define the Ordered Set (this is standard CP template boilerplate)
typedef tree<pair<int,int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void swap(vector<int> &a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
 
void solve() {
 
    int n, a, b, e = 0, f = 0, count = 0;
    cin >> n;
    vector<int> contains(n);
    vector<int> isContained(n);
    vector<tuple<int,int,int>> ranges(n);
    ordered_set set1;
    ordered_set set2;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ranges[i] = {a, b, i};
    }
    sort(ranges.begin(), ranges.end(), [](tuple<int,int,int> a, tuple<int,int,int> b) {
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) < get<0>(b);
 
    });
    for (int i = n-1; i >= 0; i--) {
        contains[get<2>(ranges[i])] = set2.order_of_key({get<1>(ranges[i]), INT_MAX});
        set2.insert({get<1>(ranges[i]), get<2>(ranges[i])});
 
    }
    for (int i = 0; i < n; i++) {
        isContained[get<2>(ranges[i])] = set1.size()-set1.order_of_key({get<1>(ranges[i]), -1});
        set1.insert({get<1>(ranges[i]), get<2>(ranges[i])});
 
    }
    for (int i : contains) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : isContained) {
        cout << i << " ";
    }
 
 
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    int t = 1;
    //cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
 
 
}