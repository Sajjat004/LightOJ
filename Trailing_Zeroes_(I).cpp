/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 23-July,2021 23:08:35
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

bool isOn(int n, int at) { return (bool) (n & (1 << at)); }
int bitOn(int n, int at) { return n = n | (1 << at); }

int vis[(mxN >> 5) + 4];
vi prime;

void bitwiseSieve() {
    vis[1 >> 5] = bitOn(vis[1 >> 5], 1 & 31);
    for (int i = 4; i <= mxN; i += 2) {
        vis[i >> 5] = bitOn(vis[i >> 5], i & 31);
    }
    for (int i = 3; i * i <= mxN; i += 2) {
        if (!isOn(vis[i >> 5], i & 31)) {
            for (int j = i * i; j <= mxN; j += (2 * i)) {
                vis[j >> 5] = bitOn(vis[j >> 5], j & 31);
            }
        }
    }
    for (int i = 2; i <= mxN; ++i) {
        if (!isOn(vis[i >> 5], i & 31)) {
            prime.pb(i);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    bitwiseSieve();
    int test = Int(), tc = 0;
    while (test--) {
        ll ans = 1LL;
        ll n = Long();
        for (auto p : prime) {
        	if (p * p > n) break;
        	int k = 0;
        	while (n % p == 0) {
        		k++;
        		n /= p;
        		if (n == 0 or n == 1) break;
        	}
        	ans *= (k + 1);
        }
        if (n != 1) ans *= 2;
        ans -= 1;
        printf("Case %d: %lld\n", ++tc, ans);
    }
    return 0;
}
