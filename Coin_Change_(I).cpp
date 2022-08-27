/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 20-March,2021 07:33:54 AM
----------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef  long long               ll;
typedef  long double             ld;
typedef  unsigned long long      ull;
typedef  pair<int, int>          pii;
typedef  pair<ll, ll>            pll;
typedef  vector<int>             vi;
typedef  vector<ll>              vll;
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 1e3 + 5;
const int mxN     = (int) 1e6 + 6;
const ll MOD      = (ll) 100000007;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    PI          acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

ll dp[52][N];
int coin[52], c[52], n, k;

ll fun(int i, int sum) {
	if (sum == k) return 1;
	if (sum > k || i > n) return 0;
	if (dp[i][sum] != -1) return dp[i][sum];
	ll ans = 0;
	for (int k = 0; k <= c[i]; ++k) {
		ans += fun(i + 1, sum + k * coin[i]);
		ans %= MOD;
	}
	return dp[i][sum] = ans;
}

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
    	memset(dp, -1, sizeof dp);
        n = Int(), k = Int();
        for (int i = 1; i <= n; ++i) coin[i] = Int();
        for (int i = 1; i <= n; ++i) c[i] = Int();

        printf("Case %d: %lld\n", ++tc, fun(1, 0));
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
