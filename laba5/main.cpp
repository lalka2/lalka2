#include <iostream>
#include <cstring>

using namespace std;

struct worker {
	char name[20];
	char position[20];
	int year;
};

int main(){
    const int SIZE = 2;
    worker ls[SIZE];
    setlocale(LC_ALL,"Russian");

    for (int i=0; i<SIZE; i++){
        cout << "Фамилия и инициалы: ";
        cin.getline(ls[i].name, 20);
        cout << "Должность: ";
        cin.getline(ls[i].position, 20);
        cout << "Год поступления: ";
        cin >> ls[i].year;
        cout << endl;
        cin.get();
    }

    for (int i=0; i<SIZE; i++){
        cout<<ls[i].name<<endl;
        cout<<ls[i].position<<endl;
        cout<<ls[i].year<<endl;
        cout<<endl;
    }


    int num;
    cout << "Введите стаж работы: ";
    cin >> num;
    for (int i=0; i<SIZE; i++){
        if (ls[i].year<=(2017 - num)){
            cout << ls[i].name <<ls[i].year << endl;
            cout<<endl;
            break;
    }
        else cout << "Таких работников не существует." << endl;
    }
	cin.get();
	return 0;
}
