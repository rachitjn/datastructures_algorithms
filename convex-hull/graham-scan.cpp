#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define pb push_back
#define x first
#define y second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
typedef pl point;
 
point P;

point pre_top(stack<point> &S){
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}

ll f(ll x){
	return x*x;
}
ll dist(point p1, point p2){
    return f(p1.x - p2.x) + f(p1.y - p2.y);
}

// Input: ordered triplet (p, q, r).
// Output: Their orientation
// {0,1,2} represent {colinear, clockwise, anti-clockwise} resepectively.
int orient(point p, point q, point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) 
    	return 0; 
    return (val > 0)? 1: 2;
}

int compare(const void *vp1, const void *vp2){
   point *p1 = (point *)vp1;
   point *p2 = (point *)vp2;
   int cur = orient(P, *p1, *p2);
   if (cur == 0)
     return (dist(P, *p2) >= dist(P, *p1))? -1 : 1;
   return (cur == 2)? -1: 1;
}

vpl compute(vpl points){
   vpl hull;
   int n = points.size(), i;
   int ymin = points[0].y, min = 0;
   Fo(i, 1, n){
		int y = points[i].y;
		if ((y < ymin) or (ymin == y and points[i].x < points[min].x))
			ymin = points[i].y, min = i;
   }

   swap(points[0], points[min]);
   P = points[0];
   qsort(&points[1], n-1, sizeof(point), compare);
   int m = 1; 
   Fo(i, 1, n){
       while (i < n-1 && orient(P, points[i], points[i+1]) == 0)
          i++;
       points[m] = points[i];
       m++;
   }
   if (m < 3) return hull;
   stack<point> S;
   fo(i, 3)
	  S.push(points[i]);
   Fo(i, 3, m){
      while (orient(pre_top(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
   while (!S.empty()){
	   point p = S.top();   	
       hull.pb({p.x, p.y});
       S.pop();
   }
   return hull;
}

int main()
{
	ios_base::sync_with_stdio(0);
	vpl points;
	int n, u, v, i;
  clock_t t = clock();
	cin >> n;
	fo(i, n) cin >> u >> v, points.pb({u, v});
        vpl hull = compute(points);
        for(auto cur: hull) cout << cur.x << " " << cur.y << endl;
  t=clock()-t;
  cout << fixed << "Time Taken: " << (t*1.0)/CLOCKS_PER_SEC << endl;
  return 0;
}
