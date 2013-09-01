#include <stdio.h>
#include <string.h>

char s[4][101];
char line1[101];
char line2[101];

void getline1(char* str){
	int i = 0, j = 0, count = -1, flag = 0;
	while(*str != '\0'){
		if(*str == '<'||*str == '>'){
			if(flag == 1){
				s[count][i] = '\0';
			}
			flag = 1;
			count++;
			i = 0;
		}else {
			line1[j++] = *str;
			if(flag == 1){
				s[count][i++] = *str;
			}
		}
		str++;
	}
	line1[--j] = '\0';
	s[3][--i] = '\0';
	printf("%s\n", line1);
}

void getline2(char* str){	
	char* p;
	strcpy(line2, str);
	p = strstr(line2, "...");
	*p = '\0';
	printf("%s%s%s%s%s\n", line2, s[2], s[1], s[0], s[3]);
}


int main(){
	int num, i = 0, j = 0;
	char str1[100][101];
	char str2[100][101];
	s[0][0] = s[1][0] = s[2][0] = s[3][0] = '\0';
	scanf("%d", &num);	
	getchar();
	while(num > 0){
		fgets(str1[i], 101, stdin);
		fgets(str2[i], 101, stdin);
		i++;
		num--;
	}
	for(j=0; j<i; j++){
		getline1(str1[j]);
		getline2(str2[j]);
	}
	return 0;
}