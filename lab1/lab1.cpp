#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//
void fillMatrix(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = (rand()% 255 + 1);
		}
	}
}
void outputClearArray(int *arr, int size) {
	size *= size;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		arr[i] = 0;
	}
}

void rightDiag(int *arr, int **matr, int size) {
	int i = 0, j = size - 1, k = 0;
	int cI = i, cJ = j;
	while (j > 0) {
		arr[k] = matr[cI][cJ];
		k++;
		if (cJ + 1 < size) {
			cI++;
			cJ++;
		} else {
			j--;
			cJ = j;
			cI = 0;
		}
	}
	while (i < size) {
		arr[k] = matr[cI][cJ];
		k++;
		if (cI + 1 < size) {
			cI++;
			cJ++;
		} else {
			i++;
			cI = i;
			cJ = 0;
		}
	}
}
void leftDiag(int *arr, int **matr, int size) {
	int i = 0, j = 0, k = 0;
	int cI = i, cJ = j;
	while (j + 1 < size) {
		arr[k] = matr[cI][cJ];
		k++;
		if (cJ > 0) {
			cI++;
			cJ--;
		} else {
			j++;
			cJ = j;
			cI = 0;
		}
	}
	while (i < size) {
		arr[k] = matr[cI][cJ];
		k++;
		if (cI + 1 < size) {
			cI++;
			cJ--;
		} else {
			i++;
			cI = i;
			cJ = size - 1;
		}
	}
}
void intoCenter(int *arr, int **matr, int size) {
	int i = size, j = size, k = 0;
	int cI = 0, cJ = 0;
	while (k < size * size) {
		while (cJ + 1 < j) {
			arr[k] = matr[cI][cJ];
			k++;
			cJ++;
		}
		while (cI + 1 < i) {
			arr[k] = matr[cI][cJ];
			k++;
			cI++;
		}
		while (cJ > size - j) {
			arr[k] = matr[cI][cJ];
			k++;
			cJ--;
		}
		while (cI - 1 > size - i) {
			arr[k] = matr[cI][cJ];
			k++;
			cI--;
		}
		if (k == size * size - 1) {
			arr[k] = matr[cI][cJ];
			break;
		}
		i--;
		j--;
	}
}
void fromCenter(int *arr, int **matr, int size) {
	int cI = size / 2, cJ = size / 2;
	int i = cI + 1, j = cJ + 1, k = 0;
	if (size % 2 == 0) {
		cJ--; // For chetnie.
	}
	while (k < size * size) {
		while (cJ + 1 < j) {
			if (k == size * size) {
				break;
			}
			arr[k] = matr[cI][cJ];
			k++;
			cJ++;
		}
		j++;
		while (cI > size - i) {
			if (k == size * size) {
				break;
			}
			arr[k] = matr[cI][cJ];
			k++;
			cI--;
		}
		i++;
		while (cJ > size - j) {
			if (k == size * size) {
				break;
			}
			arr[k] = matr[cI][cJ];
			k++;
			cJ--;
		}
		while (cI + 1 < i) {
			if (k == size * size) {
				break;
			}
			arr[k] = matr[cI][cJ];
			k++;
			cI++;
		}
	}
}
//

int main() {
	setlocale(0, "");
	srand(time(0));
	int size = 4;
	cout << "Size: ";
	cin >> size;

	int **matr = new int*[size];
	int *arr = new int[size * size];
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
	}
	fillMatrix(matr, size);

	cout << "#1:\nSourse matrix:\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	rightDiag(arr, matr, size);
	cout << "\nPo right diagonali:\n";
	outputClearArray(arr, size);
	cout << endl;

	leftDiag(arr, matr, size);
	cout << "Po left diagonali:\n";
	outputClearArray(arr, size);
	cout << endl;

	intoCenter(arr, matr, size);
	cout << "Po spirali v centr:\n";
	outputClearArray(arr, size);
	cout << endl;

	fromCenter(arr, matr, size);
	cout << " Po spirali iz centra:\n";
	outputClearArray(arr, size);
	cout << endl;

	delete[] arr;
	for (int t = 0; t < size; t++) {
		delete[] matr[t];
	}
	delete[] matr;

	cout << "\n\n#2:\nEnter quantity string: ";
	int sizearr, limit;
	cin >> sizearr;
	cout << "Enter out  element in string: : ";
	cin >> limit;
	int **randarr = new int *[sizearr];
	int *sizeline = new int[sizearr];
	cout << endl;
	for (int i = 0; i < sizearr; i++) {
		sizeline[i] = rand() % limit + 1;
		randarr[i] = new int[sizeline[i]];
		cout << i << " string, " << sizeline[i] << " elements: ";
		for (int j = 0; j < sizeline[i]; j++) {
			randarr[i][j] = rand() % 255 + 1;
			cout << randarr[i][j] << " ";
		}
		cout << endl;
	}

	delete[] sizeline;
	for (int i = 0; i < sizearr; i++) {
		delete[] randarr[i];
	}
	delete[] randarr;
}
