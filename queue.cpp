
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
class Queue {
public:
    vector<int> arr;
    int size;
    int qfront, rear;
    Queue() {
        size = 100001;
        qfront = rear = 0;
        arr = vector<int>(size, -1);
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return 1;
        }
        return 0;
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if(qfront == rear){
            cout <<"Queue is empty"<<endl;
            return -1;
        }
        int x = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear){
            qfront = rear = 0;
        }
        return x;
    }

    int front() {
        if(qfront == rear){
            cout <<"Queue is empty"<<endl;
            return -1;
        }
        return arr[qfront];
    }
};
class CircularQueue{
    public:
    vector<int> arr;
    int front, size, rear;

    CircularQueue(int n){
        size = n;
        arr = vector<int>(size, -1);
        front = rear = -1;
    }

    bool enqueue(int value){
        if(front == rear%size + 1){
            return 0;
        }else if(front == -1){
            front = rear = 0;
        }else{  
            rear = (rear + 1)%size;
        }
        arr[rear] = value;
        return 1;
    }

    int dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1)%size;
        }
        return ans;
    }
    int Front(){
        if(front == - 1){
            return -1;
        }else{
            return arr[front];
        }
    }
};
class Deque{
public:
    vector<int> arr;
    int front, size, rear;
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = vector<int>(size, -1);
        front = rear = -1;
    }

    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){
            return 0;
        }
        if(front == -1){
            front = rear = 0;
        }else{
            front = (front - 1+ size)%size;
        }
        arr[front] = x;
        return 1;
    }

    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){
            return 0;
        }
        if(front == -1){
            front = rear = 0;
        }else{
            rear = (rear + 1)%size;
        }
        arr[rear] = x;
        return 1;
    }

    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1)%size;
        }
        return ans;
    }

    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear){
            front = rear = -1;
        }else{
            rear = (rear - 1 + size)%size;
        }
        return ans;
    }

    int getFront()
    {
        // Write your code here
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            return 1;
        }
        return 0;
    }

    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size - 1) or (front == rear + 1)) return 1;
        return 0;
        
    }
};
input restricted queue - i/p can be taken only from 1 side i.e. rear
                        and o/p is taken from both the side
Output restricted queue - o/p can be taken only from 1 side i.e. front
                        and i/p is taken from both the side
void solve(){
    /* हर हर महादेव */
    Queue q;
    q.enqueue(2);
    cout<<q.dequeue();

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
