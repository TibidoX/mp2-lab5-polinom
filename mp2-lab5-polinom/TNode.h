#pragma once

template <class T>
struct TNode
{
	T val;
	TNode* pNext;

	TNode(T v, TNode* p)
	{
		val = v;
		pNext = p;
	}
	TNode(){}
};