NAME	:= diamondtrap 
SRCS	:= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp

INCS    := -I./
OBJS	:= $(SRCS:.cpp=.o)
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow ${INCS}

all     : 	$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
