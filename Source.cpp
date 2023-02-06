#include <iostream>

void Fullfill(int r, int c, int** matrix)
{
	srand(time(nullptr));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			matrix[i][j] = 1 + rand() % 70;
		}
	}
}

void print(int r, int c, int** matrix)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
	}
}

void printarr(int n, int* array)
{
	for (int i = 0; i < n; i++)
	{
			std::cout << array[i] << " ";
	}
}

void Sum(int rows, int columns, int** matrix)
{
	if (rows != columns)
	{
		std::cout << "Rows and colums should be the same" << std::endl;
	}
	else
	{
		for (int i = rows - 1; i > 0; i--)
		{
			for (int j = 0; j < columns; j++) {
				int Sum = matrix[i][j];

			}
		}
		std::cout << "Sum of minor diagonal is - " << Sum << std::endl;

	}
}
int add(int x, int y)
{
	return x + y;
}

int substract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

int operation(int(*oper)(int, int), int x, int y)
{
	return oper(x, y);
}

void BubleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = 0;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//task 3
	int r, c;

	std::cout << "Enter the rows number " << std::endl;
	std::cin >> r;

	std::cout << "Enter columns number" << std::endl;
	std::cin >> c;


	int** matrix = new int* [r];
	for (int i = 0; i < r; ++i)
	{
		matrix[i] = new int[c];
	}

	Fullfill(r, c, matrix);
	print(r, c, matrix);
	Sum(r, c, matrix);

	for (int i = 0; i < c; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;

	//task 4 
	int n;
	std::cout << "Enter the number of elements of an array " << std::endl;
	std::cin >> n;
	int* arr = new int[n];

	for (int j = 0; j < n; j++)
	{
		arr[j] = 1 + rand() % 70;
	}

	BubleSort(arr, n);

	int k;
	std::cout << "Enter the number of elements in sub-array " << std::endl;
	std::cin >> k;
	int* SUBarr = new int[k];

	for (int i = n - k; i < n; i++) 
	{
		for (int j = 0; j < k; j++) 
		{
			SUBarr[j] = arr[i];
		}
	}
	printarr(n, SUBarr);
	
	delete[] arr;
	arr = 0;

	delete[] SUBarr;
	SUBarr = 0;

	//task 5
		int x = 0;
		int y = 0;

		std::cin >> x;
		std::cin >> y;

		char znak = '0';
		std::cin >> znak;

		if (znak == '+')
		{
			std::cout << operation(add, x, y) << std::endl;
		}
		else if (znak == '-')
		{
			std::cout << operation(substract, x, y) << std::endl;
		}
		else if (znak == '*')
		{
			std::cout << operation(multiply, x, y) << std::endl;
		}
		else if (znak == '/')
		{
			std::cout << operation(divide, x, y) << std::endl;
		}
		else
		{
			std::cout << "wrong operation" << std::endl;
		}

	return 0;
}