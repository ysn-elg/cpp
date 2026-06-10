NAME        = mutant_stack

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -g

SRCS        = main.cpp
HEADERS     = MutantStack.hpp MutantStack.tpp

OBJ_DIR     = objs
OBJS        = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Executable $(GREEN)$(NAME)$(RESET) built successfully!"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling:$(RESET) $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[CLEAN]$(RESET) Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[FCLEAN]$(RESET) Executable removed."

re: fclean all

.PHONY: all clean fclean re
