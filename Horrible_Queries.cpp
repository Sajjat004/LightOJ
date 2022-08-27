/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 12-January,2021 08:47:54 AM
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
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef  tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

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

int ar[N];

template<TN T> class segTree {
private:
    struct data {
        T sum, prop;
        data(int _x) { sum = prop = 0; }
    };
    vector<data> g;
    int n;

    void build(int at, int l, int r) {
        if (l == r) {
            g[at].sum = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * at, l, mid);
        build(2 * at + 1, mid + 1, r);
        g[at].sum = g[2 * at].sum + g[2 * at + 1].sum;
    } 

    void propagate(int at, int l, int r) {
        int mid = (l + r) >> 1;
        g[2 * at].sum += (g[at].prop * (mid - l + 1));
        g[2 * at + 1].sum += (g[at].prop * (r - mid));
        g[2 * at].prop += g[at].prop;
        g[2 * at + 1].prop += g[at].prop;
        g[at].prop = 0;
    }

    void update(int at, int l, int r, int L, int R, int val) {
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            g[at].sum += (val * (r - l + 1));
            g[at].prop += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (g[at].prop) propagate(at, l, r);
        update(2 * at, l, mid, L, R, val);
        update(2 * at + 1, mid + 1, r, L, R, val);
        g[at].sum = g[2 * at].sum + g[2 * at + 1].sum;
    }

    T query(int at, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return g[at].sum;
        int mid = (l + r) >> 1;
        if (g[at].prop) propagate(at, l, r);
        T u = query(2 * at, l, mid, L, R);
        T v = query(2 * at + 1, mid + 1, r, L, R);
        return u + v;
    }

public:
    segTree(int _n) {
        n = _n;
        g.resize(4 * N, 0);
        build(1, 1, n);
    }

    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    T query(int l, int r) { return query(1, 1, n, l, r); }
};

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        memset(ar, 0, sizeof ar);
        segTree<ll> ds(n);

        printf("Case %d:\n", ++tc);
        while (q--) {
            int ck = Int();
            if (ck == 0) {
                int l = Int(), r = Int(), val = Int();
                ++l, ++r;
                ds.update(l, r, val);
            } else {
                int l = Int(), r = Int();
                ++l, ++r;
                ll ans = ds.query(l, r);
                printf("%lld\n", ans);
            }
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
