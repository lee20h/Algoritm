#include <bits/stdc++.h>
using namespace std;

int v[101][101];
int dp[101][101];

void sol(int n, int m) {
	int a = dp[n-1][m] + v[n][m];
	int b = dp[n][m-1] + v[n][m];
	dp[n][m] = min(a,b);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> v[i][j];
		}
	}
	for (int i=1; i<m; i++) {
		for (int j=0; j<=i; j++) {
			dp[0][i] += v[0][j];
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=0; j<=i; j++) {
			dp[i][0] += v[j][0];
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			sol(i,j);
		}
	}
	cout << dp[n-1][m-1] << '\n';
}
