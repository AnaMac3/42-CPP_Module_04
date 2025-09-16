#!/bin/bash

# Usage: ./newclass.sh NombreClase

NAME=$1
HPP="$NAME.hpp"
CPP="$NAME.cpp"
GUARD=$(echo $NAME | tr '[:lower]' '[:upper]')_HPP

# header
cat > $HPP << EOF
#ifndef $GUARD
# define $GUARD

# include <iostream>

class $NAME
{
	public:
		$NAME();
		~$NAME();
		$NAME(const $NAME& other);
		$NAME& operator=(const $NAME& other);
};

#endif
EOF

# cpp
cat > $CPP << EOF
#include "$NAME.hpp"

$NAME::$NAME()
{
	std::cout << "$NAME Default Constructor called" << std::endl;
}

$NAME::~$NAME()
{
	std::cout << "$NAME Destructor called" << std::endl;
}

$NAME::$NAME(const $NAME& other)
{
	std::cout << "$NAME Copy Constructor called" << std::endl;
	*this = other;
}

$NAME&	$NAME::operator=(const $NAME& other)
{
	std::cout << "$NAME Assignment Operator called" << std::endl;
	if (this != &other)
	{
		//copy atributes
	}
	return (*this);
}
EOF