/*
 * MainMethod.cpp
 *
 *  Created on: 14 Aug 2023
 *  Author: IO DevBlue
 */
//#include "SandBoxClassOne.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <variant>

using namespace std;

int g = 0;

class inter {
public:
	inter(int s): ggg(s) {}
	int prt() {
		cout<<"Number provided is "<<ggg<<endl;
		return (ggg);
	}

	int gg() const {
		return (ggg);
	}
private:
	int ggg;
};

template<typename T>
concept inter_concept = requires(T a) {
	{a.prt()}->same_as<int>;
	{a.gg()}->same_as<int>;

};

void print_inters() {
	cout<<"The sum of inters: "<<g<<endl;
}
template<inter_concept inter, inter_concept... inters>
void print_inters(inter start, inters... others) {
	g+=start.prt();
	print_inters(others)...;
}

template<inter_concept... inters>
int print_inters_once(inters... ghj) {
	return (ghj.prt()+...+0);
}

int main() {
//	cout<<"Second trial"<<endl;
	inter ff(999), aa(80), bb(8), ll(67);
	print_inters(ff, aa, bb, ll);
//	cout<<print_inters_once(ff, aa, bb, ll);
}
