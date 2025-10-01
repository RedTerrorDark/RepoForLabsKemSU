/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <cmath>

using namespace std;

  double a, d,
         ss = 7.0,
         s1 = 3000.0;

int main() {

  cout << "Введите a в см^2: ";
  cin >> a;
  a = a / 100000;
  cout << endl << "Введите d в мм: ";
  cin >> d;
  d = d / 10000;
    
  double W, Pe, Nu;
  
  for(int i = 1; i < ss; ++i){
    
    cout << "Введите W: ";
    cin >> W;
    Pe = (W * d) / a;
    if (Pe > s1){
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    } else {
      Nu = 5.0 + 0.021 * Pe;
    }
    cout << "Nu и Pe соответственно = "<< Nu << " и " << Pe << endl;
  }
  
  return 0;
}
