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

class count_sort{
	//stable-sorts a vector of pair on order of first.
	vi cnt;
	vpii ans;
	public:
	void sort(vpii &A){
		int i, n = A.size();
		int max_val = accumulate(all(A),0,[](int x, pii y){return max(x, y.F);});
		ans = vpii(n, {0,0});
		cnt = vi(max_val+1, 0);
		for(pii x: A) cnt[x.F]++;
		Fo(i, 1, max_val+1) cnt[i] += cnt[i-1];
		Fo(i, n-1, -1){
			ans[--cnt[A[i].F]] = A[i];
		}
		//update the input vector
		fo(i, n) A[i] = ans[i];
	}	
	void print(){
		for(pii x: ans) cout << x.S << " "; cout << endl;
	}
};
class radix_sort{
	//stable sorts vector A of ints
	//r = log2(max(n)) bits in a group b/r iterations
	//space needed is O(max(2^r))
	vpii res;
	count_sort obj;
	public:
	void sort(vi &A){
		int i , n = A.size();
		res.clear();
		for(int x: A) res.pb({0,x}); 
		int r = log2(n);
		r++;
		int allone = 1<<r; allone--;
		int max_val = accumulate(all(A),0,[](int x, int y){return max(x, y);});
		int iter = 1+log2(max_val); iter /= r; iter += iter%r != 0;
		while(iter--){
			for(auto& item: res){
				item.F = allone&item.S;
			}
			allone *= 1<<r;
			obj.sort(res);
		}
		//update the input vector
		fo(i, n) A[i] = res[i].S;
	}
	void print(){
		for(pii x: res) cout << x.S << " " ; cout << endl;
	}
	
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	vi A = {3,4,5,1,0,8,4};
	//radix sort 
	radix_sort my;
	my.sort(A);
	my.print();
	
	//stable count sort on pair's first value
	vpii x = { {1,20}, {2, 5}, {0, 7}, {1,19} };
	count_sort o;
	o.sort(x);
	o.print();
	

	return 0;
} 

