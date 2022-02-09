#include "Data.hpp"

Data::Data(const std::string &str_data, const int &int_data)
    : _str_data(str_data), _int_data(int_data) {}

Data::~Data() {}

const std::string &Data::getStr() const { return _str_data; }

const int &Data::getInt() const { return _int_data; }

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

std::ostream &operator<<(std::ostream &ost, const Data &rhs)
{
    ost << "ID: " << rhs.getStr() << "\n";
    ost << "Score: " << rhs.getInt() << "\n";
    return ost;
}
