#pragma once

template <class T>
struct TNode
{
	T val;
	TNode* pNext;

	TNode(T v, TNode* p=nullptr)
	{
		val = v;
		pNext = p;
	}
};