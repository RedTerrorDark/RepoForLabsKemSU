/*************************
* Автор: Некрасов А.С.   *
* Вариант а нету         *
*************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RabotaiUmolyau(int yearF, int monthF) { 
    // АХАХАХ.... это типо календарь до изобретения цифр
    string matrixCalend[6][7] = {{"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"}};
    
    int day = 1;
    int KStol, JStol;
    
    // Формула Зеллера, крутая штука, 2 часа себе мозги насиловал
    if (monthF < 3) {

        monthF += 12;
        yearF -= 1;
    }
    
    KStol = yearF % 100;
    JStol = yearF / 100;
    
    // Формула дня недели (0=Сб, 1=Вс, 2=Пн, ..., 6=Пт)
    int weakDay = (day + 13*(monthF+1)/5 + KStol + KStol/4 + JStol/4 + 5*JStol) % 7;
    
    // Корректировка для российского формата (Пн=0, Вт=1, ..., Вс=6), а то не гоже... с суботы начинать.
    weakDay = (weakDay + 5) % 7;
    
    // Определяем количество дней в месяце. Да. Это долго и не удобно
    int SkolkoEpt; // Ну ### сколько? - Не мало. - ### ты мне мозги не ###, я спрашиваю сколько! - ээээээээ 65 + еще 20 изззз... - Ладно, заткнись...

    if (monthF == 3 || monthF == 5 || monthF == 7 || monthF == 8 || monthF == 10 || monthF == 12 || monthF == 13) {

        SkolkoEpt = 31;

    } else if (monthF == 4 || monthF == 6 || monthF == 9 || monthF == 11) {

        SkolkoEpt = 30;

    } else { // тут ток февраль. а значит чекаем год на весокосный или как его там

        if ((yearF % 400 == 0) || ((yearF % 4 == 0) && (yearF % 100 != 0))) {

            SkolkoEpt = 29;

        } else {

            SkolkoEpt = 28;
        }
    }

    // Ну. и тут начинаем заполнять
    int Schet = 1;

    for (int uh = 0; uh < 6 && Schet <= SkolkoEpt; ++uh) {

        for (int huh = 0; huh < 7 && Schet <= SkolkoEpt; ++huh) {

            if (uh == 0 && huh < weakDay) {

                continue; // Пропускаем пустые ячейки перед первым числом
            }
            
            if (Schet <= SkolkoEpt) {

                if (Schet <= 9) {

                    matrixCalend[uh][huh] = "0" + to_string(Schet);

                } else {

                    matrixCalend[uh][huh] = to_string(Schet);

                }
                Schet++;
            }
        }
    }
    
    // Выводим календарь
    for (int i = 0; i < 6; ++i) {

        for (int i2 = 0; i2 < 7; ++i2) {

            cout << setw(2) << matrixCalend[i][i2] << " ";
        }

        cout << endl;
    }
    
    return 0;
}

int main() {

    int Year;

    cout << "Введите год: ";
    cin >> Year;

    cout << "=======ЯНВАРЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 1);

    cout << "=======ФЕВРАЛЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 2);

    cout << "=========МАРТ========" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 3);

    cout << "========АПРЕЛЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 4);

    cout << "=========МАЙ=========" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 5);

    cout << "========ИЮНЬ=========" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 6);

    cout << "========ИЮЛЬ=========" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 7);

    cout << "========АВГУСТ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 8);

    cout << "======СЕНТЯБРЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 9);

    cout << "=======ОКТЯБРЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 10);

    cout << "========НОЯБРЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 11);

    cout << "========ДЕКАБРЬ=======" << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    RabotaiUmolyau(Year, 12);
 
    return 0;
}