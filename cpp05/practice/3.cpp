#include <iostream>

int main()
{
    while(true)
    {
        try {
        int type;
        std::cin >> type;

        if(type == 0)
            return 0;
        else if (type == 1)
            throw 1;
        else
         throw "errrrroorrrr!";
        } catch (int fError) {
            std::cout << fError << std::endl;
        }
        catch (const char *pszError)
        {
            std::cout << pszError << std::endl;
        }
    }
}
