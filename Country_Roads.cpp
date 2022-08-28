/*---------------------------------------
   BISMILLAHIR RAHMANIR RAHIM
   AUTHOR : Md. Sajjat Hossen
   TIME : 17-June,2021 09:33:31 PM
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

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

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
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

vector<pii> g[501];
int dis[N];

void dijkstra(int src, int n) {
    for (int i = 1; i <= n; ++i) dis[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int du = pq.top().ff;
        int u = pq.top().ss;
        pq.pop();
        if (du != dis[u]) continue;
        for (auto x : g[u]) {
            int v = x.ff;
            int w = x.ss;
            if (dis[v] > dis[u] and dis[v] > w) {
                dis[v] = max(dis[u], w);
                // error(u, v, dis[v])
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    // Fast_IO
    // clock_t tStart = clock();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), m = Int();
        for (int i = 1; i <= m; ++i) {
        	int u = Int(), v = Int(), w = Int();
        	++u, ++v;
        	g[u].pb({v, w});
        	g[v].pb({u, w});
        }
        int s = Int();
        ++s;
        dijkstra(s, n);
       
        printf("Case %d:\n", ++tc);
        for (int i = 1; i <= n; ++i) {
        	if (dis[i] == INF) printf("Impossible\n");
        	else printf("%d\n", dis[i]);
        }

        for (int i = 1; i <= n; ++i) g[i].clear();
    }
    // fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
