/*
 ============================================================================
 Name        : P1ej06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define ASCII_A_MAY 65
#define ASCII_Z_MAY 90
#define ASCII_A_MIN 97
#define ASCII_Z_MIN 122

#define DIF_TO_MAY (ASCII_A_MAY - ASCII_A_MIN)
#define DIF_TO_MIN (ASCII_A_MIN - ASCII_A_MAY)

#define ES_MAYUSCULA(a) (((a)>=(ASCII_A_MAY)) & ((a)<=(ASCII_Z_MAY)))?1:0
#define ES_MINUSCULA(a) (((a)>=(ASCII_A_MIN)) & ((a)<=(ASCII_Z_MIN)))?1:0
typedef enum { MAYUSCULAS, MINUSCULAS } may_min;
int strLargo(const char *origen){ //Cantidad de caracteres
//	int l=0;
//	while (origen[l] != '\0'){
//		l++;
//	}
//	return l;
	int i = 0;
	while(*(origen+i)!='\0'){
		i++;
	}
	return i;
}
int strVacio(const char *origen){ //retorna 1 si tiene al menos un caracter, 0 en otro caso
	int i = 0;
	while(*(origen+i)!='\0'){
		i++;
	}
	return i;
}
void strCopia(char *destino, const char *origen){ // Copiador
	for(int i = 0; i <= strLargo(origen)+1; i++){
		destino[i] = origen[i];
	}
}
/*prototipo modificado para permitir argumentos de tipo string literales, en casi todos los
compiladores un literal string es considerado una constante, o sea la función no podría
modificarlos pero, en algunos compiladores tales como GCC es posible modificarlos (según
K&R el comportamiento es indefinido)*/

char* reverse(char *string){//retorna una cadena que es string invertida
	char *inversa = (char*)malloc(strLargo(string)+1);
	if (inversa == NULL){
		return -1;
	}
	for (int i = 0; i <= strLargo(string); i++){
		*(inversa+i) = *(string+strLargo(string)-i-1);
	}
	*(inversa+strLargo(string))='\0';
	return inversa;
}
void strIzq(char *destino, const char *origen){ // Saca blancos Izq.
	int i = 0;
	while( *(origen +i) == ' '){
		i++;
	}
	strCopia(destino, (origen+i));
}

void strDer(char *destino, const char *origen){ // Saca blancos Der.
	char *aux = reverse(origen);
	if (aux == NULL){
		return -1;
	}
	strIzq(destino, aux);
	aux = reverse(destino);
	strCopia(destino, aux);
	free(aux);
}

void strAmbos(char *destino, const char *origen){ // Saca blancos Izqr(. y Der.
	strDer(destino, origen);
	strIzq(destino, destino);
}
void strMayMin(char *destino, const char *origen, may_min m){ // Convierte May. Min.
	strCopia(destino, origen);
	switch(m){
		case MAYUSCULAS:{
			for(int i = 0; i < strLargo(origen); i++){
				if (ES_MINUSCULA(*(origen + i)) == 1){
					*(destino + i) += DIF_TO_MAY;
				}
			}
			break;
		}
		case MINUSCULAS:{
			for(int i=0; i < strLargo(origen); i++){
				if(ES_MAYUSCULA(*(origen + i)) == 1){
					*(destino+i) += DIF_TO_MIN;
				}
			}
			break;
		}
	}

}
int main(){
	char *text1 =" Sera Cierto ?? ";
	int largo=strLargo(text1)+1;
	char *result = (char *)malloc (largo);
	char* reves;
	if(result == NULL)
		return -1;//sino pudo reservar memoria para result
	printf("La cadena: ");
	puts(text1);
	printf("Se encuentra: %s\n",(strVacio(text1) ? "No vacia" : "Vacia"));
	printf("Largo : %d\n", strLargo(text1));
	strCopia(result,text1);
	printf("Copia : [%s]\n", result);
	strIzq(result,text1);
	printf("Sin blancos a la Izq:[%s]\n", result);
	strDer(result,text1);
	printf("Der : [%s]\n", result);
	strAmbos(result,text1);
	printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);
	strMayMin(result,text1, MAYUSCULAS);
	printf("Mayusculas : [%s]\n", result);
	strMayMin(result,text1, MINUSCULAS);
	printf("Minusculas : [%s]\n", result);
	reves=reverse(text1);
	printf("La cadena: %s invertida queda: %s\n",text1, reves);
	free(result);
	result = NULL;
	free(reves);
	reves = NULL;
	return 0;
}
