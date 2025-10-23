/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

/*Строки файла выглядят примерно так <номер шкилы> <год> <фамилия> <имя> <матеша> <физика> <русский>*/

/*Я это сделал и оно работает, и я ** не ** как это работает, но! работает, да, боже спагетти монстр храни мой код*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
  
  int index;
  string schollNumber;
  string line;
  
  int pointsSumm, SRLPoints;
  strint student[7];
  
  cout << "Введите номер школы: ";
  cin >> schollNumber;
  cout << "Вот список абитуриентов из выбраной школы: \n";
  
  ifstream file("C:\\SchollBoss.txt");
  
  while (getline(file, line)) { /*Чтение строк по порядку, наверное*/

    index = 0;
    
    if (line.find(schollNumber) == 0) { /* Проверка ПЕРВОГО слова в строке, то есть, номера школы*/
        
      stringstream chenSUKALine(line); /* если быть честным - я вообше не ** что это вообще, но работает*/
    
      while (chenSUKALine.good() && index < 7){ /* записание строки в массив*/
          
        chenSUKALine >> student[index]; 
        ++index;
        
      }
      
      pointsSumm = stoi(student[4]) + stoi(student[5]) + stoi(student[6]);
      SRLPoints = pointsSumm / 3;
      
      cout << "Год окончания школы: " << student[1] << " ФИО: " << student[2] << " " << student[3] << " Сумма баллов: " << pointsSumm << " Среднее значение Баллов: " << SRLPoints;
        
    
    }

  }

  file.close();
  
  return 0;
}
