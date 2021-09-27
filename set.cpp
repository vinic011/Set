#include <iostream>
#include <vector>
#include <sstream>
#include "set.hpp"

bool binary_search(iterator begin, iterator end, int key)
{
    if (begin == end)
        return false;

    const auto n = std::distance(begin, end);
    const auto mid = begin + n / 2;

    if (*mid == key)
        return true;

    if (*mid < key)
        return binary_search(mid + 1, end, key);

    return binary_search(begin, mid, key);
}

std::istream &operator>>(std::istream &is, set &a)
{
    std::string line;
    std::getline(is, line);
    auto ss = std::stringstream{line};
    int x;
    while (ss >> x)
    {
        a.values.push_back(x);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const set &a)
{
    for (auto i = a.values.begin(); i != a.values.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    return os;
}

set set::union_(const set &b) const
{
    set uni;
    auto i = values.begin();
    auto j = b.values.begin();

    while ((i != values.end()) && (j != b.values.end()))
    {
        if (*i == *j)
        {
            uni.values.push_back(*i);
            i++;
            j++;
        }
        else if (*i > *j)
        {
            uni.values.push_back(*j);
            j++;
        }
        else if (*j > *i)
        {
            uni.values.push_back(*i);
            i++;
        }
    }
    while ((j != b.values.end()))
    {
        uni.values.push_back(*j);
        j++;
    }
    while ((i != values.end()))
    {
        uni.values.push_back(*i);
        i++;
    }
    return uni;
}

set set::inter_(const set &b) const
{
    set inter;
    auto i = values.begin();
    auto j = b.values.begin();
    while ((i != values.end()) && (j != b.values.end()))
    {
        if (*i == *j)
        {
            inter.values.push_back(*i);
            i++;
            j++;
        }
        else if (*i > *j)
        {
            j++;
        }
        else if (*j > *i)
        {
            i++;
        }
    }
    return inter;
}

set set::dif_(const set &b) const
{
    set dif;
    auto i = values.begin();
    auto j = b.values.begin();
    while ((i != values.end()) && (j != b.values.end()))
    {
        if (*i == *j)
        {
            i++;
            j++;
        }
        else if (*j > *i)
        {
            dif.values.push_back(*i);
            i++;
        }
        else if (*i > *j)
        {
            j++;
        }
    }
    while (i != values.end())
    {
        dif.values.push_back(*i);
        i++;
    }
    return dif;
}

std::size_t set::size() const
{
    return values.size();
    ;
}

set set::interf() const
{
    set i;
    for (int j : {1, 2, 3, 5, 8, 13, 21, 34, 55})
    {
        if (binary_search(values.begin(), values.end(), j) == true)
        {
            i.values.push_back(j);
        }
    }
    return i;
}
