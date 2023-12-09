#include <iostream>
#include <fstream>
#include <string_view>
#include <cctype>

int getValue(std::string_view line)
{
    int len = line.length();
    int num = 0;

    for (int i = 0; i < len; i++)
    {
        if (isdigit(line[i]))
        {
            num += 10 * (line[i] - '0');
            break;
        }
    }

    for (int i = len - 1; i > -1; i--)
    {
        if (isdigit(line[i]))
        {
            num += line[i] - '0';
            break;
        }
    }
    return num;
}

int main(int argc, char const *argv[])
{
    std::ifstream file(static_cast<std::string>(argv[1]));
    int sum = 0;

    while (file)
    {
        std::string line{};
        std::getline(file, line);

        if (line.empty())
            continue;

        // std::cout << line << '\n';

        int value = getValue(line);
        sum += value;
        // std::cout << "value: " << value << '\n';
    }

    std::cout << "sum: " << sum;
    return 0;
}
