#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <cctype>
#include <map>

// find and return the number in the line by iterating from start to end with step
int findValue(std::string_view line, int start, int end, int step)
{
    std::map<std::string, int> map{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10}};

    for (int i = start; i != end; i += step)
    {
        if (isdigit(line[i]))
        {
            return (line[i] - '0');
        }
        else
        {
            for (const auto &[key, value] : map)
            {
                // if current prefix matches with a key
                if (key == line.substr(i, key.length()))
                {
                    return value;
                }
            }
        }
    }
    return 0;
}

int getValue(std::string_view line)
{
    int len = line.length();
    int num = 0;

    num += 10 * findValue(line, 0, len, 1);
    num += findValue(line, len - 1, -1, -1);

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
