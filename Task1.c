// ATM Management System Using Functions
# include <stdio.h>

void welcome(){
	printf("Welcome\n");
}

void displayAmount(int Amount){

	printf("Amount is: Rs.%d\n", Amount);	
}

int getWithdrawalLimit(){
	return 50000;
}

int calculateBalance(int CBalance, int WAmount){
	int RBalance;
	RBalance = CBalance - WAmount;
	return RBalance;
}

int checkWithdrawal(int CBalance, int WAmount, int MaxLim){
	if (WAmount > 0 && WAmount <= CBalance && WAmount <= MaxLim)
		return 1;
	else
		return 0;
		
}

int main(){
	
	welcome();
	int Amount,Balance,RBalance;
	Balance = 50000;
	printf("Enter Amount: ");
	scanf("%d", &Amount);
	displayAmount(Amount);
	int MaxLimit = getWithdrawalLimit();
	if(checkWithdrawal(Balance,Amount,MaxLimit) == 1){
		RBalance = calculateBalance(Balance,Amount);
		printf("Valid Withdrawal\n");
		printf("Remaining Balance is = %d\n", RBalance);
	}
	else{
		printf("Invalid Withdrawal\n");
		printf("Remaining Balance is %d\n",Balance);
	}
}

