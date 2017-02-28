#include <iostream>
using namespace std;
// https://community.topcoder.com/stat?c=problem_statement&pm=1259
class ZigZag{
	int *a, n, *dp[2];
	public:
	ZigZag(int *b, int x){
		n = x;
		a = new int[n];
		//dp[0][i] = max length starting from i and beginning with -ve
		//dp[1][i] = max length starting from i and beginning with +ve
		dp[0] = new int[n];
		dp[1] = new int[n];
		int i;
		for(i = 0; i < n; i++) a[i] = b[i], dp[0][i] = dp[1][i] = 0;
	}
	
	// O(N^2) time complexity
	int longestZigZag(){
		int i, j;
		for(i = n-1 ; i >= 0; i--){
			dp[0][i] = dp[1][i] = 1;			
			for(j = i+1; j < n; j++){
				if(a[i] < a[j]) update(dp[1][i], 1 + dp[0][j]); 
				else if(a[i] > a[j]) update(dp[0][i], 1 + dp[1][j]); 
			}
		}
		int ans = 0;
		for(i = 0; i < n; i++) update(ans, dp[0][i]), update(ans, dp[1][i]);
		return ans;
	}
	void update(int &x, int y){
		if(x < y) x = y;
	}
	
};
int main() {
	int i, n, *a;
	cin >> n;
	a = new int[n];
	for(i = 0; i < n; i++) cin >> a[i];
	ZigZag sol(a, n);
	cout << sol.longestZigZag() << endl;
	
	
	
	return 0;
}