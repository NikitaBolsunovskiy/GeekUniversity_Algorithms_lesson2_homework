#include <stdio.h>
#include <string.h>

void solution1();
char* decimalToBinary(int nDet, char * nBin);

int main() {
    solution1();
    return 0;
}

void solution1(){

//    1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
//    рекурсию.

    int nDec = 0;

    printf("Введите число: \n");
    scanf("%d",&nDec);

    char nBin[100] = "";

    decimalToBinary(nDec, "");

    printf("%s\n",nBin);

    //printf("Двоичное представление числа: %d",nBin);
}

char* decimalToBinary(int nDet, char * nBin) {

    if (nDet == 0) {
        return "0";
    } else if (nDet == 1) {
        return "1";
    } else  {
        return strcat(decimalToBinary(nDet/2,nBin),nBin);
}
}