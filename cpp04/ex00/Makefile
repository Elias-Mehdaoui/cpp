NAME 		= Animal

SRC_FILES	=	$(addprefix srcs/, Cat.cpp Dog.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp) \
				main.cpp \

OBJS_DIR	= .objets

OBJS		= $(SRC_FILES:%.cpp=$(OBJS_DIR)/%.o)

CXX			= c++

CXXFLAGS		= -g3 -std=c++98 -Wall -Wextra -Werror -Iincludes

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@mkdir $(OBJS_DIR)/srcs

$(OBJS) : $(OBJS_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

.PHONY: all clean fclean re