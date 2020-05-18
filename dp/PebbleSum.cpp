#include <bits/stdc++.h>
using namespace std;

int v[3][101];
int dp[4][101];

void pebble(int n) {
	for (int i=0; i<4; i++) {
		if(i==3) dp[i][0] = v[0][0] + v[2][0];
		else
			dp[i][0] = v[i][0];
	}
	for (int i=1; i<n; i++) {
		for (int j=0; j<4; j++) {
			if (j==0) dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + v[j][i];
			else if (j==1) dp[1][i] = max(max(dp[0][i-1], dp[2][i-1]),dp[3][i-1]) + v[j][i];
			else if (j==2) dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + v[j][i];
			else dp[3][i] = dp[1][i-1] + v[0][i] + v[2][i];
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i=0; i<3; i++) {
		for (int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	pebble(n);
	int ans = 0;
	for (int i=0; i<4; i++) {
		ans = max(ans, dp[i][n-1]);
	}
	cout << ans;
}
