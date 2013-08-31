#include <stdio.h>
#include <string.h>

#define NONE -1
#define PALIN 0
#define MIRROR 1
#define MIRRORPALIN 2

char ma[256];
#define MA {ma['A']='A';ma['E']='3';\
		ma['H']='H';ma['I']='I';\
		ma['J']='L';ma['L']='J';\
		ma['M']='M';ma['O']='O';\
		ma['S']='2';ma['T']='T';\
		ma['U']='U';ma['V']='V';\
		ma['W']='W';ma['X']='X';\
		ma['Y']='Y';ma['Z']='5';\
		ma['1']='1';ma['2']='S';\
		ma['3']='E';ma['5']='Z';\
		ma['8']='8';}

int fun(char* str){
	int len = strlen(str);
	char *p, *q;
	int flag_p = 1, flag_m = 1;
	MA;
	p = str;
	q = str + len - 1;
	while(p <= q){
		if(*p != *q){
			flag_p = 0;
		}
		if(ma[*p] != *q){
			flag_m = 0;
		}
		p++;
		q--;
	}

	if(flag_p == 1&&flag_m == 1){
		return MIRRORPALIN;
	}
	if(flag_p == 1&&flag_m == 0){
		return PALIN;
	}
	if(flag_p == 0&&flag_m == 1){
		return MIRROR;
	}
	if(flag_p == 0&&flag_m == 0){
		return NONE;
	}
	return NONE;
}


int main(){
	char s[256];
	int flag;
	while(scanf("%s", s) != EOF){
		flag = fun(s);
		if(flag == NONE){
			printf("%s -- is not a palindrome.\n", s);
		}
		if(flag == PALIN){
			printf("%s -- is a regular palindrome.\n", s);
		}
		if(flag == MIRROR){
			printf("%s -- is a mirrored string.\n", s);
		}
		if(flag == MIRRORPALIN){
			printf("%s -- is a mirrored palindrome.\n", s);
		}
		printf("\n");
	}
	return 0;
}