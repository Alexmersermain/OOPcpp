//Задание №1 по спецкурсу ООП
//Выполнил: Григорьев Александр. гр. 1123
#include "StdAfx.h"
#include <stdio.h>
#include <iostream>
#include "XlistRelease.h"
using namespace std;

int main( )
{
	Xlist<double> ld; //ld - объект linklist<double>
	ld.display();
	ld.displayB();
	ld.addItemF(23.16);
	ld.addItemB(24.01);
	ld.addItemB(25.0);
	ld.addItemF(15.0);
	ld.display();
	double d=ld.getF();
	cout<<"--the first element: "<<d<<endl;
	ld.removeB();
	ld.display();
	ld.clean();
	Xlist<char> lch; //lch - объект linklist<char>
	lch.addItemF('b'); 
	lch.addItemF('a');
	lch.addItemB('c');
	lch.display(); 
	lch.displayB(); 
	char ch=lch.getB();
	cout<<"--the last element: "<<ch<<endl;
	lch.removeF();
	lch.display();
	cout << endl;
	return 0;
}