/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:38:36 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 20:38:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JAL_PRINT_H
# define JAL_PRINT_H

/*
** ==========================================================
**                         FT_Printf
** ==========================================================
*/

int		ft_printf(const char *str, ...);

void	ft_putchar_count(int c, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putptr_count(void *ptr, int *count);
void	ft_putnbr_count(int nbr, int *count);
void	ft_putnbr_unsigned_count(unsigned int nbr, int *count);
void	ft_put_hex_count(unsigned long ptr, const char *hex_digits, int *count);

#endif //JAL_PRINT_H
