#ifndef INCLUDE_GUARD_KAREN_HPP
#define INCLUDE_GUARD_KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
    private:
        void undefined( void );
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void (Karen::*complains[5])( void );

    public:
        Karen();
        ~Karen();
        void complain( std::string level );

};

#endif

