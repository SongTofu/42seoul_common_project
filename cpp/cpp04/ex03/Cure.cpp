#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const& other)
{
	*this = other;
}

Cure::~Cure()
{
}

Cure	&Cure::operator=(Cure const& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}