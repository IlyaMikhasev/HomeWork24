#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void fill_arr(T arr[], const int length,T begin,T end);
template <typename T>
void resize_arr(T *&arr, const int length, int length2);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m, w;
	
	std::cout<<"Введите длину первого массива ->";
	std::cin >> n;
	int* A = new int[n];
	std::cout << "Введите длину второго массива ->";
	std::cin >> m;
	int* B = new int[m];
	fill_arr(A, n, -5, 6);
	fill_arr(B, m, 0, 10);
	std::cout << "Первый массив: ";
	show_arr(A, n);
	std::cout << "Второй массив: ";
	show_arr(B, m);
	int* C = new int[n+m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = 0; i < n + m; i++)
		C[n+i] = B[i];
	std::cout << "Полученный массив: ";
	show_arr(C, n + m);
	delete[] A;
	delete[] B;
	
	std::cout << "\nЗадача 2.\nИмеющийся массив: ";
	const int size = 10;
	int* mass = new int[size] {};
	fill_arr(mass, size, -5, 6);
	show_arr(mass, size);
	std::cout << "Введите новый размер массива ->";
	std::cin >> w;
	resize_arr(mass, size, w);
	std::cout << "Получившийся массив: ";
	show_arr(mass, w);
	return 0;
}
//вывод массива
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//заполнение массива
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//Изменение размера массива
template <typename T>
void resize_arr(T *&arr, const int length, int length2) {
	if (length2 < 0) {
		std::cout << "Длинна массива должна быть положительной!\n";
		return;
	}
	if (length2 == 0) {
		delete[] arr;
		arr = new int[0];
		return;
	}
	T* array = new T[length2] {};
	if (length >= length2) {
		for (int i = 0; i < length2; i++)
			array[i] = arr[i];
		delete[]arr;
		arr = array;
	}
	else {
		for(int i=0;i<length;i++)
			array[i] = arr[i];
		delete[]arr;
		arr = array;
	}

}