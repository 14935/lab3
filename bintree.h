#ifndef MY_CLASS1_H 
#define MY_CLASS1_H
#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Person
{
private:
	string name;
	int birthdate;
public:
	Person(string name, long int birthdate)
	{
		this->name = name;
		this->birthdate = birthdate;
	}
	string Getname()
	{
		return this->name;
	}
	int Getbirthdate()
	{
		return this->birthdate;
	}
};
bool Iseequal(char a, char b)
{
	return a == b;
}
bool Isequal(int a, int b)
{
	return a == b;
}
bool Isequal(double a, double b)
{
	return a == b;
}
bool Isequal(complex<int> a, complex<int> b)
{
	return a == b;
}
bool Isequal(complex<double> a, complex<double> b)
{
	return a == b;
}
bool Isequal(string a, string b)
{
	return a == b;
}
bool Isequal(Person* a, Person* b)
{
	return (a->Getbirthdate() == b->Getbirthdate() && a->Getname() == b->Getname());
}
complex<int> max(complex<int> a, complex<int> b)
{
	if (a.real() > b.real()) return a;
	return b;
}
complex<double> max(complex<double> a, complex<double> b)
{
	if (a.real() > b.real()) return a;
	return b;
}
Person* max(Person* a, Person* b)
{
	if (a->Getbirthdate() > b->Getbirthdate()) return a;
	else return b;
}
int gg(int a)
{
	return a * 2;
}
bool bb(int a)
{
	return (a % 10 == 4);
}
int rf(int a, int b)
{
	return a + b;
}

string toString(int val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}
string toString(double val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}
string toString(char val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}
string toString(string val)
{
	return val;
}
string toString(complex<int> val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}
string toString(complex<double> val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}
string toString(Person* val)
{
	string str = toString(val->Getname()) + " " + toString(val->Getbirthdate());
	return str;
}
template<typename T>
class TreeNode
{
private:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* parent;
	TreeNode(T data, TreeNode<T>* parent)
	{
		this->parent = parent;
		this->left = nullptr;
		this->right = nullptr;
		this->data = data;
	}
	TreeNode(T data)
	{
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
		this->data = data;
	}
	template<typename T> friend class BinaryTree;
};

