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
 
    int n, a ,b;
    cin >> n;
    vector<tuple<int,int,int>> stays(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        stays[i]={a,b, i};
    }
    sort(stays.begin(), stays.end());
    vector<int> roomNums(n);
    multiset<pair<int, int>> roomsFree;
    int biggestRoom = 0;
    //keep track of time the room closes, absolute, we can do lower bound on the end, if we find a room we remove it and push in a new one
    //else we just push and increase a counter, we can be pushing the room numbers as we go
    for (int i = 0; i < n; i++) {
        auto it = roomsFree.begin();
        if (it != roomsFree.end() && it->first < get<0>(stays[i])) {
            roomNums[get<2>(stays[i])] = it->second;
            roomsFree.insert({get<1>(stays[i]), it->second});
            roomsFree.erase(it);
 
        }else {
            biggestRoom++;
            roomNums[get<2>(stays[i])] = biggestRoom;
            roomsFree.insert({get<1>(stays[i]), biggestRoom});
        }
    }
    cout << biggestRoom << "\n";
    for (int i : roomNums) cout << i << " ";
    cout << "\n";
 
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