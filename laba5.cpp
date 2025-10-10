/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <vector>

using namespace std;


int mass( int numberOfArrayElements ){
    
  int *baseArray = new int [numberOfArrayElements];
  int minIndex = 9999*9999;
  
  for( int elementIndex = 0; elementIndex < numberOfArrayElements; ++elementIndex) {
      
      cout << endl << "Введите элемент массива под номером (" << elementIndex << ")";
      cin >> baseArray[elementIndex];
      
      if (baseArray[elementIndex] < minIndex){
          
        minIndex = baseArray[elementIndex];
        
      }
  }
  
  return minIndex ;

}




int main() {
  
  int X, Y, Z;
  int k, n, m;
  
  cout << "Введите размер массива X: ";
  cin >> k;
  
  X = mass(k);

  cout << "Введите размер массива Y: ";
  cin >> n;
  
  Y = mass(n);

  cout << "Введите размер массива Z: ";
  cin >> m;
  
  Z = mass(m);
  
  
  cout << "Минимальный элемент массива X: " << X << "Минимальный элемент массива Y: " << Y << "Минимальный элемент массива Z: " << Z;

  return(0);
}
