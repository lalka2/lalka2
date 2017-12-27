#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
    setlocale(LC_ALL,"rus");

     ifstream fin("file.dat");
    char stroka[70];
    while (!fin.eof()){
        fin.getline(stroka, 70);
        cout << stroka <<endl;
    }
    fin.close();

    cin.get();
    int word=0,sum=0;

  ifstream finw("file.dat");
    while (!finw.eof()){
        int counter=0;
        finw.getline(stroka, 70);
        while (stroka[counter]!='\0'){
            if (stroka[counter]==' '){
                    if(stroka[counter+1]=='а'||'е'||'и'||'о'||'у'||'ы'||'э'||'ю'||'я'){
                        counter++;
                        sum++;
                    }
            }
            else if (stroka[counter]!=' '){

                counter++;
            }
        }
    }
    finw.close();
    cout << "Слов в тексте с гласной буквы: " << sum << endl;
    cin.get();
    return 0;
}
