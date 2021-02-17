#include <stdio.h>

#define TAB '\t' 	/* Valor numerico de la constante de caracter horizontal tab en ASCII */
#define SPACE ' '  	/* Valor numerico de la constante de caracter space en ASCII */
#define NL '\n' 	/* Valor numerico de la constante de caracter new line en ASCII */
int main(void)
{
	int c = NL, last_chr, flag = 0; 
	/*	c es la variable que almacena el valor numerico de un caracter leido por la funcion getchar.
		Se inicializa con el valor de NL para que el ciclo while comience su primera vuelta. 
		last_chr es una variable utilizada durante el programa para almacenar un caracter previamente leido 
		con la funcion getchar en el ciclo while anidado.
		flag se utiliza como un indicador al programa para que imprima una linea de texto en 
		condiciones especificas. Se inicializa en 0 para que el ciclo while comience su primera vuelta. 
	*/
	printf("El programa permite al usuario ingresar una o mas lineas de texto y despues las imprime\n");
	printf("en la ventana donde se ejecute el programa.\n\n");
	printf("Si alguna linea de texto tiene dos o mas espacios en blanco consecutivos, el programa\n");
	printf("se encarga de mostrar unicamente un espacio en blanco.\n");
	printf("El programa toma en cuenta la tabulacion como un conjunto de espacios en blanco.\n\n");
	printf("Para detener la captura de texto por el programa, ingresa un salto de linea despues\n");
	printf("de que se solicite el texto a ingresar.");
	while (c == NL && flag == 0) {
		printf("\n\nTexto a ingresar:");
		flag = 1; /* Vuelve a tomar el valor 1 para que imprima el texto deseado */
		last_chr = '\0'; 
		/* Se le asigna un valor distinto de SPACE para que borre todo valor almacenado 
		referente a una linea de texto que el programa obtuvo anteriomente. */
		while ((c = getchar()) != NL) {
			if (flag)
			{
				printf("\nSalida del texto:");
				flag = 0;
			}
			if (c == TAB)
				c = SPACE;
			if (last_chr != SPACE) 
				putchar(c);
			else if (c != SPACE) 
				putchar(c);
			last_chr = c;
		}
	}		
	return 0;
}