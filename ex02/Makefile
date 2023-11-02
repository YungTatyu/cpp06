NAME = a.out
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
ifdef	DEBUG
	CXXFLAGS += -fsanitize=address
endif

SRCS_DIR = src
SRC =	main.cpp	\
		identify.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

INCLUDES_DIR = include
INCLUDES = -I$(INCLUDES_DIR)
OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o,$(SRCS))
DEPS = $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.d,$(SRCS))
TEST_DIR = test
TEST_BUILD_DIR = $(TEST_DIR)/build
RM = rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(INCLUDES) $(CXXFLAGS)  -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

re:	fclean	all

fclean:	clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(TEST_BUILD_DIR)

debug:
	@make re DEBUG=1

test:
	make TEST=1
	cmake -S . -B $(TEST_BUILD_DIR)
	cmake --build $(TEST_BUILD_DIR)
	bash -c 'cd $(TEST_BUILD_DIR) && ctest'

-include $(DEPS)

.PHONY: all re fclean clean debug leaks test