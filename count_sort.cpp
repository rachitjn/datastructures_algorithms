#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
class count_sort{
	vi ans,cnt;
	public:
	void sort(vi &A){
		int i, n = A.size();
		int max_val = accumulate(all(A),0,[](int x, int y){return max(x, y);});
		ans = vi(n, 0);
		cnt = vi(max_val+1, 0);
		for(int x: A) cnt[x]++;
		Fo(i, 1, max_val+1) cnt[i] += cnt[i-1];
		Fo(i, n-1, -1){
			ans[--cnt[A[i]]] = A[i];
		}
	}	
	void print(){
		for(int x: ans) cout << x << " "; cout << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	vi A = {9,0,3,4,5,9};
	count_sort my;
	my.sort(A);
	my.print();
	A = {9,0,1,0,3,4,5,9,10};
	my.sort(A);
	my.print();
	return 0;
} 

