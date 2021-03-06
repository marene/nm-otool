/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_symbol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:15:36 by marene            #+#    #+#             */
/*   Updated: 2016/09/20 15:36:32 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_file.h"

t_symbol		*t_symbol_construct_32(struct nlist symtable, void *strtable)
{
	t_symbol		*ret;
	char			*sym_name;

	ret = NULL;
	if ((ret = malloc(sizeof(t_symbol))) != NULL)
	{
		sym_name = strtable + symtable.n_un.n_strx;
		ret->name = (ft_strlen(sym_name) > 0) ?
						ft_strdup(sym_name) :
						NULL;
		ret->stab = (symtable.n_type & N_STAB);
		ret->pext = (symtable.n_type & N_PEXT);
		ret->ext = (symtable.n_type & N_EXT);
		ret->type = (symtable.n_type & N_TYPE);
		ret->sectnb = symtable.n_sect - 1;
		ret->n_value = symtable.n_value;
		ret->byte = NM_SYM32;
	}
	else
		ft_putendl("Adding symbol failed");
	return (ret);
}

t_symbol		*t_symbol_construct_64(struct nlist_64 symtable, void *strtable)
{
	t_symbol		*ret;
	char			*sym_name;

	ret = NULL;
	if ((ret = malloc(sizeof(t_symbol))) != NULL)
	{
		sym_name = strtable + symtable.n_un.n_strx;
		ret->name = (ft_strlen(sym_name) > 0) ?
						ft_strdup(sym_name) :
						NULL;
		ret->stab = (symtable.n_type & N_STAB);
		ret->pext = (symtable.n_type & N_PEXT);
		ret->ext = (symtable.n_type & N_EXT);
		ret->type = (symtable.n_type & N_TYPE);
		ret->sectnb = symtable.n_sect - 1;
		ret->n_value = symtable.n_value;
		ret->byte = NM_SYM64;
	}
	else
		ft_putendl("Adding symbol failed");
	return (ret);
}

void			t_symbol_destruct(t_symbol ***symbols)
{
	int			i;

	i = 0;
	while ((*symbols)[i])
	{
		free(((*symbols)[i])->name);
		free((*symbols)[i]);
		++i;
	}
	free(*symbols);
	*symbols = NULL;
}
