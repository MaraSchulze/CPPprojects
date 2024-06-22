/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:46:17 by marschul          #+#    #+#             */
/*   Updated: 2024/03/12 18:47:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <cstring>
# include <limits>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    static bool	convert_char(char *value);
    static bool	convert_int(char *value);
    static bool	convert_float(char *value);
    static bool	convert_double(char *value);

public:
    ~ScalarConverter();
    ScalarConverter&	operator=(const ScalarConverter& other);
    static void			convert(char *value);
};

#endif
