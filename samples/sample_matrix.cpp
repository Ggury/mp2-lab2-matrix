// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TDynamicMatrix<int> a(5), b(5), c(5), g(5), h(5);
  TDynamicVector<int> d(5), e(5);
  int i, j;
  int f = 4;


  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }

  for (i = 0; i < 5; i++)
  {
      d[i] = i * 3 + 2;
  }
  
  c = a * b;
  e = a * d;
  g = a * f;
  h = a + b;
  cout << "матрица a = " << endl << a << endl;
  cout << "Матрица b = " << endl << b << endl;
  cout << "Вектор d = " << endl << d << endl;
  cout << "Число f = " << endl << f << endl;
  cout << "Произведение матрицы а на число f " << endl << g << endl;
  cout << "Произведение матрицы а на вектор d " << endl << e << endl;
  cout << "Произведение матриц а и б " << endl << c << endl;
  cout << "Сумма матриц а и б " << endl << h << endl;
}
//---------------------------------------------------------------------------
