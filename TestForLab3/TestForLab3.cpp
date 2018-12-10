#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab3/BinaryTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestForLab3
{		
	TEST_CLASS(BinaryTreeTests)
	{
	public:

		TEST_METHOD(insertFunctionTestToBegin) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6 };
			int i = 0;
			for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), bfsArray[i++]);
			delete tree;
		}

		TEST_METHOD(insertFunctionTestToMiddleEnd){
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6,2,11,3,9,30,13,18 };
			int i=0;
			for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), bfsArray[i++]);
			delete tree;
		}

		TEST_METHOD(containsFunctionTestIsTrue) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6,2,11,3,9,30,13,18 };
			for (int i = 0; i < 8; ++i)
				Assert::IsTrue(tree->contains(bfsArray[i]));
			delete tree;
		}

		TEST_METHOD(containsFunctionTestIsFalse) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int wrongArray[] = { 7,100,12,4,10,31,14,19 };
			for (int i = 0; i < 8; ++i)
				Assert::IsFalse(tree->contains(wrongArray[i]));
			delete tree;
		}

		TEST_METHOD(containsFunctionTestOnEmptyTree) {
			BinaryTree *tree = new BinaryTree();
			Assert::IsFalse(tree->contains(1));
			delete tree;
		}

		TEST_METHOD(removeFunctionTestFormMiddle) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6,2,9,3,30,13,18 };
			tree->remove(11);
			int i = 0;
			for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), bfsArray[i++]);
			delete tree;
		}

		TEST_METHOD(removeFunctionTestFormEnd) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6,2,11,3,9,30,13 };
			tree->remove(18);
			int i = 0;
			for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), bfsArray[i++]);
			delete tree;
		}

		TEST_METHOD(removeFunctionTestWrongKey) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int bfsArray[] = { 6,2,11,3,9,30,13, 18 };
			tree->remove(100);
			int i = 0;
			for (BinaryTree::BfsIterator *tmp = tree->createBfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), bfsArray[i++]);
			delete tree;
		}

		TEST_METHOD(removeFunctionTestFormEmpty) {
			BinaryTree *tree = new BinaryTree();
			tree->remove(18);
			Assert::IsTrue(1);
			delete tree;
		}
	};
	TEST_CLASS(DFSIteratortests)
	{
	public:
		TEST_METHOD(insertFunctionTest) {
			BinaryTree *tree = new BinaryTree();
			int arrayForTree[] = { 6,2,3,11,9,30,13,18 };
			for (int i : arrayForTree) tree->insert(i);
			const int dfsArray[] = { 2,3,6,9,11,13,18,30 };
			int i = 0;
			for (BinaryTree::DfsIterator *tmp = tree->createDfsIterator(); tmp->hasNext(); tmp->next())
				Assert::AreEqual(tmp->current(), dfsArray[i++]);
			delete tree;
		}

	};
}
