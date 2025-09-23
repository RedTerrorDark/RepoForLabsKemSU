/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

  const double u = 0.00024,
               p = 7210,
               l = 15.4;
  
  double R0 = 0.0816,
         R1 = R0,
         a = R0,
         R2 = 0.0264;
  
 double Q1 = ((M_PI * pow(R0, 4)) / 8) * (p / (u * l));
 double Q2 = (M_PI / 8) * (p / (u * l)) * abs((pow(pow(R1, 2) - pow(R2, 2), 2) / (log(R2 / R1))) + pow(R1, 4) - pow(R2, 4));
 double Q3 = ((pow(a, 4) * pow(3, 0.5)) / 320) * (p / (u * l));
  
  cout<<"Q1 = " << Q1 << ", Q2 = " << Q2 << ", Q3 = " << Q3;

  return 0;
}
