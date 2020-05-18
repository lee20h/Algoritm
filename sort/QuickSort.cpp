#include <iostream>
using namespace std;

int N;
int v[10001];
int ans;
int partition(int p, int r)
{
   int x = v[r];
   int i = p - 1;
   for (int j=p; j<=r-1; j++)
 	  	if(v[j] <= x) {
	     	int temp = v[++i];
	     	v[i] = v[j];
	     	v[j] = temp;
	     	ans++;
		}
	int temp = v[i+1];
	v[i+1] = v[r];
	v[r] = temp;
	ans++;
   return i + 1;
}

void quickSort(int p, int r) {
	if (p < r) {
		int q = partition(p,r);
		quickSort(p,q-1);
		quickSort(q+1,r);
	}
}

int main() {
	cin >> N;
	for (int i=1; i<=N; i++)
		cin >> v[i];
	quickSort(1,N);
	cout << ans;
}
