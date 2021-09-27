#include <vector>
using vector = std::vector<int>;
using iterator = vector::const_iterator;

struct set
{
public:
    friend bool binary_search(iterator, iterator, int);
    friend std::istream &operator>>(std::istream &is, set &);
    friend std::ostream &operator<<(std::ostream &os, const set &);
    set union_(const set &) const;
    set inter_(const set &) const;
    set dif_(const set &) const;
    std::size_t size() const;
    set interf() const;

private:
    vector values;
};
