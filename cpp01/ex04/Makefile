NAME		= replace

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp
OBJ			= main.o

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m
CLEAR		= \033[K\r

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "Executable $(GREEN)$(NAME)$(RESET) built successfully!"

%.o:%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling:$(RESET) $<"
	
clean:
	@rm -f $(OBJ)
	@echo "$(RED)[CLEAN]$(RESET) Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[FCLEAN]$(RESET) Executable removed."

re: clean fclean all

.PHONY: all clean fclean re
