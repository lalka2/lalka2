#include <iostream>
#include <stdlib.h>
#include <locale>
#include <ctime>
#include <cmath>

using namespace std;

#define SIZE 6

int main(){
    setlocale(LC_ALL,"rus");
    srand(time(NULL));

    int num[SIZE];
    for(int i=0; i<SIZE; i++){
        num[i] = -10 + rand() % 20;
        cout << num[i] << "     ";
    }
    cout << endl;
    int numMin=num[0], sum=0, a=0;

    for (int i=0; i<SIZE; i++){
        if (num[i]<numMin) numMin=num[i];
        if (num[i]==abs(num[i])) sum+=num[i];
    }
    cout << "Минимальный элемент массива: " << numMin << endl;
    cout << "Сумма элементов по условию: " << sum << endl;
    for (int j=0; j<SIZE; j++){
        for (int i=1; i<SIZE-1; i++){
            if (num[i]==0) {
                a=num[i-1];
                num[i-1]=num[i];
                num[i]=a;
        }}
    cout << num[j] << "     ";
    }
    return 0;
}
