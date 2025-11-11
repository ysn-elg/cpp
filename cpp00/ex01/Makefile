NAME        = PhoneBook

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -g

SRC_DIR     = src
INC_DIR     = includes
OBJ_DIR     = obj

SRC_FILES   = main.cpp Contact.cpp PhoneBook.cpp
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[OK]$(RESET) $(NAME) built successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@
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

