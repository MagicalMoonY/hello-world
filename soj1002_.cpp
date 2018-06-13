#include <stdio.h>
#include <string.h>

#define N 510

int main(void) {
//	freopen("in.txt", "r", stdin);

	char sa[N + 1];
	char sb[N + 1];

//	while (scanf("%s%s", sa, sb) == 2) {

	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s", sa, sb);
		
		int a[N];
		int b[N];
		int c[N + 1];

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		
		int la = strlen(sa);
		int lb = strlen(sb);		

		for (int i = 0; i < la; i++) {
			a[la - i - 1] = sa[i] - '0';
		}
		for (int i = 0; i < lb; i++) {
			b[lb - i - 1] = sb[i] - '0';
		}
		
		int lc = la > lb ? la : lb;
		int t = 0;
		for (int i = 0; i < lc; i++) {
			int x = a[i] + b[i] + t;
			c[i] = x % 10;
			t = x / 10;
		}
		if (t > 0) c[lc++] = t;
		
		for (int i = lc - 1; i >= 0; i--) {
			printf("%d", c[i]);
		}
		printf("\n");
	}

	return 0;
}

