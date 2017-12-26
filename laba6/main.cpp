#include <iostream>
#include <cstdlib>

using namespace std;

#define elements 6

struct scan_info {
	char model[32];		// наименование модели
	int price;			// цена
	double x_size;		// горизонтальный размер области сканировани¤
	double y_size;		// вертикальный размер области сканировани¤
	int optr;			// оптическое разрешение
	int grey;			// число градаций серого
};

void Menu(void){
    system("cls");
    cout << "1. Создание каталога."<<endl;
    cout << "2. Вывод каталога на экран."<<endl;
}

void show (scan_info *m, int N){
    for (int i=0; i<N; i++){
        cout<<m[i].model<<endl;
        cout<<m[i].price<<endl;
        cout<<m[i].x_size<<endl;
        cout<<m[i].y_size<<endl;
        cout<<m[i].optr<<endl;
        cout<<m[i].grey<<endl;
    }
}

void get (scan_info *m, int N){
    cin.ignore();
    for (int i=0; i<N; i++){
        cout<<"\nНаименование модели: ";
        cin.getline(m[i].model,32);

        cout<<"Цена: ";
        cin>>m[i].price;
        cin.ignore();

        cout<<"Горизонтальный размер области сканирования: ";
        cin>>m[i].x_size;
        cin.ignore();

        cout<<"Вертикальный размер области сканировани¤: ";
        cin>>m[i].y_size;
        cin.ignore();

        cout<<"Оптическое разрешение: ";
        cin>>m[i].optr;
        cin.ignore();

        cout<<"Число градаций серого: ";
        cin>>m[i].grey;
        cin.ignore();
    }
}

int main(){
    setlocale(LC_ALL,"rus");
    int N, key;
    Menu();
    cin>>key;
    scan_info *m = new scan_info[N];

    bool A=true;
    while (A==true){
        if (key<4 && key>0) {
            switch (key){
                case 1: {
                    cout<<"Введите N: ";
                    cin>>N;
                    get(m,N);
                    Menu();
                    cin>>key;
                    break;
                }
                case 2:{
                    show(m,N);
                    cin>>key;
                    break;
                }
            }
        }

        else {cout<<"Неверное значение"<<endl;
            A=false;}
        }
    delete[]m;
    cin.get();
    return 0;
}
