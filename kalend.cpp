/*************************
* Автор: Некрасов А.С.   *
* Вариант а нету         *
*************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int veryCoolMonthPrintFunctionEshkere(int yearForFunction, int monthForFunction) { 
  int rowMonth = 6, colMonth = 7;
  string matrixCalend[rowMonth][colMonth] = {{"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"},
                                {"--","--","--","--","--","--","--"}};
    
  int day = 1;
  int KStol, JStol;
  // Формула Зеллера, крутая штука, 2 часа себе мозги насиловал
  if (monthForFunction < 3) {
     monthForFunction += 12;
     yearForFunction -= 1;
  }
    
  KStol = yearForFunction % 100;
  JStol = yearForFunction / 100; 
  // Формула дня недели (0=Сб, 1=Вс, 2=Пн, ..., 6=Пт)
  int weakDay = (day + 13 * (monthForFunction + 1) / 5 + KStol + KStol / 4 + JStol / 4 + 5 * JStol) % 7;
  // Корректировка для российского формата (Пн=0, Вт=1, ..., Вс=6), а то не гоже... с суботы начинать.
  weakDay = (weakDay + 5) % 7;
  // Определяем количество дней в месяце. Да. Это долго и не удобно
  int monthDays;

  if (monthForFunction == 3 || monthForFunction == 5 || monthForFunction == 7 || monthForFunction == 8 || monthForFunction == 10 || monthForFunction == 12 || monthForFunction == 13) {
    monthDays = 31;
  } else if (monthForFunction == 4 || monthForFunction == 6 || monthForFunction == 9 || monthForFunction == 11) {
    monthDays = 30;
  } else { // тут ток февраль. а значит чекаем год на весокосный или как его там

    if ((yearForFunction % 400 == 0) || ((yearForFunction % 4 == 0) && (yearForFunction % 100 != 0))) {
      monthDays = 29;
    } else {
      monthDays = 28;
    }
  }
  // Ну. и тут начинаем заполнять
  int dayForIndex = 1;

  for (int forIndex = 0; forIndex < rowMonth && dayForIndex <= monthDays; ++forIndex) {
    for (int wrongForIndex = 0; wrongForIndex < colMonth && dayForIndex <= monthDays; ++wrongForIndex) {
      if (forIndex == 0 && wrongForIndex < weakDay) {
        continue; // Пропускаем пустые ячейки перед первым числом
      }
      if (dayForIndex <= monthDays) {
        if (dayForIndex <= 9) {
          matrixCalend[forIndex][wrongForIndex] = "0" + to_string(dayForIndex);
        } else {
          matrixCalend[forIndex][wrongForIndex] = to_string(dayForIndex);
        }
        ++dayForIndex;
      }
    }
  }
  // Выводим календарь
  for (int printForIndex = 0; printForIndex < rowMonth; ++printForIndex) {
    for (int wrongPrintForIndex = 0; wrongPrintForIndex < colMonth; ++wrongPrintForIndex) {
      cout << setw(2) << matrixCalend[printForIndex][wrongPrintForIndex] << " ";
    }
  cout << endl;
  }
    
  return 0;
}

int main() {
  int Year, numberOfMonth = 12;
  string monthName[numberOfMonth] = {"ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ"};

  cout << "Введите год: ";
  cin >> Year;

  for (int indexMonth = 0; indexMonth < numberOfMonth; ++indexMonth) {
    cout << "=======" << monthName[indexMonth] << "=======" << endl << "Пн Вт Ср Чт Пт Сб Вс" << endl;
    veryCoolMonthPrintFunctionEshkere(Year, indexMonth + 1);
  }

 
  return 0;
}
