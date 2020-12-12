#include <iostream>
#include <math.h>
#include "main.h"

using std::cin;
using std::cout;


int main() {
  double a0, b0;
  
  cout << "Enter a0: ";
  cin >> a0;
  cout << "Enter b0: ";
  cin >> b0;
  falsi(a0, b0);

  return 0;
}


double equation(double x) {
  return x*sin(x) - 1;
}


void falsi(double a0, double b0) {
  int i = 1;
  double fa0, fb0, c0, fc0;

  fa0 = equation(a0);
  fb0 = equation(b0);
  if (fa0*fb0 > 0) { cout << "\n" << "Cant find any root in given range." << "\n"; return; }
  if (fb0 < 0) { c0 = a0; a0 = b0; b0 = c0; }
  cout << "Iteration #" << i << ": a0 = " << a0 << "\t, b0 = " << b0 << "\n";
  i++;
  do {
    fa0 = equation(a0);
    fb0 = equation(b0);
    c0 = (a0*fb0 - b0*fa0) / (fb0 - fa0);
    fc0 = equation(c0);
    if (modulus(fc0) < pow(10, -10)) break;
    if (fc0 < 0) a0 = c0;
    else b0 = c0;
    cout << "Iteration #" << i << ": a0 = " << a0 << "\t, b0 = " << b0 << "\n";
    i++;
  } while (modulus(a0-b0) > pow(10, -10));

  cout << "Final Result = " << c0 << "\n";
}


inline double modulus(double x) {
  if (x < 0) x = -x;
  return x;
}
