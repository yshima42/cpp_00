#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main(void)
{
    const char* str = "3050abc";
    char* s = NULL;

    errno = 0;
    long l = strtol( str, &s, 10 );
    if( (l == LONG_MIN || l == LONG_MAX) && errno == ERANGE ){
        fputs( "結果が表現できない\n", stderr );
        exit( EXIT_FAILURE );
    }
    else if( str == s ){
        fputs( "変換できなかった\n", stderr );
        exit( EXIT_FAILURE );
    }

    printf( "%ld\n", l );
    if( s != NULL ){
        puts( s );
    }
}
