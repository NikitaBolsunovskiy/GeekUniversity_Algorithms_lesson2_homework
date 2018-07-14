#include <stdio.h>
#include <string.h>

void solution1();
void solution2a();
void solution2b();
int recursivePow(int x,int n);
void solution2c();
int recursivePowEven(int x,int n);
void decimalToBinary(int nDet, char * nBin, int point);
void solution3();
int ArrayCalculatePaths(int x, int n);
int RecursiveCalculatePaths(int x, int n);

int main() {
    //solution1();
    //solution2a();
    //solution2b();
    //solution2c();
    solution3();
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

void solution2a(){

//    2. Реализовать функцию возведения числа a в степень b:
//    a. Без рекурсии.

    int x = 0;
    int n = 0;

    printf("Введите число X: \n");
    scanf("%d",&x);
    printf("Введите число N: \n");
    scanf("%d",&n);

    int result = 1;
    if (n==0) {
        x=1;
    } else {
        for (int i = 0; i < n; i++) {
            result *= x;
        }
    }

    printf("X в степени N равно: %d",result);

}

void solution2b(){
//    2. Реализовать функцию возведения числа a в степень b:
//    b. Рекурсивно.
    int x = 0;
    int n = 0;

    printf("Введите число X: \n");
    scanf("%d",&x);
    printf("Введите число N: \n");
    scanf("%d",&n);

    x = recursivePow(x,n);

    printf("X в степени N равно: %d",x);
}

int recursivePow(int x,int n){

    return (n == 1) ? x : x * recursivePow(x,n-1);

}

void solution2c(){

//    2. Реализовать функцию возведения числа a в степень b:
//    c. *Рекурсивно, используя свойство чётности степени.
//    Суть такая: 5^7 = 5^6*5 = 5^3*5^3*5 и так далее.

    int x = 0;
    int n = 0;

    printf("Введите число X: \n");
    scanf("%d",&x);
    printf("Введите число N: \n");
    scanf("%d",&n);

    x = recursivePowEven(x,n);

    printf("X в степени N равно: %d",x);

}

int recursivePowEven(int x,int n) {

    if (n==0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else if (n%2 == 0) {
        return recursivePowEven(x,n/2)*recursivePowEven(x,n/2);
    } else {
        return recursivePowEven(x,n-1)*x;
    }
}

void solution3(){

//    **Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У
//    исполнителя две команды, каждой присвоен номер:
//    1. Прибавь 1.
//    2. Умножь на 2.
//    Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько
//    существует программ, которые число 3 преобразуют в число 20:
//    а. С использованием массива.
//    b. *С использованием рекурсии.

    int x = 0;
    int n = 0;

    printf("Введите число X: \n");
    scanf("%d",&x);
    printf("Введите число N: \n");
    scanf("%d",&n);

    int arrayCalc = ArrayCalculatePaths(x,n);
    int RecursivePath = RecursiveCalculatePaths(x,n);

    printf("количество программ при расчете через массив: %d\n",arrayCalc);
    printf("количество программ при расчете через рекурсию: %d\n",RecursivePath);
}

int ArrayCalculatePaths(int x, int n){

    int paths = 0;
    if (x>n) {
        return paths;
    }
    int buffer[1000];

    for (int i = 0; i < 1000;i++){
        buffer[i] = 0;
    }
    buffer[0] = x;

    int iteration = 0;

    while (1) {

        int buffer2[1000];
        for (int i = 0; i< 1000; i++){
            buffer2[i]=0;
        }

        int counterbuffer2 = 0;
        for(int i = 0; i < 1000; i++){

            if (buffer[i]==0){
                break;
            }

            int x1 = buffer[i] + 1;
            int x2 = buffer[i] * 2;

            if (x1 == n) {
                paths += 1;
            } else if (x1 < n){
                buffer2[counterbuffer2] = x1;
                counterbuffer2 += 1;
            }

            if (x2 == n) {
                paths += 1;
            } else if (x2 < n){
                buffer2[counterbuffer2] = x2;
                counterbuffer2 += 1;
            }
        }

        for(int i = 0; i < 1000;i++){
            if (i<counterbuffer2) {
                buffer[i] = buffer2[i];
            } else {
                buffer[i] = 0;
            }
        }

        if (counterbuffer2 == 0) {
            break;
        }
    }
    return paths;

}
int RecursiveCalculatePaths(int x, int n){

    if (n<x){
        return 0;
    } else if (n==x) {
        return 1 ;
    } else if(n%2 == 1) {
        return RecursiveCalculatePaths(x,n-1);
    } else {
        return RecursiveCalculatePaths(x,n-1) + RecursiveCalculatePaths(x,n/2);
    }

}