# include <stdio.h>
int main(){
	int Uni[2][3][4];
	int i,j,k;
	int MaxSec1 = -999; int MaxSec2 = -999; int Total = 0; float Avg;
	int Count = 0; int FinalTotal = 0; float FinalAvg1, FinalAvg2; int Index1,Index2;
	printf("Enter Marks of Each Student: ");
	for( i=0; i<2; i++){
		FinalTotal = 0;
		for( j=0; j<3; j++){
			
			Total = 0; Avg = 0; 
			for( k=0; k<4; k++){
				printf("Uni[%d][%d][%d]: ",i,j,k);
				scanf("%d", &Uni[i][j][k]);
				Total = Total + Uni[i][j][k];
			}
			if(i == 0){
				if(Uni[i][j][k] > MaxSec1){
					
					MaxSec1 = Uni[i][j][k];
					Index1 = j+1;
					}
				else{
					if(Uni[i][j][k] > MaxSec2)
						MaxSec2 = Uni[i][j][k];
						Index2 = j+1;
					}
			}
			printf("Total Marks of Student %d = %d: \n", j+1,Total);
			Avg = Total/4.0;
			if(Avg >= 50)
				Count = Count + 1;
			printf("Average of Student %d = %.2f: \n", j+1,Avg);
			
			FinalTotal = FinalTotal + Total;
		
		}
		if(i==0)
			FinalAvg1 = FinalTotal/12.0;
		else
			FinalAvg2 = FinalTotal/12.0;
			
			
	}
	printf("Student whose Avg is atleast 50  are %d\n", Count);
	if(FinalAvg1 > FinalAvg2)
		printf("Section 1 Has Highest Average\n");
	else
		printf("Section 2 has Highest Average\n");
			
	
	printf("Highest Section 1 --> Student %d with Total %d\n", Index1,MaxSec1);
	printf("Hughest Section 2 --> Student %d with Total %d\n", Index2, MaxSec2);
			
}

