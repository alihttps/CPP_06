NAME = serialize

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

FILES =	*.cpp

all : $(NAME)

$(NAME) : $(FILES)
		$(CPP) $(CPP_FLAGS) $(FILES) -o $(NAME)


clean :
		rm -rf $(NAME)

re : clean all