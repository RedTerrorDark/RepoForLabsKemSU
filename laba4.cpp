/*************************
* Автор: Некрасов А.С.   *
* Вариант 9              *
*************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int indexRow, indexCol;
  
  cout << "Введите количество строк таблицы: ";
  cin >> i;
  cout << endl << "Введите количество столбцов таблицы: ";
  cin >> j;
  
  int matrix[indexRow][indexCol];
  
  for (int indexRow1 = 0; i1 < indexRow; ++indexRow1){
    for (int indexCol1 = 0; j1 < indexCol; ++indexCol1){
        
      cout << endl << "Введите значение матрицы под номером (" << indexRow1 << indexCol11 << "): ";
      cin >> matrix[indexRow1][indexCol11];
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
  
  int matrixTrans[indexRow][indexCol];
  
  for (int MatrixTransposedRow = 0; MatrixTransposedRow < indexRow; ++MatrixTransposedRow){
    for (int MatrixTransposedCol = 0; MatrixTransposedCol < indexCol; ++MatrixTransposedCol ){
        
      matrixTransposed[MatrixTransposedRow][MatrixTransposedCol] = matrix[MatrixTransposedCol][MatrixTransposedRow];
        
      cout << matrixTransposed[MatrixTransposedRow][MatrixTransposedCol] << " ";
    }
    
    cout << endl;
  }
  
  cout << "Главня диагональ матрицы: ";
  for (int MatrixDioganal = 0; MatrixDioganal < i ; ++MatrixDioganal){
    
    cout << matrix[MatrixDioganal][MatrixDioganal] << ", ";
    
  }

  return 0;
}