template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
	int size;
	void Delete(TreeNode<T>* node)
	{
		if (node)
		{
			Delete(node->left);
			Delete(node->right);
			delete node;
		}
	}
	void Print(TreeNode<T>* node)
	{
		if (node)
		{
			cout << endl;
			if (node->parent) cout << " par: " << node->parent->data << " |";
			cout << "self: " << node->data << " |";
			if (node->left)cout << " left: " << node->left->data << "  | ";
			if (node->right)cout << " right:" << node->right->data;
			Print(node->left);

			Print(node->right);
		}
	}
	void ExtractNode(TreeNode<T>* node, BinaryTree<T>* newTree)
	{
		if (node)
		{
			newTree->push(node->data);
			ExtractNode(node->left, newTree);
			ExtractNode(node->right, newTree);
		}
	}
	void PushNodeMap(T(*mapFunc)(T), BinaryTree<T>* newTree, TreeNode<T>* node)
	{
		if (node)
		{
			PushNodeMap(mapFunc, newTree, node->left);
			if (!this->Search(mapFunc(node->data)))
			{
				newTree->push(mapFunc(node->data));
			}
			PushNodeMap(mapFunc, newTree, node->right);

		}
	}
	void PushNodeWhere(bool (*whereFunc)(T), BinaryTree<T>* newTree, TreeNode<T>* node)
	{
		if (node)
		{
			PushNodeWhere(whereFunc, newTree, node->left);
			if (whereFunc(node->data)) {
				newTree->push(node->data);
			}
			PushNodeWhere(whereFunc, newTree, node->right);

		}
	}
	void ReduceNode(T(*reduceFunc)(T, T), T* resVal, TreeNode<T>* node)
	{
		if (node)
		{
			ReduceNode(reduceFunc, resVal, node->right);
			*resVal = reduceFunc(node->data, *resVal);

			ReduceNode(reduceFunc, resVal, node->left);
		}
	}
	void IsSubElem(TreeNode<T>* subNode, TreeNode<T>* node, bool* issub)
	{
		if (node && subNode)
		{
			IsSubElem(subNode->left, node->left, issub);
			if (!Isequal(subNode->data, subNode->data))
			{
				*issub = false;
				return;
			}
			IsSubElem(subNode->right, node->right, issub);
		}
		if (node == nullptr && (subNode != nullptr)) *issub = false;
	}
	void MakeVine(TreeNode<T>* node)
	{
		if (node)
		{
			while (node->right != nullptr)
			{
				if (node->parent == nullptr)
				{

					TreeNode<T>* r = node->right;
					TreeNode<T>* b = node->right->left;
					node->parent = r;
					r->parent = nullptr;
					r->left = node;
					node->right = b;
					this->root = r;
					if (b != nullptr)b->parent = node;

				}
				else
				{
					TreeNode<T>* r = node->right;
					TreeNode<T>* q = node->parent;
					TreeNode<T>* b = node->right->left;
					node->parent = r;
					node->right = b;
					q->left = r;
					r->left = node;
					r->parent = q;
					if (b != nullptr) b->parent = node;
				}
				node = node->parent;
			}
			MakeVine(node->left);
		}
	}
	void Balance()
	{
		int j;

		double d = this->size;
		int len = this->size;
		j = floor(log2(this->size + 1));
		//cout << endl << " j = " << j<<endl;
		for (int i = 1; i <= j; i++)
		{
			TreeNode<T>* node = this->root;
			d = len;
			//cout << "len:" << len << endl;
			OneBalance(node, len - i, 0);
			len = ceil((d - i) / 2) + i;
			//cout << "BALANSED" << endl;
			//this->PrintAll();
		}

	}
	void OneBalance(TreeNode<T>* node, int len, int nodenum)
	{
		if (node && nodenum < len)
		{

			if (nodenum % 2 == 0)
			{
				//cout <<endl<< 0 << " " << nodenum << " " << len<<" n:"<<node->data<<endl;
				OneBalance(node->left, len, nodenum + 1);
			}
			else
			{

				if (node->parent->parent == nullptr)
				{
					//cout << endl << 1 << " " << nodenum << " " << len << " n:" << node->data << endl;
					TreeNode<T>* p = node->parent;
					TreeNode<T>* b = node->right;
					node->parent = nullptr;
					this->root = node;
					node->right = p;
					p->left = b;
					p->parent = node;
					if (b != nullptr) b->parent = p;
					//this->PrintAll();

				}
				else
				{
					//cout << endl << 2 << " " << nodenum << " " << len << " n:" << node->data << endl;
					TreeNode<T>* p = node->parent;
					TreeNode<T>* pp = node->parent->parent;
					TreeNode<T>* b = node->right;
					node->right = p;
					node->parent = pp;
					pp->left = node;
					p->parent = node;
					p->left = b;
					if (b != nullptr) b->parent = p;
					//this->PrintAll();
				}
				OneBalance(node->left, len, nodenum + 1);
			}
		}
	}
	void StringByDifferentPass(TreeNode<T>* node, string pass, string* TtoS)
	{
		if (node)
		{
			//cout << " alf | 0 "<<pass[0]<<" | 1 "<<pass[1] <<" | 2 " << pass[2];

			for (int i = 0; i < 3; i++)
			{
				//cout <<node->data<<" " << pass[i] << " " << i << endl;
				//cout << " one ";
				if (pass[i] == 'K')
				{

					*TtoS += toString(node->data) + " ";
					//cout << node->data << " " << *TtoS << endl;
				}
				if (pass[i] == 'L') StringByDifferentPass(node->left, pass, TtoS);
				if (pass[i] == 'P') StringByDifferentPass(node->right, pass, TtoS);
			}
		}
	}
	void TreeMerge(BinaryTree<T>* newTree, TreeNode<T>* node)
	{
		if (node)
		{
			newTree->push(node->data);
			TreeMerge(newTree, node->left);
			TreeMerge(newTree, node->right);
		}
	}
	void TreeCross(BinaryTree<T>* newTree, BinaryTree<T>* onemoreTree, TreeNode<T>* node)
	{
		if (node)
		{
			if (onemoreTree->Search(node->data)) newTree->push(node->data);
			TreeCross(newTree, onemoreTree, node->left);
			TreeCross(newTree, onemoreTree, node->right);
		}
	}
	void TreeSubtr(BinaryTree<T>* newTree, BinaryTree<T>* onemoreTree, TreeNode<T>* node)
	{
		if (node)
		{
			if (!onemoreTree->Search(node->data)) newTree->push(node->data);
			TreeSubtr(newTree, onemoreTree, node->left);
			TreeSubtr(newTree, onemoreTree, node->right);
		}
	}
	void IsNodeEq(BinaryTree<T>* onemoreTree, TreeNode<T>* node, bool* iseq)
	{
		if (node)
		{
			if (!onemoreTree->Search(node->data)) *iseq = false;
			IsNodeEq(onemoreTree, node->left, iseq);
			IsNodeEq(onemoreTree, node->right, iseq);

		}
	}
	void IsSetOfNodeSub(TreeNode<T>* node, bool* issub)
	{
		if (node) {
			if (!this->Search(node->data)) *issub = false;
			IsSetOfNodeSub(node->left, issub);
			IsSetOfNodeSub(node->right, issub);
		}
	}
