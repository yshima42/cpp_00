NAME	:= megaphone
SRCS	:= megaphone.cpp
OBJS	:= $(SRCS:.cpp=.o)
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror -I.

all     : 	$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

test	:	$(NAME)
			./megaphone "shhhhh... I think the students are asleep..."
			./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
			./megaphone

.PHONY	:	all clean fclean re test