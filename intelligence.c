/*************************************************************************
    > File Name: intelligence.c
    > Author: Conan
    > Mail: xigoss@163.com 
    > Created Time: 2013年09月01日 星期日 20时09分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static double P, I, U;

int getanswer(char* str){
	char *p, *q, *value; 
	int flag = 0;
	double prefix = 1.00, f;
	value = (char*)malloc(64); 
	q = value;

	while((p = strchr(str, '=')) != NULL){
		str = p + 1;
		while(*str!='V'&&*str!='A'&&*str!='W'&&
				*str!='m'&&*str!='k'&&*str!='M'){
			*value++ = *str++;	
		}
		if(*str == 'm'){
			prefix = 0.001;
		}
		if(*str == 'k'){
			prefix = 1000.00;
		}
		if(*str == 'M'){
			prefix = 1000000.00;
		}
		*value = '\0';
		value = q;
		f = atof(value);
		f *= prefix;
		prefix = 1.00;

		if(*(p-1) == 'I'){
			flag += 1;
			I = f;
		}else
		if(*(p-1) == 'P'){
			flag += 2;
			P = f;
		}else{
			U = f;	
		}
	}
	return flag;
}

void printanswer(int flag){
	if(flag == 1){
		P = U * I;
		printf("P=%.2fW\n\n", P);
	}
	if(flag == 2){
		I = P / U;
		printf("I=%.2fA\n\n", I);
	}
	if(flag == 3){
		U = P / I;
		printf("U=%.2fV\n\n", U);
	}
}

int main(){
	int flag, num, i = 0, j = 0;
	scanf("%d", &num);
	getchar();
	char str[num][256];
	while(num > 0){
		fgets(str[i], 256, stdin);
		i++;
		num--;
	}
	
	for(j=0; j<i; j++){
		printf("Problem #%d\n", j+1);
		flag = getanswer(str[j]);
		printanswer(flag);
	}
	return 0;
}
