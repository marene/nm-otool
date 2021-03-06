/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:26:22 by marene            #+#    #+#             */
/*   Updated: 2016/09/20 11:44:49 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/fat.h>
# include <ar.h>
# include "t_file.h"
# include "libft.h"

# define NM_OK			0
# define NM_NOK			1

typedef int				(*t_file_handler)(t_file *file);

typedef struct			s_env
{
	t_file			*froot;
	t_file_handler	handler;
}						t_env;

int						handle_32(t_file *file);
int						handle_64(t_file *file);
int						handle_fat(t_file *file);
int						handle_ar(t_file *file);
t_env					*init_env(void);
int						env_next_file(t_env *env);
int						load_file(char *file_name, t_file **froot);
int						get_magic(t_env *env);
void					print_symbols(t_symbol **symbols, t_section **sections);
struct fat_header		reverse_fat_header(struct fat_header *fat_h);
struct fat_arch			reverse_fat_arch(struct fat_arch *f);

int						symsort_ascii(t_symbol *s1, t_symbol *s2);
int						symsort_ascii_addr(t_symbol *s1, t_symbol *s2);

#endif
