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
class quick_sort{
	public:
	void sort(vi &A){
		int i, n = A.size();
		quicksort(A, 0, n-1);
	}
	void quicksort(vi &A, int lo, int hi){
		if(lo>=hi) return;
		int p = partition(A, lo, hi);
		quicksort(A, lo, p-1);
		quicksort(A, p+1, hi);
	}
	int partition(vi &A, int lo, int hi){
		int pvt = lo + rand()%(hi-lo);
		swap(A[hi], A[pvt]);
		int pivot = A[hi];
		int i;
		int p = lo;
		Fo(i, lo, hi){
			if(A[i] <= pivot)
				swap(A[p++], A[i]);
		}
		swap(A[p], A[hi]);
		return p;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	int i,n,k,j;
	vi x = {1,4,3,9,2,7,100,2};
	quick_sort A;
	A.sort(x);
	for(int y: x) cout << y << " " ; cout << endl;
	

	return 0;
} 
