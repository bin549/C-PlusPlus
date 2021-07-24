#include <iostream>
#ifdef _MSC_VER
#include <string> // use this for MS Visucal C++
#else
#include <cstring>
#endif
#include <vector>

namespace string_search
{
    int brute_force(const std::string &text, const std::string &pattern)
    {
        size_t pat_l = pattern.length();
        size_t txt_l = text.length();
        int index = -1;
        if (pat_l <= txt_l)
        {
            for (size_t i = 0; i < txt_l - pat_l + 1; i++)
            {
                std::string s = text.substr(i, pat_l);
                if (s == pattern)
                {
                    index = i;
                    break;
                }
            }
        }
        return index;
    }
}

using string_search::brute_force;

const std::vector<std::vector<std::string>> test_set = {
    // {text, pattern, expected output}
    {"a", "aa", "-1"},
    {"a", "a", "0"},
    {"ba", "b", "0"},
    {"bba", "bb", "0"},
    {"bbca", "c", "2"},
    {"ab", "b", "1"}};

int main()
{
    for (size_t i = 0; i < test_set.size(); i++)
    {
        int output = brute_force(test_set[i][0], test_set[i][1]);

        if (std::to_string(output) == test_set[i][2])
            std::cout << "success\n";
        else
            std::cout << "failure\n";
    }
    return 0;
}
