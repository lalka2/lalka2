#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

struct bus_info {
	char number[10];		// номер автобуса
	char family[32]; 		// водитель
	int route;				// маршурут
	int status;				// 0 = в парке; 1 = на маршруте
};

void Menu(void){
    system("cls");
    cout << "1. Добавить маршрут."<<endl;
    cout << "2. Список."<<endl;
    cout << "3. Отправить в рейс."<<endl;
    cout << "4. Вернуть в парк."<<endl;
    cout << "5. Выход"<<endl;
}

#define SIZE 2

int main()
{
    setlocale(LC_ALL, "Russian");
    bus_info bus[SIZE];
    int key, marsh;
    int s = true;
    Menu();
    while(s) {
		cin >> key;
		switch(key) {
			case 1: {
				for(int i = 0; i < SIZE; i++) {
					cout << " - Введите номер автобуса: ";
					cin >> bus[i].number;
					cout << " - Введите фамилию водителя: ";
					cin >> bus[i].family;
					cout << " - Введите номер маршрута: ";
					cin >> bus[i].route;
					cout << endl;
					bus[i].status = 0;
				}
				Menu();
				break;
			}
            case 2: {
                for(int i = 0; i < SIZE; i++) {
                    cout<<bus[i].number<<endl;
                    cout<<bus[i].family<<endl;
                    cout<<bus[i].route<<endl;
                    if(bus[i].status==1) cout<<"На маршруте."<<endl;
                        else cout<<"В парке."<<endl;
                    cout<<endl;
                }
				break;
            }
            case 3:{
                cout<<"Введите номер маршрута, который хотите отправить в рейс: "<<endl;
                cin >> marsh;
                for (int i=0; i<SIZE; i++){
                    if (bus[i].route==marsh) bus[i].status=1;
                }
                Menu();
				break;
            }
            case 4:{
                cout<<"Введите номер маршрута, который хотите вернуть в парк: "<<endl;
                cin >> marsh;
                for (int i=0; i<SIZE; i++){
                    if (bus[i].route==marsh) bus[i].status=0;
                }
                Menu();
				break;
            }
            case 5:{
                s = false;
                break;
            }
            default:{
                cout<<"Неверное значение"<<endl;
                break;
            }
		}
    }
    cin.get();
return 0;
}

