#include <iostream>

int main()
{
    int array[5] = {5, 2, 1, 3, 4};
    int array_size = 5;
	int i = 0;
	int buf;
	char swap_cnt = 0;
	if (array_size == 0)
		return (0);
	while (i < array_size)
	{
		if (i + 1 != array_size && array[i] > array[i + 1])
		{
			buf = array[i];
			array[i] = array[i + 1];
			array[i + 1] = buf;
			swap_cnt = 1;
		}
		i++;
		if (i == array_size && swap_cnt == 1)
		{
			swap_cnt = 0;
			i = 0;
		}
	}
    // Magic array print
    for (const auto& e : array) {
        std::cout << e << std::endl;
    }
}