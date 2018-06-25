
RM ?= rm -f

CXX = clang++

# SRC = main.cpp
# SRCS = $(addprefix src/, $(SRC))
SRCS = $(wildcard src/*.cpp)
SRC = $(notdir $(SRCS))

OBJS = $(addprefix obj/, $(SRC:.cpp=.o))

CPPFLAGS = -Wall -Wextra -Werror -g -I include


NAME = computorv2
.PHONY: all clean fclean run debug re 


default:all



all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

obj/%.o: src/%.cpp
	$(CXX)  -o $@  -c $< $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

run:
	./$(NAME) $(ARGS)

debug:all run

