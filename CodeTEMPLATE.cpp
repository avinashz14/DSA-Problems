//??......LekhanKarya..Nithost_16??
/********************************************************************************************************
██████████████████████████████████████████████████████████████████████████████████████████████████████████
████████████████████████████████                                ██████████████████████████████████████████
██████████████████████████████    ████████████████████████████    ████████████████████████████████████████
██████████████████████████████    ████████████████████████████    ████████████████████████████████████████
██████████████████████████████    ████████████████████████████    ████████████████████████████████████████
██████████████████████████████    ██         █████         ███    ████████████████████████████████████████
██████████████████████████████    ██          ███          ███    ████████████████████████████████████████
███████████████████████████  █    ██  <ARE>   ███   <YOU>  ███    █  █████████████████████████████████████
██████████████████████████  ██    ██         █████         ███    ██  ████████████████████████████████████
██████████████████████████ ███    ██        ███████        ███    ███ ████████████████████████████████████
██████████████████████████  ██    ██       █████████       ███    ██  ████████████████████████████████████
███████████████████████████ ██    ████████████████████████████    ██ █████████████████████████████████████
████████████████████████████ █    ██████████  GOOD  ██████████    █ ██████████████████████████████████████
██████████████████████████████    ████████████████████████████    ████████████████████████████████████████
██████████████████████████████    ████████████████████████████    ████████████████████████████████████████
████████████████████████████████  ███████████ <BRO> ██████████  ██████████████████████████████████████████
██████████████████████████████████      █████████████████     ████████████████████████████████████████████
████████████████████████████████████    █████████████████   ██████████████████████████████████████████████
████████████████████████████████████████    █████████    █████████████████████████████████████████████████
██████████████████████████████████████████     ███     ███████████████████████████████████████████████████
██████████████████████████████████████████████     ███████████████████████████████████████████████████████
██████████████████████████████             ARTIST@NITHOST_16       ████████████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████████████████████████
*********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define testcase ll t=1; cin>>t; while(t--)
#define ll long long int
#define ull unsigned long long
#define endl "\n"
#define PI 3.1415926535897932384626
#define mod 1000000007
#define vi vector<int>
#define vii vector< vector<long long int> >
#define vpi vector< pair<long long int,long long int> >
typedef vector<vector<ll> > matrix;
typedef pair<int, int> pi; 
#define mp(a, b) make_pair(a, b)
#define pb(x) push_back(x)
#define ff first
#define ss second
#define siz 256
#define bc(n) __builtin_popcountll(n)
#define leadzero(a) __builtin_clz(a)        // count leading zeroes
#define trailzero(a) __builtin_ctz(a)       // count trailing zeroes
#define bitcount(a) __builtin_popcount(a)   // count set bits
#define lps(v,x) (lower_bound(all(v),x)-v.begin())
#define ups(v,x) (upper_bound(all(v),x)-v.begin())
# define rep(i,j,n) for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
const ll INF = 998244353;
typedef vector<vector<ll> > matrix;
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
 /*#################### Prime number Area upto n<=1e5 ###################*/

bool isPrime[50000000];
void sieve(long long int N)
{  
    for(int i=0; i<=N ; i++) isPrime[i]=true;
    isPrime[0]= false;
    isPrime[1]= false;
    for(int i=2; i*i<=N; i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i; j<=N; j+=i)     // mark all multiples of the i as composite no.
            {
                isPrime[j]=false;
            }
        }
    }
}        
    
vector<int> prime_numbers(int N)
{
    vector<int> prr;
    sieve(N);
    for(int i=0;i<=N; i++)
    {
        if(isPrime[i])  prr.push_back(i);    //insert all prime number upto N 
    }
    return prr;
}


