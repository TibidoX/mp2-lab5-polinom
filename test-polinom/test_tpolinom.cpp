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
TEST(TPolinom, polinoms_have_different_mem)
{
	TPolinom t;
	TPolinom p(t);
	EXPECT_EQ(false, &t == &p);
}
//TEST(TPolinom, can_add_monom)
//{
//	TPolinom p;
//	TMonom m(1, 2, 3, 4);
//	ASSERT_NO_THROW(p.AddMonom(m));
//}
