# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 12:05:45 by alejandj          #+#    #+#              #
#    Updated: 2026/10/17 23:12:32 by alejandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Animal.cpp			\
		Dog.cpp				\
		Cat.cpp				\
		WrongAnimal.cpp		\
		WrongCat.cpp		\
		main.cpp

OBJECTS = $(SRC:.cpp=.o)

HEADERS =	Animal.hpp			\
			Dog.hpp				\
			Cat.hpp				\
			WrongAnimal.hpp		\
			WrongCat.hpp

all: $(NAME)

# ---------------------------------------------------------------------------- #
# 💥 RULES
# ---------------------------------------------------------------------------- #

# Create final executable
$(NAME): $(OBJECTS)
	@echo ""
	@echo "\033[0;31m⚙️  COMPILANDO... 🚀\033[0m"
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo ""
	@echo "✅ \033[0;32mCPP COMPILADO!!!\033[0m"
	@echo ""

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---------------------------------------------------------------------------- #
# 🧹 CLEANING
# ---------------------------------------------------------------------------- #
clean:
	rm -rf $(OBJECTS)
	@echo "🧹 \033[0;32mObject files removed successfully! 🗑️\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "🚀 \033[0;32mExecutable $(NAME) has been removed! 👋\033[0m"

re: fclean all

.PHONY: all clean fclean re
