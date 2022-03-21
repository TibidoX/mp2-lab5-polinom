#include "../mp2-lab5-polinom/TPolinom.h"
#include "gtest.h"

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}
TEST(TPolinom, after_create_polinom_is_empty)
{
	TPolinom p;
	EXPECT_EQ(true, p.IsEmpty());
}

TEST(TPolinom, can_create_equal_polinom)
{
	TPolinom t;
	ASSERT_NO_THROW(TPolinom p(t));
}
TEST(TPolinom, copied_polinom_is_equal)
{
	TPolinom t(1, 2, 3, 4);
	TPolinom p(t);
	EXPECT_EQ(true, t == p);
}
TEST(TPolinom, polinoms_have_different_memory)
{
	TPolinom t;
	TPolinom p(t);
	EXPECT_EQ(false, &t == &p);
}
TEST(TPolinom, can_add_monom)
{
	TPolinom p;
	TMonom m(1, 2, 3, 4);
	ASSERT_NO_THROW(p.AddMonom(m));
}
TEST(TPolinom, comparison_of_equal_polynoms)
{
	TPolinom p1;
	TPolinom p2;
	TMonom m(1, 2, 3, 4);
	p1.AddMonom(m);
	p2.AddMonom(m);
	EXPECT_EQ(true, p1 == p2);
}
TEST(TPolinom, comparison_of_not_equal_polynoms)
{
	TPolinom p1;
	TPolinom p2;
	TMonom m(1, 2, 3, 4);
	p1.AddMonom(m);
	EXPECT_EQ(true, p1 != p2);
}
TEST(TPolinom, add_when_monom_is_missing)
{
	TPolinom p;
	TPolinom res(1, 2, 3, 4);
	TMonom m1(1, 2, 3, 4);
	p.AddMonom(m1);
	EXPECT_EQ(true, res == p);
}
TEST(TPolinom, add_when_monom_is_exists)
{
	TPolinom p(2, 2, 3, 4);
	TPolinom res(3, 2, 3, 4);
	TMonom m1(1, 2, 3, 4);
	p.AddMonom(m1);
	EXPECT_EQ(true, res == p);
}
TEST(TPolinom, sum_of_polinoms)
{
	TPolinom res;
	TMonom m1(1, 2, 3, 4);
	TMonom m2(10, 9, 8, 7);
	res.AddMonom(m1);
	res.AddMonom(m2);

	TPolinom p1(1, 2, 3, 4);
	TPolinom p2(10, 9, 8, 7);
	EXPECT_EQ(true, p1+p2==res);
}
TEST(TPolinom, diff_of_polinoms)
{
	TPolinom res;
	TMonom m1(1, 2, 3, 4);
	TMonom m2(-10, 9, 8, 7);
	res.AddMonom(m1);
	res.AddMonom(m2);

	TPolinom p1(1, 2, 3, 4);
	TPolinom p2(10, 9, 8, 7);
	EXPECT_EQ(true, p1 - p2 == res);
}
TEST(TPolinom, can_assign_polinoms)
{
	TPolinom p1;
	TPolinom p2;
	ASSERT_NO_THROW(p1 = p2);
}
TEST(TPolinom, assign_polinoms_are_equals)
{
	TPolinom p1(1,2,3,4);
	TPolinom p2;
	p1 = p2;
	EXPECT_EQ(true, p1 == p2);
}
TEST(TPolinom, mult_by_scalar)
{
	TPolinom p(1, 1, 1, 1);
	TPolinom res(2, 1, 1, 1);
	EXPECT_EQ(true, res == p * 2);
}
TEST(TPolinom, mult_by_monom)
{
	TMonom m(1, 2, 3, 4);
	TPolinom p(1, 1, 1, 1);
	TPolinom res(1, 3, 4, 5);
	EXPECT_EQ(true, res == (p * m));
}