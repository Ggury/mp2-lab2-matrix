// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz <= 0)
        throw out_of_range("Vector size should be greater than zero");
    if (sz >= MAX_VECTOR_SIZE)
        throw out_of_range("Vector size should be less then 100 000 000");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (*this == v)
          return *this;
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind<0 || ind>sz)
          throw out_of_range("Invalid index");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind<0 || ind>sz)
          throw out_of_range("Invalid index");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (*this == v)
          return false;
      return true;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector _temp(*this);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] += val;
      return _temp;
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector _temp(*this);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] -= val;
      return _temp;
  }
  TDynamicVector operator*(double val)
  {
      TDynamicVector _temp(*this);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] *= val;
      return _temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw invalid_argument("vector lengths are not equal");
      TDynamicVector _temp(*this);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] += v.pMem[i];
      return _temp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw invalid_argument("vector lengths are not equal");
      TDynamicVector _temp(*this);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] -= v.pMem[i];
      return _temp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw invalid_argument("vector lengths are not equal");
      T Res = NULL;
      for (int i = 0; i < sz; i++)
          Res += pMem[i]*v.pMem[i];
      return Res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz <= 0 || sz >= MAX_MATRIX_SIZE)
          throw out_of_range("size must be greater   than 0 and less than 10 000");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::operator[];


  T& at(size_t ind1,size_t ind2)
  {
      if (ind1<0 || ind1>sz || ind2<0 || ind2>sz)
          throw out_of_range("Invalid index");
      return pMem[ind1][ind2];
  }


  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz)
          return false;
      for (int i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return false;
      return true;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix _temp(sz);

      for (int i = 0; i < sz; i++)
          _temp[i] = pMem[i] * val;
      return _temp;

  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size())
          throw invalid_argument("sizes not equal");
      TDynamicVector<T> _temp(sz);
      for (int i = 0; i < sz; i++)
          _temp[i] = pMem[i] * v;
      return _temp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("sizes not equal");
      TDynamicMatrix _temp(sz);
      for (int i = 0; i < sz; i++)
          _temp.pMem[i] = pMem[i] + m.pMem[i];
      return _temp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("sizes not equal");
      TDynamicMatrix _temp(sz);
      for (int i = 0; i < sz; i++)
          _temp[i] = pMem[i] - m.pMem[i];
      return _temp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("sizes not equal");
      TDynamicMatrix _temp(sz);

      for (int i = 0; i < sz; i++)
          for (int j = 0; j < sz; j++)
              for (int k = 0; k < sz; k++)
                  _temp.pMem[i][j] += pMem[i][k] * m[k][j];
      return _temp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
          for (int j = 0; j < v.sz; j++)
              istr >> v.pMem[i][j];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
      {
            ostr << v[i];
            ostr << endl;
      }
      return ostr;
  }
};

#endif
