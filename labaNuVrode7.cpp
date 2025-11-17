/*************************
* Автор: Некрасов А.С.   *
* Вариант а нету         *
*************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    
  ifstream file("C:\\NABORBUKW.txt"); 

  string line, fileContent, doubleLatter;
  int countLatter;

  while (getline(file, line)) { 
    fileContent += line + " ";
  }
    
  file.close();

  for (char latter = 'a'; latter <= 'z'; ++latter) {
    countLatter = count(fileContent.begin(), fileContent.end(), latter);
    if (countLatter > 0) {
      cout << "Символ '" << latter << "': " << countLatter << " раз" << endl;
    }
  }

  size_t pos;

  for (char latter1 = 'a'; latter1 <= 'z'; ++latter1) {
      
    for (char latter2 = 'a'; latter2 <= 'z'; ++latter2) {
        
      doubleLatter = string(1, latter1) + latter2;
        
      countLatter = 0;
      pos = 0;
        
      while ((pos = fileContent.find(doubleLatter, pos)) != string::npos) {
          
        ++countLatter;
          
        pos += doubleLatter.length();
          
      }
      if (countLatter > 0) {
          
        cout << "Двойной символ '" << doubleLatter << "': " << countLatter << " раз" << endl;
          
      }
    }
  }

    
  return 0;
}
