/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_split_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:47:12 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/02/20 14:47:12 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	default_mode(t_splitter *sp);
static void	end_func(t_splitter *sp);

t_ftlist	redir_split_line(const char *line)
{
	t_ftlist	redirs;
	t_redirs	last_type;

	last_type = REDIR_NONE;
	redirs = parse_context(line, (t_context){	// Não esquecer de tratar as aspas
			.def_func = default_mode,
			.dquotes_func = NULL,
			.squotes_func = NULL,
			.end_func = end_func
		}, &last_type);

	return (redirs);
}

// Last found: // *
//             // wc < file1.txt
// Iter        // #
// mode = DEFAULT

//              ls -l > outfile.txt ls -l | pwd > path.txt
//
// PIPE[0] -> ls -l > outfile.txt ls -l
//		REDIR[0] (CMD) = "ls -l"
//		REDIR[1] (OUT) = "outfile.txt"
//		REDIR[2] (CMD) = "ls -l"
// PIPE[1] -> pwd > path.txt
//		REDIR[0] (CMD) = "pwd"
//		REDIR[1] (OUT) = "path.txt"



// [PENDENTE]: Implementar separação de pedaços da string da linha, em pequenos pedaços

// mode = DEFAULT
// last_type = REDIR_NONE
// last_found:
//             < infile.txt wc -l
// iter:       ^
/* list = {
	(REDIR_IN, "infile.txt"),
	(REDIR_CMD, "ls -l ")
}*/

/*
	Context:
		- first_cmd: (REDIR_CMD, "ls -l ")
		- last_outfile: NULL
		- first_infile: (REDIR_IN, "infile.txt", FD)
*/

static void	default_mode(t_splitter *sp)
{
	t_redir_slice	*slice;
	t_redirs		*last_type;
	char			*tmp;

	last_type = (t_redirs *) sp->aux;
	if (sp->last_found == NULL && *sp->iter != ' ' && *sp->iter != '>' && *sp->iter != '<')
		sp->last_found = sp->iter;
	if (*sp->iter == ' ' && sp->last_found != NULL
		&& (*last_type == REDIR_OUT || *last_type == REDIR_APPEND || *last_type == REDIR_IN))
	{
		slice = malloc(sizeof(t_redir_slice));
		slice->fd = -1;
		slice->type = *last_type;
		tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);	// Criar função para substituir uma string por outra, e limpar a string antiga
		slice->str = ft_strtrim(tmp, " ");
		free(tmp);
		ft_lst_push_back(&(sp->list), slice);
		sp->last_found = NULL;
		*last_type = REDIR_NONE;
	}
	if (*last_type != REDIR_NONE)
	{
		if (*sp->iter == '>')
		{
			if (*last_type == REDIR_OUT)
				*last_type = REDIR_APPEND;
			else
			{
				slice = malloc(sizeof(t_redir_slice));
				slice->fd = -1;
				slice->type = *last_type;
				tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);	// Criar função para substituir uma string por outra, e limpar a string antiga
				slice->str = ft_strtrim(tmp, " ");
				free(tmp);
				ft_lst_push_back(&(sp->list), slice);
				sp->last_found = NULL;
				*last_type = REDIR_OUT;
			}
		}
		else if (*sp->iter == '<')
		{
			slice = malloc(sizeof(t_redir_slice));
			slice->fd = -1;
			slice->type = *last_type;
			tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);	// Criar função para substituir uma string por outra, e limpar a string antiga
			slice->str = ft_strtrim(tmp, " ");
			free(tmp);
			ft_lst_push_back(&(sp->list), slice);
			sp->last_found = NULL;
			*last_type = REDIR_IN;
		}
	}
	else if (*last_type == REDIR_NONE)
	{
		if (*sp->iter == '>')
			*last_type = REDIR_OUT;
		else if (*sp->iter == '<')
			*last_type = REDIR_IN;
		else
			*last_type = REDIR_CMD;
	}
	// else if (*last_type == REDIR_NONE)
	// 	*last_type = REDIR_CMD;
}

static void	end_func(t_splitter *sp)
{
	t_redir_slice	*slice;
	t_redirs		*last_type;
	char			*tmp;

	last_type = (t_redirs *) sp->aux;
	if (sp->last_found != NULL)
	{
		slice = malloc(sizeof(t_redir_slice));
		slice->fd = -1;
		slice->type = *last_type;
		tmp = ft_strndup(sp->last_found, sp->iter - sp->last_found);	// Criar função para substituir uma string por outra, e limpar a string antiga
		slice->str = ft_strtrim(tmp, " ");
		free(tmp);
		ft_lst_push_back(&(sp->list), slice);
	}
}
