#include <bits/stdc++.h>
using namespace std;
// https://community.topcoder.com/stat?c=problem_statement&pm=1889
#define ll long long
ll way[103][103];
bool bad[103][103];
int val[4];
class AvoidRoads{
	int n, m, k;
	public:
	void read(){
		//widht, height, # of bad strings
		cin >> n >> m >> k;
		int i = 0, j;
		for(i = 0; i <= n; i++)
		for(j = 0; j <= m; j++)
			bad[i][j] = way[i][j] = 0;
		cin.ignore();
		string s, x;
		i = 0;
		while(k--){
			getline(cin, s);
			istringstream ss(s);
			i = 0;
			while(getline(ss, x, ' ')){
				val[i++] = stoi(x);
			}
			int x1 = min(val[0], val[2]);
			int x2 = max(val[0], val[2]);
			int y1 = min(val[1], val[3]);
			int y2 = max(val[1], val[3]);

            //this code works even when  |x1-x2| + |y1-y2| > 1
			for(i = x1; i  <= x2; i++)
			for(j = y1; j  <= y2; j++)
				bad[i][j] = 1;
		}
	}
	
	// O(n*m) time complexity
	ll numWays(){
		int i, j;
        for(i = 0; i <= n; i++) {
            way[i][0] = 1;
            if(bad[i][0] and bad[i+1][0]) break; 
        }
        for(i = 0; i <= m; i++) {
            way[0][i] = 1;
            if(bad[0][i] and bad[0][i+1]) break; 
        }
		
		for(i = 1 ; i <= n; i++){
			for(j = 1; j <= m; j++){
				if(!bad[i][j] or !bad[i-1][j]);
                    way[i][j] += way[i-1][j];
                if(!bad[i][j] or !bad[i][j-1]);
                    way[i][j] += way[i][j-1];
			}
		}
		return way[n][m];
	}
};
int main() {
	AvoidRoads a;
	a.read();
	cout << a.numWays() << endl;
	return 0;
}
