// Shopping Management System Using Functions
#include <stdio.h>

#define MAX 50
#define DISCOUNT_LIMIT 5000

void Welcome(){
	printf("=== WELCOME TO FAST MART ===\n");
}

void ShowMenu(){
	printf("\n=== Product Menu ===\n");
	printf("1. Rice(1kg)\tRs.450\n");
	printf("2. Cooking Oil\tRs.600\n");
	printf("3. Sugar(1kg)\tRs.180\n");
	printf("4. Tea Pack\tRs.350\n");
	printf("5. Milk Carton\tRs.300\n");
}

int GetPrice(int Choice){
	switch(Choice){
		case 1: return 450;
		case 2: return 600;
		case 3: return 180;
		case 4: return 350;
		case 5: return 300;
		default: return 0;
	}
}

void PrintProductName(int Choice){
	switch(Choice){
		case 1: printf("Rice\t\t"); break;
		case 2: printf("Cooking Oil\t"); break;
		case 3: printf("Sugar\t\t"); break;
		case 4: printf("Tea Pack\t"); break;
		case 5: printf("Milk Carton\t"); break;
	}
}

int calculateItemPrice(int price, int qty){
	return price * qty;
}

int calculateSubtotal(int subtotal, int itemTotal){
	return subtotal + itemTotal;
}

float calculateDiscount(int subtotal){
	if (subtotal >= DISCOUNT_LIMIT)
		return subtotal * 0.10;
	else
		return 0;
}

float calculateFinalBill(int subtotal, float discount){
	return subtotal - discount;
}

char askContinue(){
	char choice;
	printf("\nDo you want to continue shopping? (y/n): ");
	scanf(" %c", &choice);
	return choice;
}

void displayReceipt(int items[], int qtys[], int count, int subtotal, float discount, float finalBill){
	int i;
	printf("\n==== RECEIPT ====\n");
	printf("Product\t\tQty\tPrice\tTotal\n");
	for (i = 0; i < count; i++){
		int price = GetPrice(items[i]);
		PrintProductName(items[i]);
		printf("%d\t%d\t%d\n", qtys[i], price, calculateItemPrice(price, qtys[i]));
	}

	printf("Subtotal:\t\t\tRs.%d\n", subtotal);
	printf("Discount:\t\t\tRs.%.2f\n", discount);
	printf("Final Payable:\t\t\tRs.%.2f\n", finalBill);

	printf("Thank you for shopping!\n");
}

int main(){
	int items[MAX], qtys[MAX];
	int count = 0, subtotal = 0;
	int choice, qty, price, itemTotal;
	float discount, finalBill;
	char again;

	Welcome();

	do{
		ShowMenu();
		printf("Enter product number: ");
		scanf("%d", &choice);

		price = GetPrice(choice);
		if (price == 0){
			printf("Invalid product number.\n");
		}
		else{
			printf("Enter quantity: ");
			scanf("%d", &qty);

			if (qty <= 0){
				printf("Invalid quantity.\n");
			}
			else{
				items[count] = choice;
				qtys[count] = qty;
				count++;

				itemTotal = calculateItemPrice(price, qty);
				subtotal = calculateSubtotal(subtotal, itemTotal);
				printf("Added. Item total: Rs.%d\n", itemTotal);
			}
		}

		again = askContinue();

	} while ((again == 'y' || again == 'Y') );

	discount = calculateDiscount(subtotal);
	finalBill = calculateFinalBill(subtotal, discount);

	displayReceipt(items, qtys, count, subtotal, discount, finalBill);

	return 0;
}
