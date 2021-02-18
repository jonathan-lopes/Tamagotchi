#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Table ASCII*/
#define BORDER_COL 176 
#define LINE 205 

struct virtualPet
{
	char name[31];
	short int age, hunger, health, humor;
};
struct virtualPet pet;

void menu();
short int changeHunger(short int hunger);
short int changeHealth(short int health);
short int changeAge();
short int changeHumor();
void buffer();

int main()
{
	setlocale(LC_ALL, "portuguese");

	pet.health = 80;
	pet.hunger = 20;
	pet.age = 0;

	short int answer;

	printf("Qual o nome que deseja colocar no seu bichinho? ");
	fgets(pet.name, 30, stdin);

	while (pet.health > 0 && pet.hunger < 100)
	{
		changeHunger(2);
		changeHealth(-2);
		changeHumor();
		changeAge();
		menu();
		scanf_s("%hd", &answer);
		printf("\n");

		switch (answer)
		{
		case 1:
			changeHunger(-10);
			printf("-10 de fome! Obrigado! \n");
			system("pause>nul");
			break;

		case 2:
			changeHealth(10);
			printf("+10 de saúde! Obrigado! \n");
			system("pause>nul");
			break;

		case 3:
			buffer();
			printf("Qual o nome que deseja colocar no seu bichinho? ");
			fgets(pet.name, 30, stdin);
			break;

		case 4:
			if (pet.humor > 69)
			{
				printf("Estou feliz! \nHumor: %d%%", pet.humor);
			}
			else
			{
				if (pet.humor <= 69 && pet.humor > 39)
				{
					printf("Estou bem! \nHumor: %d%%", pet.humor);
				}
				else
				{
					if (pet.humor <= 39)
					{
						printf("Estou triste! \nHumor: %d%%", pet.humor);
					}
				}
			}

			system("pause>nul");
			break;

		case 5:
			if (pet.age == 1)
			{
				printf("Tenho %d ano de idade!", pet.age);
			}
			else
			{
				printf("Tenho %d anos de Idade!", pet.age);
			}

			system("pause>nul");
			break;

		case 6:
			if (pet.hunger > 69)
			{
				printf("Estou morrendo de Fome! \nFome: %d%%", pet.hunger);
			}
			else
			{
				if (pet.hunger <= 69 && pet.hunger > 39)
				{
					printf("Estou com Fome! \nFome: %d%%", pet.hunger);
				}
				else
				{
					if (pet.hunger <= 39)
					{
						printf("Não estou com fome! \nFome: %d%%", pet.hunger);
					}
				}
			}

			system("pause>nul");
			break;

		case 7:
			if (pet.health > 69)
			{
				printf("Minha saúde está boa! \nSaúde: %d%%", pet.health);
			}
			else
			{
				if (pet.hunger <= 69 && pet.hunger > 39)
				{
					printf("Acho que estou mal, atchim! \nSaúde: %d%%", pet.health);
				}
				else
				{
					if (pet.hunger <= 39)
					{
						printf("Estou doente! \nSaúde: %d%%", pet.health);
					}
				}
			}

			system("pause>nul");
			break;

		default:
			printf("Escolha um número válido! \n\n");
			system("pause>nul");
			break;
		}
	}

	system("cls");
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE,
		LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE);
	printf("\t%c  __      __    %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c /  \\.-" "-./   \\  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c \\   -   -   /  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c |   X   X   |  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c \\  .-'''-.  /  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c  '-\\__Y__/-'   %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c     `---`      %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE,
		LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE);

	printf("Você me deixou morre! \n\n");

	system("pause");
	return 0;
}

void menu() {
	system("cls");
	printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE,
		LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE);
	printf("\t%c  __      __    %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c /  \\.-" "-./   \\  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c \\   -   -   /  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c |   o   o   |  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c \\  .-'''-.  /  %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c  '-\\__Y__/-'   %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c     `---`      %c \n", BORDER_COL, BORDER_COL);
	printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE,
		LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE, LINE);
	pet.name[strcspn(pet.name, "\n")] = 0; // Remove \n 
	printf("\nOlá meu nome é %s, o que você deseja fazer comigo agora? \n", pet.name);
	printf("1- Alimentar (-10 de fome) \n");
	printf("2- Dormir (+10 de saúde) \n");
	printf("3- Alterar nome \n");
	printf("4- Visualizar humor \n");
	printf("5- visualizar idade \n");
	printf("6- Visualizar fome \n");
	printf("7- Visualizar saúde \n");
	printf("Resposta: ");
}

short int changeHunger(short int hunger) {
	pet.hunger += hunger;
	if (pet.hunger > 100)
	{
		pet.hunger = 100;
	}
	else
	{
		if (pet.health < 0)
		{
			pet.hunger = 0;
		}
	}

	return pet.hunger;
}


short int changeHealth(short int health) {
	pet.health += health;
	if (pet.health > 100)
	{
		pet.health = 100;
	}
	else
	{
		if (pet.health < 0)
		{
			pet.health = 0;
		}
	}

	return pet.health;
}

short int changeAge() {
	return pet.age += 1;
}

short int changeHumor() {
	pet.humor = pet.health + pet.hunger;
	return pet.humor;
}

void buffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}
