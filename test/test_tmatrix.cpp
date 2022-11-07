#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(_test);
	EXPECT_EQ(_test_1, _test);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(_test);
	EXPECT_EQ(_test_1[0][0], 1);
	EXPECT_EQ(_test_1[0][1], 2);
	EXPECT_EQ(_test_1[1][0], 3);
	EXPECT_EQ(_test_1[1][1], 4);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> _test(2);
	EXPECT_EQ(_test.size(), 2);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	EXPECT_EQ(_test[0][0], 1);
	EXPECT_EQ(_test[0][1], 2);
	EXPECT_EQ(_test[1][0], 3);
	EXPECT_EQ(_test[1][1], 4);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	ASSERT_ANY_THROW(_test.at(-10, -100));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	ASSERT_ANY_THROW(_test.at(10, 100));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	_test = _test;
	EXPECT_EQ(_test[0][0], 1);
	EXPECT_EQ(_test[0][1], 2);
	EXPECT_EQ(_test[1][0], 3);
	EXPECT_EQ(_test[1][1], 4);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(2);
	_test_1[0][0] = 5;
	_test_1[0][1] = 6;
	_test_1[1][0] = 7;
	_test_1[1][1] = 8;
	_test_1 = _test;
	EXPECT_EQ(_test_1[0][0], 1);
	EXPECT_EQ(_test_1[0][1], 2);
	EXPECT_EQ(_test_1[1][0], 3);
	EXPECT_EQ(_test_1[1][1], 4);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> _test(2);
	TDynamicMatrix<int> _test_1(3);
	_test_1 = _test;
	EXPECT_EQ(_test_1.size(), 2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(3);
	_test_1[0][0] = 5;
	_test_1[0][1] = 6;
	_test_1[0][2] = 7;
	_test_1[1][0] = 8;
	_test_1[1][1] = 9;
	_test_1[1][2] = 10;
	_test_1[2][0] = 11;
	_test_1[2][1] = 12;
	_test_1[2][2] = 13;
	_test_1 = _test;
	EXPECT_EQ(_test_1[0][0], 1);
	EXPECT_EQ(_test_1[0][1], 2);
	EXPECT_EQ(_test_1[1][0], 3);
	EXPECT_EQ(_test_1[1][1], 4);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(2);
	_test_1[0][0] = 1;
	_test_1[0][1] = 2;
	_test_1[1][0] = 3;
	_test_1[1][1] = 4;
	ASSERT_TRUE(_test == _test_1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	ASSERT_TRUE(_test == _test);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(3);
	_test_1[0][0] = 5;
	_test_1[0][1] = 6;
	_test_1[0][2] = 7;
	_test_1[1][0] = 8;
	_test_1[1][1] = 9;
	_test_1[1][2] = 10;
	_test_1[2][0] = 11;
	_test_1[2][1] = 12;
	_test_1[2][2] = 13;
	ASSERT_FALSE(_test == _test_1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(2);
	_test_1[0][0] = 1;
	_test_1[0][1] = 2;
	_test_1[1][0] = 3;
	_test_1[1][1] = 4;
	TDynamicMatrix<int> _Res(2);
	_Res = _test + _test_1;
	ASSERT_TRUE(_Res == _test + _test_1);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(3);
	_test_1[0][0] = 5;
	_test_1[0][1] = 6;
	_test_1[0][2] = 7;
	_test_1[1][0] = 8;
	_test_1[1][1] = 9;
	_test_1[1][2] = 10;
	_test_1[2][0] = 11;
	_test_1[2][1] = 12;
	_test_1[2][2] = 13;
	ASSERT_ANY_THROW(_test + _test_1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(2);
	_test_1[0][0] = 1;
	_test_1[0][1] = 2;
	_test_1[1][0] = 3;
	_test_1[1][1] = 4;
	TDynamicMatrix<int> _Res(2);
	_Res = _test - _test_1;
	ASSERT_TRUE(_Res == _test - _test_1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> _test(2);
	_test[0][0] = 1;
	_test[0][1] = 2;
	_test[1][0] = 3;
	_test[1][1] = 4;
	TDynamicMatrix<int> _test_1(3);
	_test_1[0][0] = 5;
	_test_1[0][1] = 6;
	_test_1[0][2] = 7;
	_test_1[1][0] = 8;
	_test_1[1][1] = 9;
	_test_1[1][2] = 10;
	_test_1[2][0] = 11;
	_test_1[2][1] = 12;
	_test_1[2][2] = 13;
	ASSERT_ANY_THROW(_test - _test_1);
}

