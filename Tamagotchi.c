#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
		changeAge();
		menu();
		scanf_s("%hd", &answer);
		printf("\n");

		switch (answer)
		{
		case 1:
			changeHunger(-10);
			printf("-10 de fome! Obrigado! \n");
			break;

		case 2:
			changeHealth(10);
			printf("+10 de saúde! Obrigado! \n");
			break;

		case 3:
			buffer();
			printf("Qual o nome que deseja colocar no seu bichinho? ");
			fgets(pet.name, 30, stdin);
			break;

		case 4:
			printf("Humor: %d \n", changeHumor());
			break;

		case 5:
			printf("Idade: %d \n", changeAge());
			break;

		case 6:
			printf("Fome: %d \n", pet.hunger);
			break;

		case 7:
			printf("Saúde: %d \n", pet.health);
			break;

		default:
			printf("Escolha um número válido! \n");
			break;
		}
	}

	printf("\n------------------------------------------\n");
	printf("Você me deixou morre! \n");
	
	system("pause");
	return 0;
}

void menu() {
	printf("\n------------------------------------------\n\n");
	printf("Olá meu nome é %s.", pet.name);
	puts("O que você deseja fazer comigo agora?");
	printf("1- Alimentar (-10 de fome) \n");
	printf("2- Dormir (+10 de saúde) \n");
	printf("3- Alterar nome \n");
	printf("4- Visualizar humor \n");
	printf("5- visualizar idade \n");
	printf("6- Visualizar fome \n");
	printf("7- Visualizar saúde \n");
	printf("Resposta: ");
}

short int changeHunger( short int hunger) {
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
