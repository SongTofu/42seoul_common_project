CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	ex03
FILES	=	main.cpp Bureaucrat.cpp Form.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp Intern.cpp

OBJ		=	$(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(wildcard *.gch)

fclean: clean
	$(RM) $(NAME)

re: fclean all