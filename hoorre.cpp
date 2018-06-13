#include <stdio.h>
#include <string.h>

int n;
int a[12];
int c[12][12];

int main() {
	for (; ; ) {
		scanf("%d", &n);
		if (n == 0) break;
		
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}

		// µÚ1ÁÐ 
		if (a[1] == 0) {
			for (int i = 1; i <= n; i++) {
				c[1][i] = 1;
			}
		} else {
			c[1][a[1]] = 1;
		}
		
		// µÝÍÆ
		for (int i = 2; i <= n; i++) {
			if (a[i] == 0) {
				for (int j = 1; j <= n; j++) {
					c[i][j] += c[i - 1][j - 1];
					c[i][j] += c[i - 1][j];
					c[i][j] += c[i - 1][j + 1];
				}
			} else {
				int j = a[i];
				c[i][j] += c[i - 1][j - 1];
				c[i][j] += c[i - 1][j];
				c[i][j] += c[i - 1][j + 1];
			}
		} 

		int count = 0;
		for (int i = 1; i <= n; i++) {
			count += c[n][i];
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}

