/*************************************************************************
    > File Name: 10115.c
    > Author: Conan
    > Mail: xigoss@163.com 
    > Created Time: 2013年09月17日 星期二 10时27分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sub[50][81];
char rep[50][81];

void automatic(int n, char* str){
	int i = 0, j;
	char* p;
	char* strtmp;
	strtmp = (char*)malloc(256);
	while(i < n){
		if((p = strstr(str, sub[i])) != NULL){
			j = p - str;
			strncpy(strtmp, str, j);
			strtmp[j] = '\0';
			strcat(strtmp, rep[i]);
			p += strlen(sub[i]);
			strcat(strtmp, p);
			strcpy(str, strtmp);
		}else{
			i++;
		}
	}
}

int main(){
	char str[256];
	int n, i;
	while(scanf("%d", &n) != EOF){
		getchar();
		if(n == 0) return 0;
		for(i=0; i<n; i++){
			gets(sub[i]);
			gets(rep[i]);
		}
		gets(str);
		automatic(n, str);
		printf("%s\n", str);
	}
	return 0;
}
