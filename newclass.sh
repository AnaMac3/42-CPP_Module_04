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

/**
 * @class	$NAME
 * @brief	
 *
 */

class $NAME
{
	public:
		$NAME();
		$NAME(const $NAME& other);
		$NAME& operator=(const $NAME& other);
		~$NAME();
};

#endif
EOF

# cpp
cat > $CPP << EOF
#include "$NAME.hpp"

/**
 * @brief	Default constructor	
 *
 */

$NAME::$NAME()
{
	std::cout << "$NAME Default Constructor called" << std::endl;
}

/**
 * @brief	Copy constructor	
 *
 */

$NAME::$NAME(const $NAME& other)
{
	std::cout << "$NAME Copy Constructor called" << std::endl;
	*this = other;
}

/**
 * @brief	Assignment operator	
 *
 */

$NAME&	$NAME::operator=(const $NAME& other)
{
	std::cout << "$NAME Assignment Operator called" << std::endl;
	if (this != &other)
	{
		//copy atributes
	}
	return (*this);
}

/**
 * @brief	Default destructor	
 *
 */

$NAME::~$NAME()
{
	std::cout << "$NAME Destructor called" << std::endl;
}

EOF