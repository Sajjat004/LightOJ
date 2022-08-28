/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 12-January,2021 11:47:34 PM
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
        T mn;
        data() { mn = 0; }
    };
    vector<data> g;
    int n;

    void build(int at, int l, int r) {
        if (l == r) {
            g[at].mn = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * at, l, mid);
        build(2 * at + 1, mid + 1, r);
        g[at].mn = min(g[2 * at].mn, g[2 * at + 1].mn);
    }

    T query(int at, int l, int r, int L, int R) {
        if (R < l || r < L) return (T) INT_MAX;
        if (L <= l && r <= R) return g[at].mn;
        int mid = (l + r) >> 1;
        T u = query(2 * at, l, mid, L, R);
        T v = query(2 * at + 1, mid + 1, r, L, R);
        return min(u, v);
    }

public:
    segTree(int _n) {
        n = _n;
        g.resize(4 * N);
        build(1, 1, n);
    }

    T query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        int n = Int(), q = Int();
        for (int i = 1; i <= n; ++i) ar[i] = Int();
        segTree<int> ds(n);
        printf("Case %d:\n", ++tc);
        while (q--) {
            int l = Int(), r = Int();
            printf("%d\n", ds.query(l, r));
        }
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
