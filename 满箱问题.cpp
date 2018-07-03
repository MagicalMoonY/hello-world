
#include <iostream>
using namespace std;
 
int n, V, hfV;
int v[50001];
bool f[50001];
 
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> v[i];
	for(int i=1; i<=n; i++) V += v[i];
	hfV = V/2;
	f[0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=hfV; j>=v[i]; j--)
			f[j] = f[j] || f[j-v[i]];
	int maxv = 0;
 	for(int i=hfV; i>=1; i--)
		if(f[i]) {
			maxv = i;
			break;
		}
	if(V % 2 == 0) cout << (hfV - maxv) * 2 << endl;
	else cout << V - 2 * maxv << endl;
	return 0;
	} 

