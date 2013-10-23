/*************************************************************************
    > File Name: 340.c
    > Author: xigoss
    > Mail: xigoss@163.com 
    > Created Time: Wed 23 Oct 2013 10:43:06 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(){
	int n, i, j, p, q, count = 1;
	int secret[MAX], br[MAX];
	int flag1[MAX], flag2[MAX];

	while(scanf("%d", &n) != EOF){
		if(n == 0)break;
		printf("Game %d:\n", count);
		for(i=0; i<n; i++) 
			scanf("%d", &secret[i]);

		while(1){
			for(i=0; i<n; i++) 
				scanf("%d", &br[i]);
			if(br[0] == 0)
				break;
			p = 0;
			q = 0;
			memset(flag1, 0, sizeof(int)*n);
			memset(flag2, 0, sizeof(int)*n);

			for(i=0; i<n; i++){
				if(secret[i] == br[i]){
					p++;
					flag1[i] = 1;
					flag2[i] = 1;
				}
			}
			for(i=0; i<n; i++)
				for(j=0; j<n; j++){
					if(flag1[i] == 1)break;
					if(flag2[j] == 1)continue;
					if(secret[i] == br[j]){
						q++;
						flag1[i] = 1;
						flag2[j] = 1;
					}
				}
			printf("    (%d,%d)\n", p, q);
		}
		count++;
	}
	return 0;
}
