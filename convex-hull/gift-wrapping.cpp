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
typedef pii point;
 
// Input: ordered triplet (p, q, r).
// Output: Their Orientation
// {0,1,2} represent {colinear, clockwise, anti-clockwise} resepectively.
int orientation(point p, point q, point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) 
    	return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
vpii compute(vpii points){
    vector<point> hull;
	int n = points.size();
    if (n < 3) return hull;
    int l = 0, i;
    Fo(i, 1, n)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do{
        hull.pb(points[p]);
        q = (p+1)%n;
        //find the next most clockwise point
		fo(i, n)
           if (orientation(points[p], points[i], points[q]) == 1)
               q = i;
        p = q;
    } while (p != l);// Completed the hull
 	return hull;
}
int main()
{
    ios_base::sync_with_stdio(0);
    vpii points;
    int n, u, v, i;
    cin >> n;
    fo(i, n) cin >> u >> v, points.pb({u, v});
    vpii hull = compute(points);
    for(auto cur: hull) cout << cur.x << " " << cur.y << endl;
    return 0;
}
