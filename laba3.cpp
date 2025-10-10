/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  
  double a, d,
         s1 = 3000.0;
  int WCount = 7;

  cout << "Введите a в см^2: ";
  cin >> a;
  
  a = a / 100000.0;
  
  cout << endl << "Введите d в мм: ";
  cin >> d;
  
  d = d / 10000.0;
    
  double W, Pe, Nu;
  
  for (int WIndex = 1; WIndex < WCount; ++WIndex){
    
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
