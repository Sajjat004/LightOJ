/*-----------------------------------
  bismillahir rahmanir rahim
  @author : md. sajjat hossen
  created : 16-October,2021 07:54:08
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

vi g[N];
int color[N];
int cnt[2];

void dfs(int u) {
    cnt[color[u]]++;
    for (auto v : g[u]) {
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            dfs(v);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int();
        vi node;
        for (int i = 1; i <= n; ++i) {
            int u = Int(), v = Int();
            g[u].pb(v);
            g[v].pb(u);
            node.pb(v);
            node.pb(u);
        }
        memset(color, -1, sizeof color);
        int res = 0;
        for (auto x : node) {
            if (color[x] == -1) {
                cnt[0] = cnt[1] = 0;
                color[x] = 0;
                dfs(x);
                res += max(cnt[0], cnt[1]);
            }
        }
        printf("Case %d: %d\n", ++tc, res);

        for (int i = 0; i < N; ++i) {
            g[i].clear();
        }
    }
    return 0;
}
