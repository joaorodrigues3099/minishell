/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:00:01 by joao-alm          #+#    #+#             */
/*   Updated: 2025/03/17 17:00:01 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jal_error.h"
#include "jal_string.h"
#include "token.h"
#include <stdlib.h>

t_token_type	ft_token_type(const char *value)
{
	if (value[0] == '|' && value[1] == '\0')
		return (TOKEN_PIPE);
	if (value[0] == '<' && value[1] == '\0')
		return (TOKEN_REDIRECT_IN);
	if (value[0] == '>' && value[1] == '\0')
		return (TOKEN_REDIRECT_OUT);
	if (ft_strncmp(value, ">>", 2) == 0 && value[2] == '\0')
		return (TOKEN_APPEND);
	if (ft_strncmp(value, "<<", 2) == 0 && value[2] == '\0')
		return (TOKEN_HEREDOC);
	return (TOKEN_WORD);
}

t_token	*ft_new_token(char *value)
{
	t_token	*new;

	if (!value)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		return (ft_error("memory allocation failed", E_NOMEM), NULL);
	new->type = ft_token_type(value);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_token_add_back(t_token **head, t_token *new)
{
	t_token	*current;

	if (!head || !new)
		return ;
	current = *head;
	if (current)
	{
		while (current && current->next)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}

void	ft_token_free(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}

void	ft_token_clear(t_token *head)
{
	t_token	*next;

	while (head)
	{
		next = head->next;
		ft_token_free(head);
		head = next;
	}
}
