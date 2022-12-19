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

  int type1;
  char type2;
  char type3;
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  cout << "Введите  размер матриц" << endl;
  cin >> type1;
  TDynamicMatrix<int> data_1(type1);
  TDynamicMatrix<int> data_2(type1);
  cout << "Задайте матрицу 1:" << endl;
  cin >> data_1;
  cout << "Matrix 1 =" << data_1 << endl;
  cout << "Задайте матрицу 2:" << endl;
  cin >> data_2;
  cout << "Введите тип опреации" << endl;
  cin >> type3;
  switch (type3)
  {
  case '+':
      cout << "Сумма:"<<endl<<data_1 + data_2 <<endl ;
      break;
  case '-':
      cout << "Разность:" << endl<< data_1 - data_2 << endl;
      break;
  case '*':
      cout << "Произведение:" << endl<< data_1 * data_2 << endl;
      break;
  }
}
//---------------------------------------------------------------------------
