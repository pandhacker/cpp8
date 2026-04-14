NAME		=	Span

CC			=	c++
FLAG		=	-Wall -Wextra -Werror -std=c++98 

LISTCPP		=	main.cpp \
				Span.cpp \

LISTINCS	=	Span.hpp \

				
SRC_DIR		=	./core/
SRC			=	$(addprefix $(SRC_DIR),$(LISTCPP))
OBJ			=	$(SRC:.cpp=.o)
DEP         =	$(OBJ:.o=.d)
INCS_DIR	=	./includes/
INCS		=	$(addprefix $(INCS_DIR),$(LISTINCS))


%.o : %.cpp
	$(CC) $(FLAG) -MMD -MP -Iincludes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCS)
	$(CC) $(OBJ) -o $(NAME) 
clean:
	rm -f $(OBJ) $(DEP)
	
fclean: clean
	rm -f $(NAME)
 
re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEP)
