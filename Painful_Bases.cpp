/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 24-October,2021 08:29:36
------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define mp       make_pair
#define PI       acos(-1.0)
#define TN       typename
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

bool isOn(int n, int at) { return (bool) (n & (1 << at)); }
int bitOn(int n, int at) { return n = n | (1 << at); }

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

int dp[(1 << 16) + 2][22];
int base, k, len;
string num;

int get(int at) {
    return (num[at] >= '0' and num[at] <= '9') ? num[at] - '0' : num[at] - 'A' + 10;
}

int call(int mask, int val) {
    // error(mask, val)
    if (mask == ((1 << len) - 1)) return val == 0;
    // debug("ok")
    int& ret = dp[mask][val];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < len; ++i) {
        if (!isOn(mask, i)) {
            // debug("ok")
            // error(i, get(i))
            ret += call(bitOn(mask, i), (get(i) + base * val) % k);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    Fast_IO
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        memset(dp, -1, sizeof dp);
        cin >> base >> k;
        cin >> num;
        reverse(all(num));
        len = szof(num);
        cout << "Case " << ++tc << ": " << call(0, 0) << nl;
    }
    return 0;
}
