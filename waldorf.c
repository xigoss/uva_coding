#include<stdio.h>
#include<string.h>
#include<ctype.h>

int a[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int b[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void findword(int m, int n, char array[50][51], char* word){
	int len, i, j, k, M, N, count;
	
	len = strlen(word);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){			
			for(k=0; k<8; k++){
				count = 0;
				if(i+a[k]*len<-1 || i+a[k]*len>m
					|| j+b[k]*len<-1 || j+b[k]*len>n){
					continue;
				}
				
				M = i;
				N = j;
				while(count<len){
					if(tolower(array[M][N]) != tolower(word[count])){
						break;
					}
					if(count == len-1){
						printf("%d %d\n", i+1, j+1);
						return;
					}
					count++;
					M += a[k];
					N += b[k];				
				}
			}
		}
	}
}

int main(){
	int num, t, m, n, i, line = 0;
	char a[50][51];
	char words[20][51];
	scanf("%d", &num);
	while(num > 0){
		if(line != 0){
			printf("\n");
		}
		line = 1;
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++){
			scanf("%s", a[i]);			
		}
		scanf("%d", &t);
		for(i=0; i<t; i++){
			scanf("%s", words[i]);
		}
		for(i=0; i<t; i++){
			findword(m, n, a, words[i]);
		}
		num--;
	}
	return 0;
}
