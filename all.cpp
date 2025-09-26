#include <iostream>
#include <cmath>

using namespace std;
/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

int main() {
  
  const double c = 5.73;

  double D = 0.0006;
  int t = 3600;
  double e = 2.7185;
  int step1End = 5,
      step2End = 26;

  double C;
  int step = 1;
  

  cout << "| X | C |" << endl;
  int x = 1;
  
  while (x < step1End) {
    C = c * pow(e, -(pow(x, 2.0) / (4.0 * D * t)));
    
    cout << "| " << x << " | " << C << " |" << endl;
    x += step;
  }
  
  step = 5;
  
  do {
    C = c * pow(e, -(pow(x, 2.0) / (4.0 * D * t)));
    
    cout << "| " << x << " | " << C << " |" << endl;
    x += step;
  } while (x < step2End);

  return 0;
}
