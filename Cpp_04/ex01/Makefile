NAME = brain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Animal.cpp			\
		Dog.cpp				\
		Cat.cpp				\
		WrongAnimal.cpp		\
		WrongCat.cpp		\
		Brain.cpp			\
		main.cpp			\

OBJECTS = $(SRC:.cpp=.o)

HEADERS =	Animal.hpp			\
			Dog.hpp				\
			Cat.hpp				\
			WrongAnimal.hpp		\
			WrongCat.hpp		\
			Brain.hpp			\



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