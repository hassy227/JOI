#include<stdio.h>
#include<stdlib.h>
#include<math.h>

class CLOTH{
public:
	int A;//最高気温
	int B;//最低気温
	int C;//派手さ
	bool Select[200];
	int yesterday;
	int today;

};

int main(){
	
	
	int temperature[200];//その日の気温
	int D;//日数
	int N;//服の数
	int point;
	int max=0;
	CLOTH cloth[200];
	
	scanf("%d %d",&D,&N);
	for(int i=0;i<D;i++){
		scanf("%d",&temperature[i]);
	}
	for(int i=0;i<N;i++){
		for (int j = 0; j < 200; j++)cloth[i].Select[j] = false;
		scanf("%d %d %d",&cloth[i].A,&cloth[i].B,&cloth[i].C);
	}

	for (int i = 0; i < N; i++){
		cloth[i].yesterday = 0;
		cloth[i].today = 0;
		if (cloth[i].A <= temperature[0] && temperature[0] <= cloth[i].B){
			cloth[i].Select[0] = true;
		}
	}
	printf("%d %d\n", D,N);

	for(int i=1;i<D;i++){//今日の日数
		for(int j=0;j<N;j++){//昨日着た服を探す
			if (cloth[j].Select[i-1]){//昨日着た場合
				for (int k = 0; k < N; k++){ //今日着る服を探す
					point = abs(cloth[k].C - cloth[j].C) + cloth[j].yesterday;
					//printf("%d.%d ", point, cloth[k].today);
					if (cloth[k].A <= temperature[i] && temperature[i] <= cloth[k].B&&cloth[k].today<point){
						
						cloth[k].today = point;
						cloth[k].Select[i] = true;
					}
				}
			}
			cloth[j].Select[i-1] = false;
			//printf(":\n", point);
		}

		for (int j = 0; j < N; j++){//今日来た服を探す
			if (cloth[j].Select[i]){
				cloth[j].yesterday = cloth[j].today;
			}
		}
		printf("i\n", point);
	}
	for (int i = 0; i < N; i++){
		if (max < cloth[i].yesterday){
			max = cloth[i].yesterday;
		}
	}
	printf("\nA:%d\n", max);
	return 0;
}