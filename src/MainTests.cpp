#include "MainTests.hpp"
#include <chrono>
#include <cmath>
#include <fstream>
#include "DHeap.hpp"

void Test3_1A()
{
	int q = 1;
	int r = pow(10, 6);
	std::fstream file;
	file.open("Exp3.1(a).txt", std::fstream::out);
	std::cout << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int n = 1; n < pow(10, 4) + 2; n += 100)
	{
		DHeap h(2, n, pow(n, 2) / 10 - 2, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}


void Test3_1B()
{
	int q = 1;
	int r = pow(10, 6);
	std::fstream file;
	file.open("Exp3.1(b).txt", std::fstream::out);
	std::cout << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int n = 1; n < pow(10, 4) + 2; n += 100)
	{
		DHeap h(2, n, pow(n, 2) - 2, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}

void Test3_2A()
{
	int q = 1;
	int r = pow(10, 6);
	std::fstream file;
	file.open("Exp3.2(a).txt", std::fstream::out);
	std::cout << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int n = 101; n < pow(10, 4) + 2; n += 100)
	{
		DHeap h(2, n, 100 * n - 2, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}

void Test3_2B()
{
	int q = 1;
	int r = pow(10, 6);
	std::fstream file;
	file.open("Exp3.2(b).txt", std::fstream::out);
	std::cout << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "n\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int n = 101; n < pow(10, 4) + 2; n += 100)
	{
		DHeap h(2, n, 1000 * n - 2, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << n << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}

void Test3_3()
{
	int q = 1;
	int r = pow(10, 6);
	int n = pow(10, 4);
	std::fstream file;
	file.open("Exp3.3.txt", std::fstream::out);
	std::cout << "m\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "m\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int m = 0; m < pow(10, 7) + 1; m += pow(10,5))
	{
		DHeap h(2, n, m, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << m << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << m << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}

void Test3_4A()
{
	int q = 1;
	int n = pow(10, 4);
	int m = pow(n, 2) - 2;
	std::fstream file;
	file.open("Exp3.4(a).txt", std::fstream::out);
	std::cout << "r\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "r\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int r = 0; r < 201; r++)
	{
		DHeap h(2, n, m, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << r << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << r << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}

void Test3_4B()
{
	int q = 1;
	int n = pow(10, 4);
	int m = 1000 * n - 2;
	std::fstream file;
	file.open("Exp3.4(b).txt", std::fstream::out);
	std::cout << "r\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	file << "r\t" << "time 2-heap\t" << "time 3-heap" << std::endl;
	for (int r = 0; r < 201; r++)
	{
		DHeap h(2, n, m, q, r);
		auto begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		auto end = std::chrono::steady_clock::now();
		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << r << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		file << r << "\t" << (double)elapsed_ms.count() / 1000 << "\t\t";
		h.SetD(3);
		begin = std::chrono::steady_clock::now();
		h.LDG_DIJKSTRA_DHEAP(1);
		end = std::chrono::steady_clock::now();
		elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		std::cout << (double)elapsed_ms.count() / 1000 << std::endl;
		file << (double)elapsed_ms.count() / 1000 << std::endl;
	}
	file.close();
}
