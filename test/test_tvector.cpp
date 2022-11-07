#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> _test(5);
	for (int i = 0; i < 5; i++)
		_test[i] = i;
	TDynamicVector<int>  _test_1(_test);
	EXPECT_EQ(_test_1, _test);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> _test(5);
	for (int i = 0; i < 5; i++)
		_test[i] = i;
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(i, _test[i]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(2);
  v[0] = 4;
  v[1] = 2;
  EXPECT_EQ(4, v[0]);
  EXPECT_EQ(2, v[1]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(2);
	v[0] = 4;
	v[1] = 2;
  ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(2);
	v[0] = 4;
	v[1] = 2;
	ASSERT_ANY_THROW(v.at(10000022));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(2);
	v[0] = 4;
	v[1] = 2;
	v = v;
	EXPECT_EQ(v[0], 4);
	EXPECT_EQ(v[1], 2);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 4;
	_test[1] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1 = _test;
	EXPECT_EQ(_test_1[0], 4);
	EXPECT_EQ(_test_1[1], 2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> _test(3);
	TDynamicVector<int> _test_1(2);
	_test_1 = _test;
	EXPECT_EQ(_test_1.size(), 3);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> _test(3);
	_test[0] = 4;
	_test[1] = 2;
	_test[2] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 1;
	_test_1[1] = 2;
	_test_1 = _test;
	EXPECT_EQ(_test_1[0], 4);
	EXPECT_EQ(_test_1[1], 2);
	EXPECT_EQ(_test_1[2], 2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> _test(2);
	_test[0] = 4;
	_test[1] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 4;
	_test_1[1] = 2;
	ASSERT_TRUE(_test == _test_1);
  
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> _test(2);
	_test[0] = 4;
	_test[1] = 2;
	ASSERT_TRUE(_test == _test);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> _test(3);
	_test[0] = 4;
	_test[1] = 2;
	_test[2] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 1;
	_test_1[1] = 2;
	ASSERT_FALSE(_test == _test_1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _Res(2);
	_Res = _test + 1;
	ASSERT_TRUE(_Res == _test + 1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _Res(2);
	_Res = _test - 1;
	ASSERT_TRUE(_Res == _test - 1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _Res(2);
	_Res = _test * 2;
	ASSERT_TRUE(_Res == _test * 2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 3;
	_test_1[1] = 4;
	TDynamicVector<int> _Res(2);
	_Res = _test + _test_1;
	EXPECT_EQ(_Res, _test + _test_1);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(3);
	_test_1[0] = 3;
	_test_1[1] = 4;
	_test_1[2] = 5;
	ASSERT_ANY_THROW(_test + _test_1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 3;
	_test_1[1] = 4;
	TDynamicVector<int> _Res(2);
	_Res = _test_1 - _test;
	EXPECT_EQ(_Res, _test_1 - _test);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(3);
	_test_1[0] = 3;
	_test_1[1] = 4;
	_test_1[2] = 5;
	ASSERT_ANY_THROW(_test - _test_1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(2);
	_test_1[0] = 3;
	_test_1[1] = 4;
	int _Res(2);
	_Res = _test_1 * _test;
	EXPECT_EQ(_Res, _test_1 * _test);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> _test(2);
	_test[0] = 1;
	_test[1] = 2;
	TDynamicVector<int> _test_1(3);
	_test_1[0] = 3;
	_test_1[1] = 4;
	_test_1[2] = 5;
	ASSERT_ANY_THROW(_test * _test_1);
}

