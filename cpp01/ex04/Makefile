NAME	:= replace
SRCS	:= main.cpp Replace.cpp
OBJS	:= $(SRCS:.cpp=.o)
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic 

all     : 	$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
