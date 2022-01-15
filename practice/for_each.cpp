#include <algorithm>
#include <iostream>
#include <vector>

class Printer {
    public:
        Printer() : mCount(0) {}

        void operator()(int elem)
        {
            std::cout << elem << std::endl;
            ++mCount;
        }

        int GetCount() const
        {
            return mCount;
        }

    private:
        int mCount;
        
};


int main()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    const int count = std::for_each(v.begin(), v.end(), Printer()).GetCount();
    std::cout << "count: " << count << std::endl;
}
