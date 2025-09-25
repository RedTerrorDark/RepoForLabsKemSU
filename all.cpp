#include <iostream>
#include <cmath>

using namespace std;

int main()
{

  const double c = 5.73;
  
  double D = 0.0006;
  int t = 3600;
  double e = 2.7185;
  
  cout << "| X | C |" << endl;
  for(int x = 1; x != 26; ++x) {
      if(x <= 5 || x % 5 == 0){
          double C = c * pow(e, -(pow(x, 2) / (4 * D * t)));
          cout << "| " << x << " | " << C << " |" << endl;
        }
      }

  return 0;
}
