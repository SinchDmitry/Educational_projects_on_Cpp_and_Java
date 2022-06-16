NAME			= 	MutantStack
SRCS			=	main.cpp 

OBJS			= $(SRCS:.cpp=.o)
DEP				= $(SRCS:.cpp=.d)

CXX				= c++

RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I. -MD -std=c++98


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(DEP)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

-include		$(DEP)

.PHONY:			all clean fclean re
