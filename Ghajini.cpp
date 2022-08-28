/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 15-August,2020 11:33:58 PM
==========================================*/

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
typedef  tree<int, null_type, less<int>,
         rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef  tree<int, null_type, less_equal<int>,
         rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;

#define    debug(x)    cerr << #x << " = " << x << '\n';
#define    all(x)      x.begin(), x.end()
#define    szof(x)     (int) x.size()
#define    ff          first
#define    ss          second
#define    pb          push_back
#define    mp          make_pair
#define    pie         acos(-1.0)
#define    TN          typename
#define    nl          '\n'
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int ar[N];

struct SegTree {
    struct data {
        int mx, mn;
        data() {
            mx = 0;
            mn = INT_MAX;
        }
    };

    vector<data> g;
    SegTree() {
        g.resize(4 * N);
    }

    void build(int at, int l, int r) {
        if (l == r) {
            g[at].mn = g[at].mx = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * at, l, mid);
        build(2 * at + 1, mid + 1, r);
        g[at].mn = min(g[2 * at].mn, g[2 * at + 1].mn);
        g[at].mx = max(g[2 * at].mx, g[2 * at + 1].mx);
    }

    int query_mx(int at, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return g[at].mx;
        int mid = (l + r) >> 1;
        int u = query_mx(2 * at, l, mid, L, R);
        int v = query_mx(2 * at + 1, mid + 1, r, L, R);
        return max(u, v);
    }

    int query_mn(int at, int l, int r, int L, int R) {
        if (R < l || r < L) return INT_MAX;
        if (L <= l && r <= R) return g[at].mn;
        int mid = (l + r) >> 1;
        int u = query_mn(2 * at, l, mid, L, R);
        int v = query_mn(2 * at + 1, mid + 1, r, L, R);
        return min(u, v);
    }
};

int main() {
    //Fast_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), d = Int();
        for (int i = 1; i <= n; ++i) ar[i] = Int();
        int ans = 0;
        SegTree ds;
        ds.build(1, 1, n);
        for (int i = 1; i < n - d + 1; ++i) {
            int mx = ds.query_mx(1, 1, n, i, i + d - 1);
            int mn = ds.query_mn(1, 1, n, i, i + d - 1);
            ans = max(ans, mx - mn);
        }
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
