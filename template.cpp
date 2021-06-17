#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" \
                 << "\n";
#define NO cout << "NO" \
                << "\n";
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
ll mpow(ll base, ll exp);
void ipgraph(ll n, ll m);
void dfs(ll u, ll par);

const ll mod = 1'000'000'007;
const ll N = 3e5, M = N;
//=======================

vi g[N];
ll a[N];

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

vl ans;

void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;

    for (ll p = 2; p <= n; p++)
        if (prime[p])
            ans.push_back(p);
    return;
}

ll isPerfectSquare(ll x)
{
    long long left = 1, right = x;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        // Check if mid is perfect square
        if (mid * mid == x)
        {
            return mid;
        }

        // Mid is small -> go right to increase mid
        if (mid * mid < x)
        {
            left = mid + 1;
        }

        // Mid is large -> to left to decrease mid
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void prifac(ll N)
{
    ll i;
    unordered_map<ll, ll, custom_hash> fac;
    fac[1] = 1;
    for (i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll c = 0;
            while (N % i == 0)
                c++, N /= i;
            fac[i] = c;
        }
    }
    if (N > 1)
        fac[N] = 1;
}

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve()
{
    ll i, j, n, m;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/

    ll t = 1;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }

    return 0;
}

ll mpow(ll base, ll exp)
{
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(ll n, ll m)
{
    ll i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(ll u, ll par)
{
    for (ll v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}
