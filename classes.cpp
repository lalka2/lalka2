#include <iostream>
#include <string>

using namespace std;

static string Europe="Europe"; //объявляем глобальные статические данные
static string America="America";

class Animal //класс животные
{
public:
    bool gender; //пол
    int population; //популяция
    Animal(): population(10), gender(true){} // конструтор по умолчанию
    Animal(int a, bool b): population(a),gender(b){} // конструтор с двумя параметрами
    Animal(const Animal &other){this->population=other.population;} // конструтор копирования
    void showGender(){if(gender) cout<<"Gender: MALE"<<endl; else cout<<"Gender: FEMALE"<<endl;} //вызов функций пола и
    void showPop(){cout<<"Animal population: "<<population<<"000 individuals."<<endl;}; // популяции
    ~Animal(){} // деструтор
};

class carnivores : virtual public Animal // класс хищники, наследник от класса животные
{
protected:
    string food; // параметр пищи
public:
    carnivores():food("meat"){} // конструтор по умолчанию
    carnivores(string c):food(c) {} // конструтор с параметром
    void showFood(){cout<<"Animal food: "<<food<<endl;} //вызов функции питания
    ~carnivores(){} // деструтор
};

class carnivoresPet // класс домашних хищных животных
{
private:
    string bite; // животные которые могут укусить
public:
    carnivoresPet():bite("Bites!"){} // конструтор
    void showBite(){cout<<"The animal can: "<<bite<<endl;} //вызов функции
    friend carnivores; // делаем класс хищников дружественным для получения его функций
    ~carnivoresPet(){} // деструтор
};

class cats : public carnivores, public carnivoresPet // класс кошек
{
private:
    string voice; //голос
public:
    cats():voice("meow..."){} // коты говорят мяу
    friend void nation(string country=Europe); // дружественная функция показа родины кошки используя статичные данные
    void showVoice(){cout<<voice<<endl;} //вызов функции
    ~cats(){} // деструтор
};

class dogs : public carnivores, public carnivoresPet  // класс собак
{
private:
    string voice; //голос
public:
    dogs():Animal(14, false), voice("woof!woof!"){} //собаки говорят гав
    friend void nation(string America); // дружественная функция показа родины кошки используя статичные данные
    void showVoice(){cout<<voice<<endl;} //вызов функции
    ~dogs(){} // деструтор
};

void nation(string country) // функция определения родины животных
    {
        if(country==Europe)
        cout<<"country: "<<Europe<<endl;
        else cout<<"country: "<<America<<endl;
    }

int main()
{
    cats barsik; //создаем объект барсик
    nation();   // и вызываем все имеющиеся функции
    barsik.showGender();
    barsik.showPop();
    barsik.showFood();
    barsik.showVoice();
    barsik.showBite();
    cout<<endl;
    dogs reks; //создаем объект рекс
    nation(); // и вызываем все имеющиеся функции
    reks.showGender();
    reks.showPop();
    reks.showFood();
    reks.showVoice();
    reks.showBite();

    return 0;
}
