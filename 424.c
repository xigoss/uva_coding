#include<stdio.h>
#include<string.h>

#define MAX 102

int main(){
	char num[MAX];
	int result[MAX] = {0};
	int i, j, len, canshow = 0, carry, tmp;
	freopen("t.txt", "r", stdin);
	while(scanf("%s", num) != EOF){
		if(strcmp(num,"0") == 0) break;
		len = strlen(num);
		i = MAX - 1;
		j = len - 1;
		carry = 0;
		while(j >= 0){
			tmp = result[i] + num[j] - '0' + carry;
			carry = tmp>9?1:0;
			result[i] = tmp%10;
			j--;
			i--;
		}
		while(carry == 1){
			tmp = result[i] + carry;
			carry = tmp>9?1:0;
			result[i] = tmp%10;
			i--;
		}	
	}
	
	for(i=0; i<MAX; i++){
		if(canshow){
			printf("%d", result[i]);
			continue;
		}
		if(result[i] > 0){
			printf("%d", result[i]);
			canshow = 1;
		}
	}

	printf("\n");
	return 1;
}