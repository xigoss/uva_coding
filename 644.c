/*************************************************************************
    > File Name: 644.c
    > Author: Conan
    > Mail: xigoss@163.com 
    > Created Time: 2013年09月10日 星期二 10时20分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char code[9][12];

int judge(int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(strstr(code[i], code[j]) == code[i] ||
				strstr(code[j], code[i]) == code[j])
				return 0;
		}
	}
	return 1;
}

int main(){
	int i = 0, num = 1;;
	while(gets(code[i])){
		if(code[i][0] == '9'){
			if(judge(i)){
				printf("Set %d is immediately decodable\n", num);
			}else{
				printf("Set %d is not immediately decodable\n", num);
			}
			i = 0;
			num++;
		}else{
			i++;
		}
	}
}
