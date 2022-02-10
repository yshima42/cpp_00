NAME	:= convert
SRCS	:= Convert.cpp main.cpp
TESTS 	:= Convert.cpp test_main.cpp

INCS    := -I./
OBJS	:= $(SRCS:.cpp=.o)
TOBJS	:= $(TESTS:.cpp=.o)
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic ${INCS}

all     : 	$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

test 	: 	$(TESTS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(TESTS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
