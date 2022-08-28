/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 11-August,2021 10:09:56
-------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long             ll;
typedef long double           ld;
typedef unsigned long long    ull;
typedef pair <int, int>       pii;
typedef pair <ll, ll>         pll;
typedef vector <int>          vi;
typedef vector <ll>           vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       	= (int) 2e5 + 5;
const int mxN     	= (int) 1e6 + 6;
const int MOD     	= (int) 1e9 + 7;
const int INF     	= (int) 1e9 + 9;
const double EPS	= (double) 1e-9;

#define debug(x)    cerr << #x << " = " << x << '\n';
#define all(x)      x.begin(), x.end()
#define szof(x)     (int) x.size()
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define PI          acos(-1.0)
#define TN          typename
#define nl          '\n'
#define Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

string s, t;
int n, m;
int lss;

ll dp[40][40][100];

ll fun(int n, int m, int k) {
	if (k == 0 and n == 0 and m == 0) return 1LL;
	if (k == 0) return 0LL;
	if (k > 0 and n == 0 and m == 0) return 0LL;
	ll& ret = dp[n][m][k];
	if (ret != -1LL) return ret;
	ret = 0LL;
	if (s[n] == t[m]) {
		ret = fun(n - 1, m - 1, k - 1);
	} else {
		if (n) ret += fun(n - 1, m, k - 1);
		if (m) ret += fun(n, m - 1, k - 1);
	}
	return ret;
}

int LCS() {
	int dp1[n + 1][m + 1];
	memset(dp1, 0, sizeof dp1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i] == t[j]) {
				dp1[i][j] = 1 + dp1[i - 1][j - 1];
			} else {
				dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]);
			}
		}
	}
	return dp1[n][m];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
    	memset(dp, -1LL, sizeof dp);
        cin >> s >> t;
        n = szof(s), m = szof(t);
        s = '?' + s;
        t = '?' + t;
        int lcs = LCS();
        lss = n + m - lcs;
        ll res = fun(n, m, lss);
        cout << "Case " << ++tc << ": " << lss << " " << res << nl;
    }
    return 0;
}
