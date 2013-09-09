/*************************************************************************
    > File Name: 10815.c
    > Author: Conan
    > Mail: xigoss@163.com 
    > Created Time: 2013年09月07日 星期六 20时32分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 201
#define MAX 100000

static int count = 0;
static char word[MAX][SIZE];

int cmp(const void* s, const void* t){
	return strcmp((char*)s, (char*)t);
}

void strtolow(char* str){
	while(*str != '\0') {
		*str = tolower(*str);
		str++;
	}
}

void parse(char* str){
	char t[SIZE];
	int len, i, j = 0, flag = 0;
	strtolow(str);
	len = strlen(str);
	for(i=0; i<len; i++){
		if(islower(str[i])){
			t[j] = str[i];
			flag = 1;
			j++;
		}else{
			if(flag){
				t[j] = '\0';
				strcpy(word[count], t);
				j = 0;
				flag = 0;
				count++;
			} 
		}
	}
}

int main(){
	char str[SIZE+2];
	int i;
	while(fgets(str, MAX+2, stdin) != NULL){
		parse(str);
	}
	qsort(word, count, SIZE, &cmp);
	for(i=0; i<count; i++){
		if(i == 0){
			printf("%s\n", word[i]);
		}else{
			if(cmp(word[i], word[i-1]))
				printf("%s\n", word[i]);
		}
	}
	return 0;
}
