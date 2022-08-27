/*....Bismillahir Rahmanir Rahim....*/
/**
      Author  :  Md. Sajjat Hosen
      Created :  Friday, 25 April, 2020
**/
/*....! TRY ONCE MORE !....*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long               ll;
typedef long double             ld;
typedef unsigned long long      ull;
typedef pair<int, int>          pii;
typedef pair<ll, ll>            pll;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }
inline float Float() { float x; scanf("%f", &x); return x; }
inline double Double() {double x; scanf("%lf", &x); return x; }

//    Moves : L, U, R, D, LU, RU, RD, LD.
int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N          = (int)2e5 + 5;
const int maxN       = (int)1e6 + 6;
const ll  Mod        = (ll)1e9 + 7;
const int inf        = (int)2e9;
const ll  Inf        = (ll)1e18;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     Int         Int()
#define     Long        Long()
#define     Float       Float()
#define     Double      Double()
#define     all(x)      x.begin(), x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mp          make_pair
#define     TN          typename
#define     pie         acos(-1.0)
#define     nl          '\n'
#define     Fast_Read   ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

/*...... ! Code start from here ! ......*/
ll a[N], node[4*N];
int n, q;

void build(int at, int l, int r) {
    if (l == r) {
        node[at] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*at, l, mid);
    build(2*at + 1, mid + 1, r);
    node[at] = node[2*at] + node[2*at + 1];
}

void update(int at, int l, int r, int pos, int val) {
    if (pos < l || r < pos) return;
    if (l == r) {
        node[at] += val;
        a[l] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(2*at, l, mid, pos, val);
    update(2*at + 1, mid + 1, r, pos, val);
    node[at] = node[2*at] + node[2*at + 1];
}

ll query(int at, int l, int r, int x,  int y) {
    if (y < l || x > r) return 0;
    if (x <= l && r <= y) return node[at];
    int mid = (l + r) >> 1;
    ll u = query(2*at, l, mid, x, y);
    ll v = query(2*at + 1, mid + 1, r, x, y);
    return u + v;
}

int main() {
    //Fast_Read
    //freopen("input.txt", "r", stdin);
    int test = Int, tc = 0;
    while (test--) {
        n = Int, q = Int;
        for (int i = 1; i <= n; i++) {
            a[i] = Long;
        }
        build(1, 1, n);
        bool ok = true;
        while (q--) {
            int x, y;
            ll v, ans;
            x = Int;
            if (x == 1) {
                y = Int;
                if (ok) {
                    printf("Case %d:\n", ++tc);
                    ok = false;
                }
                printf("%lld\n", a[y + 1]);
                update(1, 1, n, y + 1, -a[y + 1]);
            } else if (x == 2) {
                y = Int, v = Long;
                update(1, 1, n, y + 1, v);
            } else {
                x = Int, y = Int;
                ans = query(1, 1, n, x + 1, y + 1);
                if (ok) {
                    printf("Case %d:\n", ++tc);
                    ok = false;
                }
            printf("%lld\n", ans);
            }
        }
    }
    return 0;
}

/*................END.................*/
