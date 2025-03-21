/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:51:22 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <readline/readline.h>
#include <stdlib.h>

int	ft_exit(int exit_code)
{
	ft_print_error(exit_code);
	rl_clear_history();
	exit(exit_code);
}
