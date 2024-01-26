#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int money = 0;
void pay()
{
	int n;
	printf("Nhap so tien can nap: ");
	scanf("%d", &n);
	money += n;
	menu();
}
void menu()
{
	int choose;

	printf("=======Tai xiu==========\n");
	printf("So tien hien tai: %d\n", money);
	printf("1. Nap them tien\n");
	printf("2. Dat cuoc\n");
	printf("Nhap lua chon: ");
	scanf("%d", &choose);
	if(choose == 1)
	{
		pay();
	}
	else if(choose == 2)
	{
		cuoc();
	}
}
void cuoc()
{
	int choose, tien_cuoc;
	printf("\nChon tai hoac xiu\n1.Tai\n2.Xiu\n");
	printf("Nhap lua chon: ");
	scanf("%d", &choose);
	printf("So tien hien tai la %d\nVui long nhap so tien can cuoc: ", money);
	scanf("%d", &tien_cuoc);
	if(money >= tien_cuoc)
	{
		if(gacha() == choose)
		{

			money += tien_cuoc;
			printf(" Ban thang! So tien hien tai la: %d\n", money);
		}
		else
		{

			money -= tien_cuoc;
			printf(" Ban thua! So tien hien tai la: %d\n", money);
		}
	}
	else
	{
		printf("Khong du tien !\n");
		menu();
	}
	menu();
}
int gacha()
{
	int result = 0;
	int xx = 0;
	srand((int)time(0));
	printf("\nKet qua la: ");
	for(int i = 1; i <= 3; i++)
	{
		xx = 1 + rand() % (6+1-1);
		printf("%d ", xx);
		result += xx;
	}
	printf("=%d", result);
	if(result >= 4 && result <= 10)
	{
		printf("\nKet qua la xiu!");
		return 2; 
	}
	else if(result >= 11 && result <= 17)
	{
		printf("\nKet qua la tai!");
		return 1; 
	}
	else
	{
		printf("Ket qua khong xac dinh, roll again!\n");
		gacha();
	}

	
}
int main()
{

	menu();
	
}

