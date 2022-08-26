/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 21-January,2021 11:30:15 PM
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
const ll MOD      = (ll) 1e9 + 7;

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

int main() {
    Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = 1, tc = 0;
    cin >> test;
    while (test--) {
        double r1, r2, r3, ab, bc, ca, temp, ag1, ag2, ag3, ar1, ar2, ar3;
        cin >> r1 >> r2 >> r3;
        ab = r1 + r2;
        bc = r2 + r3;
        ca = r3 + r1;
        //debug(ab)
        temp = (ab * ab + ca * ca - bc * bc) / (2.0 * ab * ca);
        ag1 = acos(temp);
        temp = (ab * ab + bc * bc - ca * ca) / (2.0 * ab * bc);
        ag2 = acos(temp);
        temp = (bc * bc + ca * ca - ab * ab) / (2.0 * bc * ca);
        ag3 = acos(temp);

        ar1 = (ag1 * r1 * r1) / 2.0;
        ar2 = (ag2 * r2 * r2) / 2.0;
        ar3 = (ag3 * r3 * r3) / 2.0;

        double s = (ab + bc + ca) / 2.0;

        double totalarea = sqrt(s * (s - ab) * (s - bc) * (s - ca));
        double ans = totalarea - ar1 - ar2 - ar3;
        //debug(ans)
        cout << "Case " << ++tc << ": " << fixed << setprecision(10) << ans << nl;
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
