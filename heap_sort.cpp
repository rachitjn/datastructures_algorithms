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
class heap{
	int size;
	vi arr;
	#define L(x) 2*x+1
	#define R(x) 2*x+2
	public:
	heap() {size = 0; arr.clear(); }
	heap(vi &a) {
		size = a.size();
		int i;
		fo(i, size) arr.pb(a[i]);
	}
	void heapify(int pos){
		int to = pos;
		int l = L(pos), r = R(pos);
		if(l < size and arr[to]<arr[l]) to = l;
		if(r < size and arr[to]<arr[r]) to = r;
		if(to != pos) swap(arr[to], arr[pos]), heapify(to);
	}
	void correct(int pos){
		if(pos == 0) return;
		int p = (pos-1)/2;
		if (arr[p]<arr[pos]) swap(arr[p], arr[pos]), correct(p);
	}
	int extract(){
		if(size==0)return -1;
		int ans = arr[0];
		arr[0] = arr[size-1]; size--;
		heapify(0);
		return ans;
	}
	void build(){
		int i, n = arr.size();
		size = 1;
		Fo(i, 1, n){
			correct(size);
			size++;
		}
	}
	void sort(){
		int i;
		int n = arr.size();
		fo(i, n) {
			arr[size-1] = extract();
		}
	}
	void print(){
		for(int x: arr) cout << x << " " ; cout << endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j;
	vi x = {1,3,4,2,9,3,0,19,2};
	heap A(x);
	A.build();
	A.sort();
	A.print();
	return 0;
} 
