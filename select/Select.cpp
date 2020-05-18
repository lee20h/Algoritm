#include <iostream>
using namespace std;

int v[10001];
int cnt;

int partition(int p, int r)
{
   int x = v[r];
   int i = p - 1;
   for (int j=p; j<=r-1; j++)
 	  	if(v[j] <= x) {
	     	int temp = v[++i];
	     	v[i] = v[j];
	     	v[j] = temp;
	     	cnt++;
		}
	int temp = v[i+1];
	v[i+1] = v[r];
	v[r] = temp;
	cnt++;
   return i + 1;
}

int select(int p, int r, int i) //�迭 A[p..r]���� i��°�� ã�´�.
{
   if(p == r) return v[p];
   int q = partition(p, r); //QuickSort���� partition�� ����
   int k = q - p + 1;
   if(i < k) return select(p, q - 1, i);
   else if(i > k) return select(q + 1, r, i - k);
   else return v[q]; //i == k
}

int main() {
	int n, idx;
	cin >> n >> idx;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
	}
	select(1,n,idx);
	cout << cnt;
}
