#include <iostream>
#include <math.h>
#include <iso646.h>
float get_diskrim(float a, float b, float c){
  return b*b - 4 * a*c;
}
bool comparison(float f1, float f2){
  return abs(f1 - f2) < 0.000001;
}
float roots(float a, float b, float c, float koeff){
  if (abs(a) < 0.000001){
    if (abs(b) < 0.000001){
      if (abs(c) < 0.000001){
        return INFINITY;
      }
      else{
        return NAN;
      }
    }
    else{
      return -c / b;
    }    
  }
  else{
    return (-b + sqrt(get_diskrim(a,b,c))*koeff) / (2 * a);
  }
}
float solution(float a, float b, float c, float* x1, float* x2){
  float d = get_diskrim(a, b, c);
  if (d < 0){
    return false;
  }
  else{
    *x1 = roots(a, b, c, 1);
    if (std::isnan(*x1)){
      return false;
    }
    *x2 = roots(a, b, c, -1);
    return true;
  }
}
float print_results(bool has_roots, float x1, float x2,float a,float b, float c){
  if (!has_roots){
    std::cout << "NO ROOTS";
  }
  else if (a == 0 and b == 0 and c == 0){
    std::cout << "INFINITY";
  }
  else if (x1 == x2){
    std::cout << x1 << std::endl;
    std::cout << "1 ROOTS";
  }
  else{
    std::cout << x1 << "," << x2 <<std:: endl;
    std::cout << "2 ROOTS";
  }
}
int main(){
  float a=0, b=0, c=0, d = 0, x1=0,x2=0;
  std::cin >> a >> b >> c;
  bool has_roots = false;
  has_roots = solution(a, b, c, &x1, &x2);
  print_results(has_roots, x1, x2, a, b, c);
  system("pause");
  return 0;
}