public:
	BinaryTree(T data)
	{
		this->root = new TreeNode<T>(data);
		this->size = 1;
	}
	BinaryTree()
	{
		size = 0;
		root = nullptr;
	}
	~BinaryTree()
	{
		if (size > 0) Delete(this->root);
	}
	void PrintAll()
	{
		cout << endl << "+++++++++++++++++++++++++++" << endl;
		cout << this->size << endl;
		Print(this->root);
		cout << endl << "------------------------";
	}
	bool Search(T data)
	{
		TreeNode<T>* node = root;
		while (node && (!Isequal(node->data, data)))
		{
			if (Isequal(max(node->data, data), node->data))
			{
				node = node->left;
			}
			else
				node = node->right;
		}
		return node != nullptr;
	}
	void push(T data)
	{
		if (size == 0)
		{
			root = new TreeNode<T>(data);
			size = 1;

			return;
		}
		TreeNode<T>* node = root;
		while (node && (!Isequal(node->data, data)))
		{
			if (Isequal(max(node->data, data), node->data) && node->left == NULL)
			{
				node->left = new TreeNode<T>(data, node);
				size++;
				return;
			}
			if (Isequal(max(node->data, data), data) && node->right == NULL)
			{
				node->right = new TreeNode<T>(data, node);
				size++;
				return;
			}
			if (node->data > data)
				node = node->left;
			else
				node = node->right;

		}
	}
	void DeleteElem(T data)
	{
		TreeNode<T>* node = root;
		if (size <= 0)  return;
		while (node && (!Isequal(node->data, data)))
		{
			if (Isequal(max(node->data, data), node->data))
				node = node->left;
			else
				node = node->right;
		}
		if (!node) return;
		size--;
		if (node == this->root)
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				root = nullptr;
				delete node;
				return;
			}
			if (node->left == nullptr)
			{
				root = node->right;
				delete node;
				return;
			}
			if (node->right == nullptr)
			{
				root = node->left;
				delete node;
				return;
			}
			TreeNode<T>* change = node->right;
			while (change->left)
				change = change->left;
			T changeData = change->data;
			DeleteElem(changeData);
			node->data = changeData;
			return;
		}
		if (node->left == nullptr)
		{
			if (node->parent->left == node)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
			delete node;
			return;
		}
		if (node->right == nullptr)
		{
			if (node->parent->left == node)
				node->parent->left = node->left;
			else
				node->parent->right = node->left;
			delete node;
			return;
		}
		TreeNode<T>* change = node->right;
		while (change->left)
			change = change->left;
		T changeData = change->data;
		DeleteElem(changeData);
		node->data = changeData;
		return;
	}
	BinaryTree<T>* Map(T(*mapFunc)(T))
	{
		BinaryTree<T>* newTree = new BinaryTree<T>();
		PushNodeMap(mapFunc, newTree, this->root);
		return newTree;
	}
	BinaryTree<T>* Where(bool (*whereFunc)(T))
	{
		BinaryTree<T>* newTree = new BinaryTree<T>();
		PushNodeWhere(whereFunc, newTree, this->root);
		return newTree;
	}
	T Reduce(T(*reduceFunc)(T, T), T initval)
	{
		T* resVal = &initval;
		ReduceNode(reduceFunc, resVal, this->root);
		cout << endl;
		return *resVal;
	}
	void PerfectBalance()
	{
		if (this->size < 3) return;
		TreeNode<T>* node = this->root;
		MakeVine(node);
		//this->PrintAll();
		Balance();
	}
	bool IsSubTree(BinaryTree<T>* subTree)
	{
		TreeNode<T>* node = root;
		while (node && (!Isequal(node->data, subTree->root->data)))
		{
			if (Isequal(max(node->data, subTree->root->data), node->data))
			{
				node = node->left;
			}
			else
				node = node->right;
		}
		if (node == nullptr)return 0;
		bool issub = true;
		IsSubElem(subTree->root, node, &issub);
		return issub;
	}
	BinaryTree<T>* ExtractSub(T data)
	{
		TreeNode<T>* node = root;
		while (node && (!Isequal(node->data, data)))
		{
			if (Isequal(max(node->data, data), node->data))
			{
				node = node->left;
			}
			else
				node = node->right;
		}
		BinaryTree<int>* newTree = new BinaryTree<int>();
		if (node == nullptr)
		{

			return newTree;
		}
		ExtractNode(node, newTree);
		return newTree;
	}
	string TreeToString(string pass)
	{
		TreeNode<T>* node = this->root;
		string TtoS = "";
		StringByDifferentPass(node, pass, &TtoS);
		return TtoS;
	}

	BinaryTree<T>* Merge(BinaryTree<T>* onemoreTree)
	{
		BinaryTree<T>* newTree = new BinaryTree<T>();
		TreeMerge(newTree, this->root);
		TreeMerge(newTree, onemoreTree->root);
		return newTree;
	}
	BinaryTree<T>* Cross(BinaryTree<T>* onemoreTree)
	{
		BinaryTree<T>* newTree = new BinaryTree<T>();
		TreeCross(newTree, onemoreTree, this->root);
		return newTree;
	}
	BinaryTree<T>* Subtr(BinaryTree<T>* onemoreTree)
	{
		BinaryTree<T>* newTree = new BinaryTree<T>();
		TreeSubtr(newTree, onemoreTree, this->root);
		return newTree;
	}
	bool IsTreeEq(BinaryTree<T>* onemoreTree)
	{
		if (this->size != onemoreTree->size) return 0;
		bool iseq = true;
		IsNodeEq(onemoreTree, this->root, &iseq);
		return iseq;
	}
	bool IsSetOfTreeSub(BinaryTree<T>* onemoreTree)
	{
		if (this->size < onemoreTree->size) return 0;
		bool issub = true;
		IsSetOfNodeSub(onemoreTree->root, &issub);
		return issub;
	}
};

#endif