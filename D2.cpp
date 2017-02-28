#include <bits/stdc++.h>
using namespace std;
int arr[10003];
int arr2[10003];
int dp[10003];
int n;
int go(int st){
	for(int i = 0; i < n; i++)
		dp[i]=1;
	int i, j, k = 0;
	int res = -1;
	for(i = st; i < n; i++)
		arr2[k++] = arr[i];
	
	for(i = 0; i < st; i++)
		arr2[k++] = arr[i];
	
	for (int i = 1; i < n; i++ )
	for (int j = 0; j < i; j++ ) 
           	if ( arr2[i] > arr2[j])
           		dp[i] = max(dp[i], dp[j] + 1);
	for (int i = 0; i < n; i++ )
    	res = max(res, dp[i]);
   return res;
}

int main() {
	int t;
	cin>>t;
	while(t--){	
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		int res = -1;
		for(int i = 0; i < n; i++)
			res = max(res, go(i));
		
		cout<<res<<endl;
	}
	return 0;
}
