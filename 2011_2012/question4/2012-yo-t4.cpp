#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool check(int p2ago, int p1ago, int ptoday, int B2ago, int B1ago ,int Btoday){
	if (p2ago == ptoday && p1ago == ptoday && p2ago == p1ago){
		return false;
	}
	if ((p2ago+1 == B2ago || B2ago == 0) && (p1ago+1 == B1ago || B1ago == 0) && (ptoday+1 == Btoday || Btoday == 0)){
		return true;
	}
	return false;
}

int main(){
	int N,K;//服の数
	int A[100], B[100];
	int pasta2ago[3][3] = {0};
	int pasta1ago[3][3] = {0};
	int Bpasta[120] = {0};
	int total=0;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++){
		scanf("%d %d", &A[i], &B[i]);
		Bpasta[A[i]-1] = B[i];
	}
//初日と二日目の処理
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if ((i+1 == Bpasta[0] || Bpasta[0] == 0) && (j+1 == Bpasta[1] || Bpasta[1] == 0)){
				pasta2ago[i][j]=1;
			}
		}
	}
//それ以降の処理
	for (int i = 2; i < N; i++){
		for (int j = 0; j < 3;j++){
			for (int k = 0; k < 3; k++){
				for (int l = 0; l < 3; l++){
					if (check(j, k, l, Bpasta[i-2], Bpasta[i-1], Bpasta[i])){
						pasta1ago[k][l] += pasta2ago[j][k];
						pasta1ago[k][l] %= 10000;
					}
				}
			}
		}
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				pasta2ago[j][k] = pasta1ago[j][k];
				pasta1ago[j][k] = 0;
			}
		}
	}
	for (int j = 0; j < 3; j++){
		for (int k = 0; k < 3; k++){
			total  += pasta2ago[j][k];
			total  %=10000;
		}
	}

	printf("\n%d\n",total);

	return 0;
}
