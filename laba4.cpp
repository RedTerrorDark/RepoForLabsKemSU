/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int i, j;
  
  cout << "Введите количество строк таблицы: ";
  cin >> i;
  cout << endl << "Введите количество столбцов таблицы: ";
  cin >> j;
  
  int matrix[i][j];
  
  for (int i1 = 0; i1 < i; ++i1){
    for (int j1 = 0; j1 < j; ++j1){
        
      cout << endl << "Введите значение матрицы под номером (" << i1 << j1 << "): ";
      cin >> matrix[i1][j1];
    }
  }
  
  cout << "Первоначально матрица выглядит так:" << endl;
  
  /* Вывод начальной таблички*/
  for (int MatrixRow = 0; MatrixRow < i; ++MatrixRow){
    for (int MatrixCol = 0; MatrixCol < j; ++MatrixCol ){
        
      cout << matrix[MatrixRow][MatrixCol] << " ";
    }
    
    cout << endl;
  }
  
  /* Вывод транспонированной матрицы*/
  cout << "Транспонированная матрица :" << endl;
  
  int matrixTrans[i][j];
  
  for (int MatrixTransRow = 0; MatrixTransRow < i; ++MatrixTransRow){
    for (int MatrixTransCol = 0; MatrixTransCol < j; ++MatrixTransCol ){
        
      matrixTrans[MatrixTransRow][MatrixTransCol] = matrix[MatrixTransCol][MatrixTransRow];
        
      cout << matrixTrans[MatrixTransRow][MatrixTransCol] << " ";
    }
    
    cout << endl;
  }
  
  cout << "Главня диагональ матрицы: ";
  for (int MatrixDioganal = 0; MatrixDioganal < i ; ++MatrixDioganal){
    
    cout << matrix[MatrixDioganal][MatrixDioganal] << ", ";
    
  }

  return 0;
}
