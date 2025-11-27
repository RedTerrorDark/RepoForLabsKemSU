/*************************
* Автор: Некрасов А.С.   *
* Вариант а нету         *
*************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string SumNumbers(string number1, string number2) {
  string result = "";
  int carry = 0;
  int diff, sum;
    
  if (number1.length() < number2.length()) swap(number1, number2);
  diff = number1.length() - number2.length();
  number2 = string(diff, '0') + number2;
    
  for (int move = number1.length() - 1; move >= 0; --move) {
    sum = (number1[move] - '0') + (number2[move] - '0') + carry;
    carry = sum / 10;
    result.push_back(sum % 10 + '0');
  }
    
  if (carry) result.push_back(carry + '0');
  reverse(result.begin(), result.end());
    
  return result;
}

string compareNumbers(string number1, string number2) {
  string result = "";
  int compare;
  compare = number1.compare(number2);
    
  if (compare == 0){
    result = "=";
  } else if (compare > 0){
    result = ">";
  } else if (compare < 0){
    result = "<";
  }
    
  return result;
}

string subtractNumbers(string number1, string number2) {
  bool isNegative = false;
    
  if (number1.length() < number2.length() || (number1.length() == number2.length() && number1 < number2)) {
    swap(number1, number2);
    isNegative = true;
    }
    
  string result = "";
  int borrow = 0;
  int diff, digit1, digit2;

  diff  = number1.length() - number2.length();
  number2 = string(diff, '0') + number2;
    
  for (int move = number1.length() - 1; move >= 0; --move) {
    digit1 = number1[move] - '0' - borrow;
    digit2 = number2[move] - '0';
    if (digit1 < digit2) {
      digit1 += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
      result.push_back((digit1 - digit2) + '0');
  }
    
  while (result.length() > 1 && result.back() == '0') {
    result.pop_back();
  }
    
  if (isNegative) result.push_back('-');
  reverse(result.begin(), result.end());
    
  return result;
}

string multiplyNumbers(string number1, string number2) {
  if (number1 == "0" || number2 == "0") return "0";
    
  int len1 = number1.length();
  int len2 = number2.length();
  vector<int> result(len1 + len2, 0);
  int product, sum;
    
    // Умножаем в столбик
  for (int move = len1 - 1; move >= 0; --move) {
    for (int move2 = len2 - 1; move2 >= 0; --move2) {
      product = (number1[move] - '0') * (number2[move2] - '0');
      sum = product + result[move + move2 + 1];
            
      result[move + move2 + 1] = sum % 10;
      result[move + move2] += sum / 10;
    }
  }
    
    // Преобразуем в строку
  string finalResult = "";
  for (int number : result) {
    if (!(finalResult.empty() && number == 0)) { // Пропускаем ведущие нули
      finalResult.push_back(number + '0');
    }
  }
    
  return finalResult.empty() ? "0" : finalResult;
}

string divideNumbers(string number1, string number2) {
    // Проверка деления на ноль
  if (number2 == "0") return "ERROR: НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!!!!!!";
    
    // Если делимое меньше делителя
  if (number1.length() < number2.length() || (number1.length() == number2.length() && number1 < number2)) {
    return "0";
  }

  string result = "";
  string current = "";
  int count;
  string temp;
    
  for (int move = 0; move < number1.length(); ++move) {
    current += number1[move];
        // Убираем ведущие нули
    while (current.length() > 1 && current[0] == '0') {
      current = current.substr(1);
    }
        // Пропускаем если current меньше num2
    if (current.length() < number2.length() || (current.length() == number2.length() && current < number2)) {
      if (!result.empty()) result += "0";
      continue;
    }
        // Находим сколько раз num2 помещается в current
    count = 0;
    temp = current;
        
    while (temp.length() > number2.length() || (temp.length() == number2.length() && temp >= number2)) {
      temp = subtractNumbers(temp, number2);
      ++count;
    }
        
    result += to_string(count);
    current = temp;
  }
    
  return result.empty() ? "0" : result;
}


int main() {
  string number1, number2;
  int choice;
    
  cout << "First Number: ";
  cin >> number1;
  cout << "Second Number: ";
  cin >> number2;
    
  cout << "\nAnd what are you going to do with this?:\n" << "1. sum up the numbers\n" << "2. subtract numbers\n" << "3. multiply numbers\n" << "4. divide numbers\n" << "5. compare numbers\n" << "What did you choose???: ";
  cin >> choice;
    
  string result;
  switch (choice) {
    case 1:
      result = SumNumbers(number1, number2);
      cout << "sum: " << result << endl;
      break;
    case 2:
      result = subtractNumbers(number1, number2);
      cout << "difference: " << result << endl;
      break;
    case 3:
      result = multiplyNumbers(number1, number2);
      cout << "product: " << result << endl;
      break;
    case 4:
      result = divideNumbers(number1, number2);
      cout << "result of division: " << result << endl;
      break;
    case 5:
      result = compareNumbers(number1, number2);
      cout << number1 << result << number2 << endl;
      break;
    default:
      cout << "uhhhhh...." << endl;
    }
    
  return 0;
}