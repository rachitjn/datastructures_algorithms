#include <bits/stdc++.h>
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
using namespace std;

struct Point{
    double x, y;
};

Point *hullSet;
int h=0;

int f(Point A, Point B, Point X){
    int sign = (A.y-B.y)*X.x + (B.x-A.x)*X.y + (B.y*A.x-A.y*B.x);
    if(sign<0) return -1;
    if(sign>0) return 1;
    return 0;
}

int area(Point p, Point q, Point r){
    return abs( p.x*(q.y-r.y) + q.x*(r.y-p.y) + r.x*(p.y-q.y) );
}


void FindHull(Point *point, int n, Point A, Point B){
	int i;
    if(n<=0) return;
    int index=0, max_dis, temp_dis;
    fo(i, n){
        temp_dis = area(A, B, point[i]);
        if(i==0) max_dis=temp_dis;
        else if(temp_dis > max_dis){
            max_dis = temp_dis;
            index = i;
        }
    }
    hullSet[h++]=point[index];
    Point C = point[index];
    Point G;
    G.x = (A.x + B.x + C.x)/3;
    G.y = (A.y + B.y + C.y)/3;
    int sign = f(A, C, G);
    Point *point_pos = new Point[n];
    Point *point_neg = new Point[n];
    int p=0, q=0;
    fo(i, n)
        if(sign*f(A,C,point[i]) < 0) point_pos[p++]=point[i];
    
    sign = f(B, C, G);
    fo(i, n)
        if(sign*f(B,C,point[i]) < 0) point_neg[q++]=point[i];
    
    FindHull(point_pos, p, A, C);
    FindHull(point_neg, q, C, B);   
}

int n;
int main(){
    clock_t t = clock();
    int i;
    cin >> n;
    Point *point = new Point[n];
    hullSet = new Point[n];
    int lmost=0, rmost=0;
    for(int i=0;i<n;i++){
        cin >> point[i].x >> point[i].y;
        if(point[i].x < point[lmost].x) lmost=i;
        if(point[i].x > point[rmost].x) rmost=i;
    }

    
    Point *point_pos = new Point[n];
    Point *point_neg = new Point[n];
    
    int A,B,C;
    A = point[lmost].y - point[rmost].y;
    B = -point[lmost].x + point[rmost].x;
    C = point[rmost].y*point[lmost].x - point[lmost].y*point[rmost].x;
    
    int p=0, q=0, val;
    fo(i, n){
        if(i!=lmost && i!=rmost){
            val = A*point[i].x + B*point[i].y + C;
            if(val>0){
                point_pos[p++]=point[i];
            }
            if(val<0){
                point_neg[q++]=point[i];
            }
        }
    }
    
    hullSet[h++] = point[lmost];
    hullSet[h++] = point[rmost];

    FindHull(point_pos, p, point[lmost], point[rmost]);
    FindHull(point_neg, q, point[lmost], point[rmost]);
    fo(i, h){
        Point cur = hullSet[i];
        cout << cur.x << " " << cur.y << endl;
    }

    t=clock()-t;
    cout << fixed << "Time Taken: " << (t*1.0)/CLOCKS_PER_SEC << endl;
    return 0;
}