#include "stdafx.h"
#include <array>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <chrono>


int main()
{
	
	std::array<char, 1000000> v;
	std::generate(v.begin(), v.end(), std::rand);
	int key = 0;
	int j;
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < v.size();i++) {
		key = v[i];
		j = i - 1;
		for (; j >= 0&&v[j]>key; j--) {
			v[j + 1] = v[j];
		}
		v[j + 1] = key;

	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	int i = 0;
	for (; i < v.size(); i++) {
		std::cout << v[i] << " ";
		if (i % 30==0) std::cout << std::endl;
	}
	std::cout << std::endl << i << " elementov" << std::endl;
	std::cout << std::endl << "Elipsed time: " << elapsed.count() << "s\n";
	
	system("pause");

    return 0;
}

