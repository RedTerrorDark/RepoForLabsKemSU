/*************************
* Автор: Некрасов А.С.   *
* Вариант а нету         *
*************************/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string arabicToRoman(int arabic) {

  vector<pair<int, string>> romanValues = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
    {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
    {1, "I"}
  };

  string resultRoman = "";
    
  for (const auto& yaNeZnauCheEto : romanValues) {
        
    while (arabic >= yaNeZnauCheEto.first) {
            
      resultRoman += yaNeZnauCheEto.second;
      arabic -= yaNeZnauCheEto.first;
            
    }
  }
    
  return resultRoman;
}

int romanToArabic(const string& roman) {
    
  unordered_map<char, int> arabicValues = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
  };

  for (char c : roman) {
    if (arabicValues.find(c) == arabicValues.end()) {
    return -1; 
    }
  }
    
  int resultArabic = 0;
    
  for (size_t index = 0; index < roman.length(); ++index) {
        
    int currentBukvaEpta = arabicValues[roman[index]];
        
    if (index + 1 < roman.length()) {
            
      int nextBukvaEpta = arabicValues[roman[index + 1]];
            
      if (currentBukvaEpta < nextBukvaEpta) {
                
        resultArabic += nextBukvaEpta - currentBukvaEpta;
        ++index;
                
        continue;
      }
    }  
        
    resultArabic += currentBukvaEpta;
  }
    
  return resultArabic;
}

int main() {
    
  int yaNeZnayKakNazvat, startArabic, endRoma;
  string startRoman;
  bool success = false;

  do {
      
    cout << "Введите 1 если вам надо арабское число в римское, введите 2 если вам надо римское число в арабское: ";
    cin >> yaNeZnayKakNazvat;
        
  if (cin.fail() || (yaNeZnayKakNazvat != 1 && yaNeZnayKakNazvat != 2)) {
      
    cout << "ты глупый или что-то, сказанно же 1 или 2, не тупи😭." << endl;
      
    cin.clear();
    cin.ignore(10000, '\n');
      
    cout << "Давай еще пробуй😡" << endl;

    } else {
      
      if (yaNeZnayKakNazvat == 1){
          
        cout << "Введите Арабское число: ";
        cin >> startArabic;
          
        if (cin.fail()) {
            
          cout << "Ты че ввел емае 😭 , давай сначало" << endl;
            
          cin.clear();
          cin.ignore(10000, '\n');
        } else if (startArabic <= 0 || startArabic > 3999) {
            
            cout << "😭" << endl << "Я знаю только от 0 до 3999, не судите строго" << endl << "давай заново короче 🤓" << endl;
                
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        } else {
            
          cout << "Римское число: " << arabicToRoman(startArabic) << endl;
            
          success = true;
        }
        
      } else {
          
        cout << "Введите Римское число: ";
        cin >> startRoman;
          
        if (cin.fail()) {
            
          cout << "Ты че ввел емае 😭 , давай сначало" << endl;

          cin.clear();
          cin.ignore(10000, '\n');
            
        } else {
            
          endRoma = romanToArabic(startRoman);
            
          if (endRoma > 0){
            cout << "Арабское число: " << endRoma << endl;
              
            success = true;
              
          } else {
              cout << "Ты че ввел 😭 , нет таких цифр в риме!!! Давай учи и заново!🙄🙄" << endl;

              cin.clear();
              cin.ignore(10000, '\n');
          }
        
        }
      }
    }
  } while (!success);

    return 0;
}
