NAME		=	MutantStack

CC			=	c++
FLAG		=	-Wall -Wextra -Werror -std=c++98

LISTCPP		=	main.cpp \

LISTTPP		=	MutantStack.tpp \

LISTINCS	=	MutantStack.hpp \

				
SRC_DIR		=	./core/
SRC			=	$(addprefix $(SRC_DIR),$(LISTCPP))
OBJ			=	$(SRC:.cpp=.o)

DEP         =	$(OBJ:.o=.d)

TPP_DIR		=	./tpp/
TPP			=	$(addprefix $(TPP_DIR),$(LISTTPP))

INCS_DIR	=	./includes/
INCS		=	$(addprefix $(INCS_DIR),$(LISTINCS))

%.o : %.cpp
	$(CC) $(FLAG) -Iincludes -MMD -MP -Itpp -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCS) $(TPP)
	$(CC) $(OBJ) -o $(NAME) 
clean:
	rm -f $(OBJ) $(DEP)
	
fclean: clean
	rm -f $(NAME)
 
re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEP)
