/*  Bismillahir Rahmanir Rahim
    Author  :  Md. Sajjat Hosen
    Created :  Friday, 05 June, 2020 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int maxN    = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     all(x)      x.begin(), x.end()
#define     szof(x)     (int) x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     mp          make_pair
#define     PI          acos(-1.0)
#define     TN          typename
#define     nl          '\n'
#define     Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

inline int add(int a, int b) { a += b; return a >= Mod ? a - Mod : a < 0 ? a + Mod : a; }
inline int mult(int a, int b) { return (ll) a * b % Mod; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

#ifndef Sajjat004
     #define error(...) __f(#__VA_ARGS__, __VA_ARGS__);
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " = " << arg1 <<" ";
        __f(comma+1, args...);
    }
#else
    #define error(...)
#endif

int vis[100][100];

bool isVis(int idx, int m) {
    for (int i = 1; i <= m; ++i) {
        if (vis[idx][i] == 0) return 1;
    }
    return 0;
}
int main() {
    Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        list<int> lis;
        int n, m;
        cin >> n >> m;
        int seat[m + 3];
        memset(seat, 0, sizeof seat);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            lis.pb(i);
        }
        ll time = 0;
        bool ok = 1;
        int curr = 1, cnt = 0;
        while (ok) {
            time += 5;
            if (seat[curr] != 0 && isVis(seat[curr], m)) {
                lis.pb(seat[curr]);
            } else if (seat[curr] != 0) cnt++;
            ok = cnt == n ? 0 : 1;
            seat[curr] = 0;
            for (auto it = lis.begin(); it != lis.end(); ++it) {
                if (vis[*it][curr] == 0) {
                    vis[*it][curr] = 1;
                    seat[curr] = *it;
                    lis.erase(it);
                    break;
                }
            }
            curr++;
            if (curr > m) curr = 1;
        }
        cout <<"Case " << ++tc << ": " << time << nl;
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
