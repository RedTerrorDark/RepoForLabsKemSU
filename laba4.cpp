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
        
      cout << endl << "Введите значение матрицы под номером (" << indexRow1 << indexCol1 << "): ";
      cin >> matrix[indexRow1][indexCol1];
    }
  }
  
  cout << "Первоначально матрица выглядит так:" << endl;
  
  /* Вывод начальной таблички*/
  for (int matrixRow = 0; matrixRow < i; ++matrixRow){
    for (int matrixCol = 0; matrixCol < j; ++matrixCol ){
        
      cout << matrix[matrixRow][matrixCol] << " ";
    }
    
    cout << endl;
  }
  
  /* Вывод транспонированной матрицы*/
  cout << "Транспонированная матрица :" << endl;
  
  int matrixTrans[indexRow][indexCol];
  
  for (int matrixTransposedRow = 0; matrixTransposedRow < indexRow; ++matrixTransposedRow){
    for (int matrixTransposedCol = 0; matrixTransposedCol < indexCol; ++matrixTransposedCol ){
        
      matrixTransposed[matrixTransposedRow][matrixTransposedCol] = matrix[MatrixTransposedCol][matrixTransposedRow];
        
      cout << matrixTransposed[matrixTransposedRow][matrixTransposedCol] << " ";
    }
    
    cout << endl;
  }
  
  cout << "Главня диагональ матрицы: ";
  for (int matrixDioganal = 0; matrixDioganal < i ; ++matrixDioganal){
    
    cout << matrix[matrixDioganal][matrixDioganal] << ", ";
    
  }

  return 0;
}
