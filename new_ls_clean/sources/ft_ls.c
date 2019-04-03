
#include "ft_ls.h"


void		ft_ls(char **path, char *option)
{
	t_list_ls	*list;

	ft_sort_tab(option, path);
	list = ft_create_list(path);
	ft_display(path, option);
	if (ft_strchr(option, 'R') != NULL && list != NULL)//NE MARCHE PAS....
	{
		ft_recursive_ls(list, option);
	}
////////////////////////////////////////////////////////////////////////////////
	// Pour l affichage : 
	// Si on trouve un fichier dans path on l affiche
	// SI on trouve un repertoire on afficher le nom du repertoire et son contenu
	// list ne contient que des repertoires.
	// path contient tout (fichiers + repertoires)
// !!!!!!!!!!! TOUJOURS FFICHER LES FICHIERS AVANT LES REPERTOIRES !!!!!!!!!!!!! 

// la fonction d affichage doit prendre un char ** et afficher en fonction du contenu
	//SI il y a plusieurs repertoires : 
	//1 - les fichiers (ASCII)
	//2 - !!!! NOM DU REPERTOIRES:\n puis contenu pour tout les repertoires (ASCII)
	//
	//SINON 1 seul element dans le char **path
	//afficher le contenu si c est un repertoires ou le nom si c est un fichier
	// !!!! NE PAS AFFICHER LE NOM SI C EST UN REPERTOIRES
////////////////////////////////////////////////////////////////////////////////
	// if (ft_strchr(option, "R") != NULL)
	//POUR LA RECURSIVE : 
	//IL faut utiliser la list qui ne contient que des noms de repertoires
	//la transformer en tableau
	//relancer ft_ls avec le nouveau tableau et option

////////////////////////////////////////////////////////////////////////////////
}


int		main(int ac, char **av)
{
	char		*option;
	char		**path;

	option = ft_pars_option(ac, av);
	ft_verif_option(option);
	path = ft_pars_folders(ac, av);
	path = ft_verif_folders(path);
	ft_ls(path, option);
	return 1;
}