/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <cmath>

using namespace std;

const double a = 0.00000062,
             d = 0.0035;

double math(double x) {
  double Nu;
  
  if(x > 3000){
     Nu = 3.4 + 0.014 * pow(x, 0.8);
  } else {
     Nu = 5.0 + 0.021 * x;
  }
  
return (Nu);
}

int main() {
  double W2, Pe;
  
  cout << "| Nu | Pe |" << endl;
  
  for(double W = 0.1; W < 0.51; W += 0.1){
    if( W == 0.1 || W == 0.2 || W == 0.5){
      Pe = (W * d) / a;
      cout << "| " << math(Pe) << " | " << Pe << " |" << endl;
    }
  }
  
  for(int W = 1; W < 6; ++W){
    if( W == 1 || W == 2 || W == 5){
      Pe = (W * d) / a;
      cout << "| " << math(Pe) << " | " << Pe << " |" << endl;
    }
  }
  
  return 0;
}