//#########################################################################################
bool isAnagram(string s, string t)
 {
        int sl=s.length();
        int tl=t.length();
        
        if(sl != tl)
            return false;
        
        int alp[26]={0}; 
        
        for(int i=0; i<sl;i++)
        {
            alp[s[i]-'a']++;
        }
    
        for(int j=0; j< tl; j++)
        {
            if(!alp[t[j]-'a'])
                return false;
            alp[t[j]-'a']--;   
        }
        
        for(int i=0;i<26;i++)
        {
            if(alp[i])
                return false;
        }
        return true;   
}
//###########################################################################################
int find_largest_digit(int n)
{
    int mx = 0 ;
    while(n>0)
    {
        mx = max(mx, n%10) ;
        n/=10 ;
    }
    return mx  ;
}
//###########################################################################################
ll no_of_digits(ll n)
{
    ll ans = 0 ;
    while(n>0)
    {
        ans++ ;
        n/=10 ;
    }
    return ans ;
}
//###########################################################################################
// modulo Multiplication
ll moduloMultiplication(ll  a, ll  b,  ll  zz)
{
    ll res = 0;
    a %= zz;
    while (b)
    {
        if (b & 1)
            res = (res + a) % zz;

        a = (2 * a) % zz;

        b >>= 1;
    }
    return res;
}
//###########################################################################################

ll convert(string s)
{
    bool o = true ;
    ll ans = 0 ;
    for(ll i=0;i<s.length();i++)
    {
        ans = ans*10 + (s[i]-48) ;
    }
    return ans ;
}
//###########################################################################################
//function to calculate a^b under mod...
ll powmod(ll a,ll b, ll modulo)
{
    if(b==0 || a==1) return 1;
    ll half=powmod(a,(b/2),modulo) % modulo;
    ll full = (half*half)%modulo;

    if(b%2) return (full*a)%modulo;
    return full%modulo;
}
//#########################################################################################
//function  to calculate power of big numbers ....
ll power(ll  a, ll  b)
{
  if(b==0) return 1;
  else if(b&1)
    return a*power(a*a, (b-1)/2);
  else 
    return power(a*a, b/2);
}
//###########################################################################################
//function to calculate inverse modulo under mod...assuming gcd is 1
ll invmod(ll a,ll modulo)
{
    ll check=powmod(a,modulo-2,modulo) %modulo;
    return check;
}
//###########################################################################################
 
ll max(ll a,ll b)
{
  if (a>b) {
    /* code */
    return a;
  }
  return b;
}
//###########################################################################################
ll min(ll a,ll b)
{
  if (a<b) {
    /* code */
    return a;
  }
  return b;
}
//###########################################################################################
ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}
//###########################################################################################
ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}
//###########################################################################################
ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}
//###########################################################################################
ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}
//###########################################################################################
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
//###########################################################################################
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
//###########################################################################################
void yes()
{
  cout<<"YES"<<"\n";
}
//###########################################################################################
void no()
{
  cout<<"NO"<<"\n";
}

//###########################################################################################
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}


/*
int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}

vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
*/
//###########################################################################################
void printDivisors(int n)
{
    vector<int> res;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
              {
                   printf("%d ", i);
                  //  res.pb(i);
              }
            else
               { 
                  printf("%d %d ", i, n/i);
                 //  res.pb(i), res.pb(n/i);
               }
        }
    }
   // return res;
}

//###########################################################################################
int phi(int n)
{
    int result = n; // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p = 2; p * p <= n; ++p) {

        // Check if p is a prime factor.
        if (n % p == 0) {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
//###########################################################################################


ll count(string a, string b)
{
    ll m = a.length();
    ll n = b.length();


    ll lp[m + 1][n + 1] = { { 0 } };

    for (ll i = 0; i <= n; ++i)
        lp[0][i] = 0;

    for (ll i = 0; i <= m; ++i)
        lp[i][0] = 1;

    for (ll i = 1; i <= m; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lp[i][j] = lp[i - 1][j - 1] +
                               lp[i - 1][j];

            else
                lp[i][j] = lp[i - 1][j];
        }
    }

    return lp[m][n];
}


bool palindrome(string s)
{
    for(ll i = 0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-i-1]) return 0;

    }
    return 1;

}



int main()
{
	//fast
	clock_t launch=clock();
    ll t=1;
    //cin>>t;
    while(t--)
    {
      
    }
	//clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
	return 0;
}
