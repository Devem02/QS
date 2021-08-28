/*
@file mainSource.cpp
@date 08/06/2021
@author Diego Vega Mora
@tittle Quicksort
@code
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/*
@param un vector
@param un numero que inicializa
@param un numero que finalice
@retrurn un numero
@brief Algoritmo auxiliar del quicksort
*/
int particion(vector<int>& array, int inicio, int fin) {
	int pivote = array[inicio];
	int i = inicio + 1;
	for (int j = i; j <= fin; j++) {
		if (array[j] < pivote) {
			swap(array[i], array[j]);
			i++;
		}
	}
	swap(array[inicio], array[i - 1]);
	return i - 1;
}
/*
@param un vector
@param un numero que inicializa
@param un numero que finalice
@retrurn
@brief Algoritmo auxiliar del quicksort
*/
void quickSort(vector<int>& array, int inicio, int fin) {
	if (inicio < fin) {
		int pivote = particion(array, inicio, fin);
		quickSort(array, inicio, pivote - 1);
		quickSort(array, pivote + 1, fin);
	}
}

int* read(string name);
void write(string name, vector<int> array);

int main() {

	int* arreglo = read("numeros.txt");
	vector<int>array;//se crea el vector para el quicksort
	for (int i = 0; i <= 4; i++) {
		array.push_back(arreglo[i]);//agrega los elementos del array al vector
	}
	quickSort(array, 0, array.size() - 1);
	write("numeros.txt", array);
	return 0;
}

/*
@param un nombre de archivo
@retrurn un array
@brief De un archivo, toma los numeros y los pasa a un array.
*/
int* read(string name) {

	ifstream file;
	string numbers;
	int i = 0;
	char num[10];
	int myArray[5];


	file.open(name, ios::in);

	if (file.fail()) {
		cout << "Error al abrir el archivo";
		exit(1);
	}

	if (file.is_open()) {

		while (file.good()) {

			file.getline(num, 256, ',');
			myArray[i] = atoi(num);
			i++;
		}
		file.close();
	}
	else {}
	return myArray;
}

/*
@param un nombre de archivo
@param un vector
@retrurn
@brief reescribe el archivo con el vector.
*/
void write(string name, vector<int> array) {
	ofstream file;

	file.open(name, ios::out);

	if (file.fail()) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	for (int i = 0; i <= 4; i++) {
		file << array[i] << endl;
	}
	file.close();
}


