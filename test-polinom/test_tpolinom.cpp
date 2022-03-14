#include "../mp2-lab5-polinom/TPolinom.h"
#include "gtest.h"

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, queue_is_empty_after_create)
{
	EXPECT_EQ(1, 1);
}
//
//TEST(TListQueue, can_create_copied_queue)
//{
//	TListQueue<int> m;
//	ASSERT_NO_THROW(TListQueue<int> m1(m));
//}
//
//TEST(TListQueue, copied_queue_is_equal_to_source_one)
//{
//	TListQueue<int> m;
//	for (int i = 0; i < 9; i++)
//	{
//		m.Push(i);
//		//mm.Push(i+1);
//	}
//	TListQueue<int> mm(m);
//
//	EXPECT_EQ(m, mm);
//}
//
//TEST(TListQueue, copied_queue_has_its_own_memory)
//{
//	TListQueue<int> m;
//	TListQueue<int> mm(m);
//	EXPECT_NE(&m, &mm);
//}
//
//TEST(TListQueue, can_assign_queue_to_itself)
//{
//	TListQueue<int> m;
//	ASSERT_NO_THROW(m = m);
//}
//
//TEST(TListQueue, compare_equal_queues_return_true)
//{
//	TListQueue<int> m;
//	TListQueue<int> mm;
//	for (int i = 0; i < 9; i++)
//	{
//		m.Push(i);
//		mm.Push(i);
//	}
//	EXPECT_EQ(true, m == mm);
//}
//
//TEST(TListQueue, compare_queue_with_itself_return_true)
//{
//	TListQueue<int> m;
//
//	EXPECT_EQ(true, m == m);
//}
//
//TEST(TListQueue, compare_not_equal_queues_return_false)
//{
//	TListQueue<int> m;
//	TListQueue<int> mm;
//	for (int i = 0; i < 9; i++)
//	{
//		m.Push(i);
//		mm.Push(i + 1);
//	}
//	EXPECT_EQ(false, m == mm);
//}
//
//TEST(TListQueue, can_push_if_queue_isnt_full)
//{
//	TListQueue<int> m;
//	m.Push(1);
//
//	EXPECT_EQ(m.Pop(), 1);
//}
//
//TEST(TListQueue, can_pop_if_queue_isnt_empty)
//{
//	TListQueue<int> m;
//	m.Push(1);
//	EXPECT_EQ(m.Pop(), 1);
//}
//
//TEST(TListQueue, cant_pop_if_queue_is_empty)
//{
//	TListQueue<int> m;
//	ASSERT_ANY_THROW(m.Pop());
//}
//
//TEST(TListQueue, can_assign_queues)
//{
//	TListQueue<int> m;
//	TListQueue<int> mm;
//	for (int i = 0; i < 9; i++)
//	{
//		m.Push(i);
//		mm.Push(i + 1);
//	}
//	m = mm;
//	EXPECT_EQ(m, mm);
//}
//
//TEST(TListQueue, queue_is_empty_after_clear)
//{
//	TListQueue<int> m;
//	for (int i = 0; i < 9; i++)
//	{
//		m.Push(i);
//	}
//	m.Clear();
//	EXPECT_EQ(m.IsEmpty(), true);
//}