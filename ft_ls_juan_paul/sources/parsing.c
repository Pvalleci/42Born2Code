/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvalleci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:28:12 by pvalleci          #+#    #+#             */
/*   Updated: 2019/03/12 16:28:14 by pvalleci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_pars_option(int argc, char **argv)
{
	int 	i;
	char	*option;
	char	*tmp;
	char	*tmp2;

	if (!(option = ft_strnew(0)))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			tmp2 = argv[i];
			tmp2++;
			tmp = option;
			if (!(option = ft_strjoin(option, tmp2)))
				return (NULL);
			free(tmp);
		}
		else
			return (option);
		i++;
	}
	return (option);
}

int			ft_verif_option(char *option)
{
	int		i;

	i = 0;
	while (option[i])
	{
		if (option[i] != 'l' && option[i] != 'R'
			&& option[i] != 'a' && option[i] != 'r'
			&& option[i] != 't')
		{
			printf("ft_ls: illegal option -- %c\n", option[i]);
			printf("usage: ./ft_ls [-lRart] [file ...]\n");
			free(option);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

char		**ft_pars_folders(int argc, char **argv)
{
	int		i;
	int		j;
	char	**folders;

	i = 1;
	j = 0;
	if (argc == 1)
		return (NULL);
	while ((i < argc) && argv[i][0] == '-')
		i++;
	if (i == argc)
		return (NULL);
	if (!(folders = (char **)malloc(sizeof(char *) * ((argc - i) + 1))))
		return (NULL);
	while (i < argc)
	{
		folders[j] = ft_strdup(argv[i]);
		j++;
		i++;
	}
	folders[j] = NULL;
	return (folders);
}

char		**ft_valid_folders(char **folders, int i, int j)
{
	char	**valid_folders;
	DIR		*rep;

	if (!(valid_folders = (char **)malloc(sizeof(char*) * ((i - j) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (folders[i] != NULL)
	{
		if (!(rep = opendir(folders[i])))
			i++;
		else
		{
			valid_folders[j] = ft_strdup(folders[i]);
			j++;
			i++;
			closedir(rep);
		}
	}
	valid_folders[j] = NULL;
	return (valid_folders);
}

char		**ft_verif_folders(char **folders)
{
	int				i;
	int				j;
	char			**valid_folders;
	DIR				*rep;

	i = 0;
	j = 0;
	if (!folders)
		return (NULL);
	while (folders[i] != NULL)
	{
		if (!(rep = opendir(folders[i])))
		{
			///si c est un ifchier il faut afficher : ls: %s: Not a diretory dans le cas ou on aurait envoyer un fichier a la place d un dossier.
			printf("ft_ls: %s: No such file or directory\n", folders[i]);
			j++;
		}
		else
			closedir(rep);
		i++;
	}
	valid_folders = ft_valid_folders(folders, i, j);
	return (valid_folders);
}
