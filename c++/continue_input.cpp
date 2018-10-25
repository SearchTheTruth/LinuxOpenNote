/*连续输入一串数字，打印并统计相同数字*/
#include <iostream>

int main()
{
	int current_value = 0, value = 0;
	int counter = 0;
	if(std::cin >> current_value)
	{	
		counter++;
		while(std::cin >> value)
		{
			if(current_value == value)
			{
				counter++;
				continue;
			}
			else
			{
				std::cout << current_value << " repeat " << counter << " times " << std::endl;
				current_value = value;
				counter = 1;
			}
		}
		std::cout << current_value << " repeat " << counter << " times " << std::endl;
	}
	return 0;
}
