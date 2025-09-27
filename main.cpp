/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  double u = 0.00024,
         p = 7210,
         l = 15.4;
  
  double R0, R1, a, R2;
  double Q1, Q2, Q3;

  cout << "Введите R0 в см: "; 
  cin >> R0;
  cout  << endl << "Введите R1 в см: ";
  cin >> R1;
  cout << endl << "Введите R2 в см: ";
  cin >> R2;
  cout << endl << "Введите a в см: ";
  cin >> a;

  R0 = R0 / 100.0;
  R1 = R1 / 100.0;
  R2 = R2 / 100.0;
  a = a / 100.0;
    
  Q1 = ((M_PI * pow(R0, 4.0)) / 8.0) * (p / (u * l));
  Q2 = (M_PI / 8.0) * (p / (u * l)) * abs((pow(pow(R1, 2.0) - pow(R2, 2.0), 2.0) / (log(R2 / R1))) + pow(R1, 4.0) - pow(R2, 4.0));
  Q3 = ((pow(a, 4.0) * pow(3.0, 0.5)) / 320.0) * (p / (u * l));
  
  cout<<"Q1 = " << Q1 << ", Q2 = " << Q2 << ", Q3 = " << Q3;

  return 0;
}
