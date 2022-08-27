
/**
*     => Md. Sajjat Hosen
*     => Department of Computer Science and Engineering
*     => Bangabandhu Sheikh Mujibur Rahman Science and Technology University
**/

/*..................! TRY ONCE MORE !..................*/

/*...Part - 01...*/

#include <bits/stdc++.h>
using namespace std ;

/*...Part - 02...*/

typedef long long               ll ;
typedef long double             ld ;
typedef unsigned long long      ull ;
typedef pair<int,int>           pii ;
typedef pair<ll,ll>             pll ;
typedef vector<int>             vi ;
typedef vector<ll>              vll ;
typedef vector<vector<int>>     vvi ;

int Int(){int x ; scanf("%d",&x) ; return x ;}
ll Long(){ll x ; scanf("%lld",&x) ; return x ;}
float Float(){float x ; scanf("%f",&x) ; return x ;}
double Double(){double x ; scanf("%lf",&x); return x;}

/*...Part - 03...*/
/*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

/*...Part - 04...*/
/*...Needed to change according to problem requirements...*/

const int N          = (int)1000 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;

/*..........................................................*/
/*...Part - 05...*/

#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     Int         Int()
#define     Long        Long()
#define     Float       Float()
#define     Double      Double()
#define     all(x)      x.begin() , x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

/*...Part - 06...*/
/*...... ! Code start from here ! ......*/


vector < int > vec[N];
bool vis[N];
int n, m, a[N], x, y, ans, sum, k, flag, p;
void dfs(int p){
    vis[p] = true;
    //cout << p << endl;
    ans += a[p];
    //cout << ans << endl;
    x++;
    for(auto v : vec[p]){
        if(!vis[v]) dfs(v);
    }
    return;
}

int main(){
    //freopen("input.txt","r",stdin);
    int test = Int , tc = 0 ;
    while(test--){
        flag = 0;
        sum = 0;
        memset(vis, 0 , sizeof(vis));
        memset(vec, 0, sizeof(vec));
        n = Int;
        m = Int;
        for(int i = 1; i <= n; ++i){
            a[i] = Int;
            sum += a[i];
        }
        for(int i = 1; i <= m; i++){
            x = Int;
            y = Int;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        if(sum % n == 0){
            k = sum / n;
        }
        else{
            printf("Case %d: No\n", ++tc);
            continue;
        }

        for(int i = 1; i <= n; i++){
            ans = 0;
            x = 0;
            if(!vis[i]){
                dfs(i);
                if(ans / x != k){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            printf("Case %d: No\n", ++tc);
        else
            printf("Case %d: Yes\n", ++tc);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/
