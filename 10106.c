#include <stdio.h>
#include <string.h>

void change(int* a, char* b){
	int len = strlen(b);
	int i, j;
	for(i=0, j=len-1; i<len; i++, j--){
		a[i] = b[j] - '0';
	}
}

int  multiply(int* a, int m, int* b, int n, int* result){
	int i, j, k = 0 ;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			result[i+j] += a[i]*b[j];
		}
	while(k <= m+n-2 || result[k] != 0){
		if(result[k]/10 > 0){
			result[k+1] += result[k]/10;
			result[k] = result[k]%10;
		}
		k++;
	}
	return k;
}

int main(){
	char a[256], b[256];
	int aa[256], bb[256], result[512];
	int m, n, len, i, flag;
	while(scanf("%s%s", a, b) != EOF){
		flag = 0;
		memset(result, 0, sizeof(int)*512);
		m = strlen(a);;
		n = strlen(b);
		change(aa, a);
		change(bb, b);
		len = multiply(aa, m, bb, n, result);
		for(i=len-1; i>=0; i--){
			if(flag == 0)
				if(result[i] != 0)
					flag = 1;
			if(flag == 1|| i == 0)
				printf("%d", result[i]);
		}
		printf("\n");
	}
	return 0;
}
