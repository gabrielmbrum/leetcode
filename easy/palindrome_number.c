#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int find (int x, int idx) {
	return (x / (int) pow(10, idx)) % 10;
}

bool isPalindrome (int x) {
	
	if (x < 0) return false; // considerando que um número negativo tenha o identificador '-' na frente, logo nunca é palindromo

	if (x < 10) return true; // é um número de digito único, logo é palindromo
	
	// vale a pena descobrir qts digitos o n° tem no inicio?
	// para descobrir precisaria fazer n operacoes, sendo n o n° de digitos
	
	int y = 10;
	int digit_count = 0;
	while (x / pow(y, digit_count) >= 1)
		digit_count += 1;
	
	printf("\ndc: %d | y: %d\n", digit_count, y);

	// e para descobrir o 1° digito? por mod
	// faz a operação com base na qtd de digitos, por exemplo, 901, sabendo que tem 3 digitos, pode-se fazer 901 % 100 
	int first_digit = find (x, 0);
	int comp1 = 0, comp2 = 0;

      	for (int i = 0; i <= digit_count / 2; i++) {
      		if (i == 0) {
			comp2 = find(x, digit_count - 1);
			if (first_digit != comp2) return false;
		} else if (i != digit_count / 2) { // evita de comparar o mesmo número
			comp1 = find (x, i);
			comp2 = find (x, digit_count - i - 1);
			if (comp1 != comp2) return false;
		}

		printf("\nround %d -> comp1: %d & comp2: %d\n", i, i == 0 ? first_digit : comp1, comp2); 
	}
	
	return true;
}
	
int main () {
	int x;

	printf("digite um num: ");
	scanf("%d", &x);

	printf("\nresult: %s\n", isPalindrome(x) == true ? "true" : "false");

	return 0;
}
