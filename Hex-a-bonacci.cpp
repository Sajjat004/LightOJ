/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 15-October,2021 20:51:18
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
const int MOD    = (int) 10000007;
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

int a, b, c, d, e, f;
int dp[N];

int call(int n) {
    if (n == 0) return a % MOD;
    if (n == 1) return b % MOD;
    if (n == 2) return c % MOD;
    if (n == 3) return d % MOD;
    if (n == 4) return e % MOD;
    if (n == 5) return f % MOD;

    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    dp[n] = add(dp[n], call(n - 1), MOD);
    dp[n] = add(dp[n], call(n - 2), MOD);
    dp[n] = add(dp[n], call(n - 3), MOD);
    dp[n] = add(dp[n], call(n - 4), MOD);
    dp[n] = add(dp[n], call(n - 5), MOD);
    dp[n] = add(dp[n], call(n - 6), MOD);
    return dp[n];
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
        int n;
        cin >> a >> b >> c >> d >> e >> f >> n;
        cout << "Case " << ++tc << ": " << call(n) << nl;
    }
    return 0;
}
