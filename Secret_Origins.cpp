/*  Bismillahir Rahmanir Rahim
    Author  :  Md. Sajjat Hosen
    Created :  Friday, 05 June, 2020 */

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N       = (int) 2e5 + 5;
const int maxN    = (int) 1e6 + 6;
const int Mod     = (int) 1e9 + 7;

#define     debug(x)    cerr << #x << " = " << x << '\n';
#define     all(x)      x.begin(), x.end()
#define     szof(x)       (int) x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     mp          make_pair
#define     TN          typename
#define     nl          '\n'
#define     Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

inline int add(int a, int b) { a += b; return a >= Mod ? a - Mod : a < 0 ? a + Mod : a; }
inline int mult(int a, int b) { return (ll) a * b % Mod; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

bool isOn(ll n, int at) { return (bool) (n & (1 << at)); }
ll bitOn(ll n, int at) { return n = n | (1 << at); }
ll bitOff(ll n, int at) { return n = n & ~(1 << at); }

void binary(ll n) {
    vi ans;
    while (n) {
        //printf("%d", n % 2);
        int x = n % 2;
        ans.pb(x);
        n /= 2;
    }
    reverse(all(ans));
    for (auto i : ans) {
        printf("%d", i);
    }
    printf("\n");
}


int main() {
    //Fast_IO
    //clock_t tStart = clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int test = Int(), tc = 0;
    while (test--) {
        ll n = Long();
        int lst, fst = 0;
        for (int i = 0; i <= 40; ++i) {
            if (isOn(n, i) == 1 && isOn(n, i + 1) == 0) {
                 n = bitOff(n, i);
                 n = bitOn(n, i + 1);
                 lst = i - 1;
                 break;
             }
        }
        while(lst > fst) {
            if (isOn(n, lst) == 0) {
                lst--;
            } else if (isOn(n, fst) == 1) {
                fst++;
            } else {
                n = bitOff(n, lst);
                n = bitOn(n, fst);
                lst--;
                fst++;
            }
        }
        printf("Case %d: %lld\n", ++tc, n);
    }
    //fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
