
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

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;

/*..........................................................*/
/*...Part - 05...*/

#define     Int         Int()
#define     Long        Long()
#define        Float     Float()
#define     Double     Double()
#define     all(x)      x.begin() , x.end()
#define     sz(x)       (int)x.size()
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

/*...Part - 06...*/
/*...... ! Code start from here ! ......*/



int main(){
    //freopen("input.txt","r",stdin);
    int test = Int , tc = 0 ;
    float ab, bc, ca, rati, ans;
    while(test--){
        ab = Double;
        bc = Double;
        ca =  Double;
        rati = Double;
        ans = (sqrt(rati) / sqrt(rati + 1.0)) * ab;
        printf("Case %d: %f\n", ++tc, ans);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/
