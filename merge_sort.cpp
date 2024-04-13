
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define cins(x) for (auto &i : x) cin >> i
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int, int>
#define pi 3.14159265358979323846264338327950
#define pii pair<int, int>
#define vpi vector<pii>
#define ff first
#define ss second
#define setbits(x) __builtin_popcount(x)
#define endl '\n';
#define in insert
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
int gcd(int x, int y) {return (x ? gcd(y % x, x) : y);}
int lcm(int x, int y) {return x / gcd(x, y) * y;}
vi dx = {0,0,1,-1,1,1,-1,-1};
vi dy = {1,-1,0,0,1,-1,1,-1};
const int mod = 1e9+7;
const int MAXX = 2e5+5;

//------------------------------------------------//

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
int n;
vi v(MAXX);
void merge(int left, int mid, int right){
    int sizeofone = mid-left+1;
    int sizeofsecond = right-mid;

    int arr1[sizeofone];
    int arr2[sizeofsecond];

    f(i,0,sizeofone){
        arr1[i] = v[i+left];
    }
    f(i,0,sizeofsecond){
        arr2[i] = v[i+mid+1];
    }
    int index = left, i = 0, j = 0;
    while(i < sizeofone and j < sizeofsecond){
        if(arr1[i] <= arr2[j]){
            v[index] = arr1[i];
            i++;
        }else{
            v[index] = arr2[j];
            j++;
        }
        index++;
    }
    while(i < sizeofone){
        v[index] = arr1[i];
        i++;
        index++;
    }
    while(j < sizeofsecond){
        v[index] = arr2[j];
        j++;
        index++;
    }
}
void mergesort(int begin, int end){ 
    if(begin < end){
        int mid = begin + (end - begin)/2;

        mergesort(begin, mid); // 
        mergesort(mid+1, end);

        merge(begin, mid, end);
    }
}
void solve(){
    /* हर हर महादेव */
    cin >> n;
    f(i,0,n){
        cin >> v[i];
    }
    mergesort(0, n-1);
    // T(n) = 2T(n/2) + θ(n)
    f(i,0,n){
     cout<<v[i]<<" ";
    }
    // algo is correct
}

int32_t main()
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
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
