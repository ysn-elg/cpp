
NAME		= Animal 

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= Animal.cpp  Cat.cpp  Dog.cpp  main.cpp

OBJ_DIR		= objs
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) #-p avoid errors

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
