#include <stdio.h>
#include <string.h>

void solution1();
void decimalToBinary(int nDet, char * nBin, int point);

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

    char nBin[100];

    for (int i = 0; i< 100; i++) nBin[i]='_';

    decimalToBinary(nDec,nBin,0);

    for (int i = 0;i<100;i++) {
        if (nBin[i]!='_') {
            printf("%c", nBin[i]);
        } else {
            continue;
        }
    }
}

void decimalToBinary(int nDet, char * nBin,int point) {

    if (nDet > 0)
    {
        if (nDet % 2 == 0)
        {
            nDet = nDet / 2;
            decimalToBinary(nDet, nBin,point + 1);
            nBin[99 - point] = '0';
        }
        else {
            nDet = nDet / 2;
            decimalToBinary(nDet, nBin,point + 1);
            nBin[99 - point] = '1';
        }
    }

}