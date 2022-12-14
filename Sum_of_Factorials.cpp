/*==========================================
    Bismillahir Rahmanir Rahim
    Author  : Md. Sajjat Hosen
    Created : 16-January,2021 09:02:50 PM
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
#define    Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template<TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template<TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

vll v(22, 0);

void love() {
    v[1] = v[0] = 1;
    for (int i = 2; i <= 20; ++i) {
        v[i] = (ll)i * v[i - 1];
        //debug(v[i])
    }
}

int main() {
    //Fast_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    love();
    while (test--) {
        vi ans;
        ll n = Long();
        int x = 20;
        while (x >= 0) {
            //debug(x)
            if (v[x] <= n) {
                n -= v[x];
                ans.pb(x);
            }
            x--;
        }
        printf("Case %d: ", ++tc);
        if (n == 0) {
            //debug(n)
            sort(all(ans));
            int k = szof(ans);
            for (int i = 0; i < k - 1; ++i) {
                printf("%d!+", ans[i]);
            }
            printf("%d!\n", ans[k - 1]);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
