/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:52:28 by akharrou          #+#    #+#             */
/*   Updated: 2019/04/25 08:17:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    NAME
**         f_handler -- formatted floating point number conversion
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char	*
**         f_handler(t_format format);
**
**    PARAMETERS
**
**         t_format format         Structure containing the variable
**                                 and information about how it must
**                                 be formatted.
**
**    DESCRIPTION
**         Handles the '%f' specifier like the libc 'printf()' function.
**
**         Note: the only flags and fields that apply to this specifier
**         are the following:
**
**             Flags: '-', '+', ' ', '0'
**             Width: defined or '*'
**             Precision: defined or '*'
**             Length: 'L'
**
**
**    RETURN VALUES
**         If successful, returns a formatted string that follows the
**         specified format; otherwise exits with a -1 on error.
*/

#include "../ft_printf.h"

char			*f_handler(t_format format)
{
	char		*fltstr;

	fltstr = ft_ftoa_base(
		(long double)format.data.double_, DECIMAL_BASE, -1, format.precision);
	if (format.flags & PLUS && !ft_strchr(fltstr, '-'))
		fltstr = ft_strprepend(fltstr, "+", 1, 0);
	if (format.flags & SPACE && !ft_strchr(fltstr, '-'))
		fltstr = ft_strprepend(fltstr, " ", 1, 0);
	return (fltstr);
}



	/** TODO
	 *
	 * KEEP TESTING HUGO + NEW + FILECHECKER
	 * FIX %c with 0 (i.e '\0')
	 * FIX %f
	 *
	 * check with christian
	 */



	// format.width -= ft_strlen(fstr);
	// if (format.width > 0)
	// 	fstr = apply_width(format, fstr);


	// intmax_t	temp;
	// int8_t		sign;
	// char		*intstr;

	// temp = (format.length < L) ? format.data.int_ : format.data.intmax_;
	// sign = (temp < 0);
	// intstr = ft_strdup("");
	// if (!(format.precision == 0 && temp == 0))
	// {
	// 	temp = (temp < 0) ? -temp : temp;
	// 	intstr = ft_strappend(
	// 		intstr, ft_utoa_base(temp, DECIMAL_BASE, format.precision), 1, 1);
	// 	format.width -= ft_strlen(intstr) +
	// 		(sign || (format.flags & PLUS || format.flags & SPACE) ? 1 : 0);
	// }
	// if (format.width && format.pad == '0')
	// 	intstr = apply_width(format, intstr);
	// intstr = (sign) ? ft_strprepend(intstr, "-", 1, 0) : intstr;
	// if (format.flags & PLUS && !sign)
	// 	intstr = ft_strprepend(intstr, "+", 1, 0);
	// if (format.flags & SPACE && !(format.flags & PLUS) && !sign)
	// 	intstr = ft_strprepend(intstr, " ", 1, 0);
	// if (format.width && format.pad != '0')
	// 	intstr = apply_width(format, intstr);
