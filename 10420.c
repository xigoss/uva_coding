/*************************************************************************
    > File Name: 10420.c
    > Author: xigoss
    > Mail: xigoss@163.com 
    > Created Time: Wed 23 Oct 2013 03:11:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2000
#define SIZE 77

int cmp(const void* a, const void* b){
	return strcmp((char*)a, (char*)b);
}

int main(){
	int n, i, count=0;
	char word[SIZE];
	char country[MAX][SIZE];
	scanf("%d", &n);	
	getchar();
	for(i=0; i<n; i++){
		fgets(word, 77, stdin);
		strcpy(country[i], strtok(word, " "));
	}
	qsort(country, n, SIZE, &cmp);
	
	for(i=0; i<=n; i++){
		if(i == 0){
			count = 1;
			printf("%s", country[i]);
		}else 
		if(i == n){
			printf(" %d\n", count);
		}else
		{
			if(strcmp(country[i-1], country[i]) != 0){
				printf(" %d\n", count);
				printf("%s", country[i]);
				count = 1;
			}else{
				count++;
			}
		}
	}

	return 0;
}
