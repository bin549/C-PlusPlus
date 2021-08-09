#include <iostream>

unsigned char **new_array2d(unsigned int row, unsigned int column)
{
	unsigned char **array2d = new unsigned char *[row];
	for (unsigned int i = 0; i < row; i++)
	{
		array2d[i] = new unsigned char[column];
	}
	return array2d;
}

void delete_array2d(unsigned char **array2d, unsigned int row)
{
	for (unsigned int i = 0; i < row; i++)
		delete[] array2d[i];
	delete[] array2d;
}

void set_array2d(unsigned char **array2d, unsigned int row, unsigned int column)
{
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
		{
			array2d[i][j] = rand() % 256;
		}
	}
}

void print_array1d(unsigned int array[], unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		std::cout << array[i] << "   ";
	}
}
void print_array2d(unsigned char **array2d, unsigned int row, unsigned int column)
{
	std::cout << std::endl;
	for (unsigned int i = 0; i < row; i++)
	{
		std::cout << std::endl;
		for (unsigned int j = 0; j < column; j++)
		{
			std::cout << array2d[i][j] << "   ";
		}
	}
}

unsigned int *histgram(unsigned char **array2d, unsigned int row, unsigned int column)
{
	unsigned int count[256] = {0};
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			count[array2d[i][j]]++;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 256; i++)
	{
		std::cout << count[i] << " ";
	}
	return count;
}

unsigned char **get_sub_array(unsigned char **array2d, unsigned int row_index, unsigned int column_index, unsigned int height, unsigned int width)
{
}

void gray_to_binary(unsigned char **array2d, unsigned int row, unsigned int column);

/*b)四周元素与中间元素异或运算后，组成下列四种排列
		1 a0，a1，a2，a3，a4，a5，a6，a7
		2 a2，a3，a4，a5，a6，a7，a0，a1
		3 a4，a5，a6，a7，a0，a1，a2，a3
		4 a6，a7，a0，a1，a2，a3，a4，a5
   	   将上面四种排列转换为十进制数，求这个四个十进制数的最小值。*/
unsigned int find_min_value(unsigned char **array2d);

int main()
{
	std::cout << "请输入列数和行数\n";
	int row, column;
	std::cin >> row >> column;
	unsigned char **array2d = new_array2d(row, column);
	set_array2d(array2d, row, column);
	print_array2d(array2d, row, column);
	unsigned int *count;
	histgram(array2d, row, column);
	return 0;
}