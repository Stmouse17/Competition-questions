#include <iostream>

int main()
{
    char character;
    int height;
    while (std::cin >> character && character != '@')
    {
        std::cin >> height;
        for (int i = 0; i < height; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < height -1; j++)
                    std::cout << " ";
                std::cout << character << std::endl;
            }
            else if (i == height - 1)
            {
                for (int j = 0; j < 2 * height - 1; j++)
                    std::cout << character;
                std::cout << std::endl;
            }
            else
            {
                for (int j = 0; j < height - i - 1; j++)
                    std::cout << ' ';
                std::cout << character;
                for (int k = 0; k < 2 * i - 1; k++)
                    std::cout << ' ';
                std::cout << character << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}