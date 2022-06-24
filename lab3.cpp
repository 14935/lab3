#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "bintree.h"
#include "set.h"
using namespace std;

int main()
{
	BinaryTree<int>* tree1 = new BinaryTree<int>();
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 1000000; i++)
	{
		tree1->push(rand() % 1000000);
	}
	BinaryTree<int>* tree2 = new BinaryTree<int>();
	for (int i = 0; i < 1000; i++)
	{
		tree2->push(rand() % 1000000);
	}
	cout << "TIME OF PASSES DATA = 10^6" << endl << "record by different passes K - root| P - right| L - left" << endl;
	clock_t start = clock();
	string s = tree1->TreeToString("KLP");
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "KLP: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("KPL");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "KPL: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("LKP");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "LKP: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("LPK");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "LPK: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("PLK");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "PLK: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("PKL");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	/*for (int i = 0; i < 100000000; i++)
	{
		tree1->push(rand() % 1000000);
	}
	cout << "PKL: " << seconds << endl;
	cout << "TIME OF DATA = 10^8" << endl << "record by different passes K - root| P - right| L - left" << endl;
	start = clock();
	s = tree1->TreeToString("KLP");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "KLP: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("KPL");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "KPL: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("LKP");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "LKP: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("LPK");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "LPK: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("PLK");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "PLK: " << seconds << endl;
	start = clock();
	s = tree1->TreeToString("PKL");
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "PKL: " << seconds << endl;*/
	start = clock();
	BinaryTree<int>* treemap = tree1->Map(gg);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "map time" << seconds << endl;
	start = clock();
	BinaryTree<int>* treered = tree1->Where(bb);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Where time" << seconds << endl;


	start = clock();
	tree1->push(500000);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "push elem time " << seconds << endl;

	start = clock();
	tree1->DeleteElem(500000);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Delete elem time " << seconds << endl;

	start = clock();
	bool b = tree1->Search(500000);
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Search elem time " << seconds << endl;
}