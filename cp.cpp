
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define cins(x) for (auto &i : x) cin >> i
#define vi vector<ll>
#define vvi vector<vi>
#define mii map<ll, ll>
#define pi 3.14159265358979323846264338327950
#define pii pair<ll, ll>
#define vpi vector<pii>
#define ff first
#define ss second
#define setbits(x) __builtin_popcount(x)
#define endl '\n';
#define pb push_back
#define f(i, a, b) for (int i = a; i < b; i += 1)
#define rev(i, a, b, c) for (int i = a - 1; i >= b; i -= c)
#define FOR(x) for(auto it = x.begin();it!=x.end();it++)
#define COUT(x) for(auto &i : x) cout<<i<<" ";
#define MAX(x) *max_element(all(x));
#define MIN(x) *min_element(all(x));
#define SUM(x) accumulate(all(x), 0ll);

#define Y cout<<"YES"<<endl
#define N cout<<"NO"<<endl

typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

//-----------------some_fxns-------------------//

bool isSquare(int x) {int y = sqrtl(x); return x == y * y;}
bool ispow2(int x) {return (x ? !(x & (x - 1)) : 0);}
int ceils(int x, int y) {return (x >= 0 ? (x + y - 1) / y : x / y);}
int gcd(ll x, ll y) {return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y) {return x / gcd(x, y) * y;}
vi dx = {0,0,1,-1,1,1,-1,-1};
vi dy = {1,-1,0,0,1,-1,1,-1};


bool num_palindrome(ll n){
    ll ort= n,remainder,reversed=0;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if(ort == reversed){
        return true;
    }else{
        return false;
    }
}

string binary(int num,int n){
    string s;
    for(int i = n-1;i>=0;i--){
        s.push_back(((num>>i)&1)+'0');        
    }
    return s;
}

//------------------------------------------------//

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void google(int t) {cout << "Case #" << t << ": ";}

 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//--------------------------------------------SOLUTION OF THE PROBLEM--------------------------?//
void solve(){
    /* हर हर महादेव */
    ll n, q;
    cin >> n >> q;
    map<int, multiset<int>> m;
    map<int, set<int>> mp;
    while(q--){
        ll x;
        cin >>x;
        if(x == 1){
            ll a, b;
            cin >> a >> b;
            m[b].insert(a);
            mp[a].insert(b);
        }else if(x == 2){
            ll a;
            cin >> a;
            for(auto i : m[a]){
                cout<<i<<" ";
            }
            cout<<endl;
        }else{
            ll a;
            cin >> a;
            for(auto i : mp[a]){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout.setf(ios::fixed);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("Error.in", "w", stderr);
    #endif
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
