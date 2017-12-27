#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>

using namespace std;

#define Width 7
#define hight 5

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int a[Width][hight], sum=0;
    for (int i=0; i<hight; i++){
        for (int j=0; j<Width; j++){
            a[i][j]= -10 + rand() % 30;
            cout << a[i][j] << "    ";
        }
    cout << endl;
    }
    for (int i=0; i<hight; i++){
        int preSum=0, prov=0;
        for (int j=0; j<Width; j++){
            preSum+=a[i][j];
            if (a[i][j]!=abs(a[i][j])) prov+=1;
        }
        if (prov!=0) cout <<"сумма элементов строки: "<<preSum <<endl;
    }
    int minimum[hight], maximum[hight];
    for (int i=0; i<hight; i++){
        for (int j=1; j<Width-1; j++){
            if (a[i][j]<a[i-1][j]) minimum[i]=a[i-1][j];
                else minimum[i]=a[i][j];
        }
    }
    for (int i=0; i<Width; i++){
        int prov=0, J=1;
        for (int j=1; j<hight; j++){
            if (a[j][i]>a[j-1][i]) maximum[i]=a[j-1][i];
                else maximum[i]=a[j][i];
        }
    }
    for (int i=0; i<hight; i++){
        for (int j=0; i<Width; i++){
            if (minimum[i]==maximum[j])
                cout<<minimum[i]<<" - Седловая точка A"<< endl;
        }
    }
    cin.get();
return 0;
}

