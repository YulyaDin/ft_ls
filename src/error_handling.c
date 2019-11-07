/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:01:53 by abartole          #+#    #+#             */
/*   Updated: 2019/11/07 20:01:33 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_usage(char *src, char *str, int error)
{
	char	*s;

	s = "usage: ft_ls [-1AaCcfglmnoRrSTtuU@H] [file ...]";
	if (error == 1)
	{
		ft_putstr_fd(src, 2);
		ft_putstr_fd(": illegal option -- ", 2);
		ft_putchar_fd(*str, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd(s, 2);
		exit(1);
	}
	return (0);
}

void	print_errormsg(char *name)
{
	char	*errorbuff;

	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	if ((errorbuff = strerror(errno)))
		ft_putstr_fd(errorbuff, 2);
	write(2, "\n", 1);
}

void	error(int error_status, char *name)
{
	if (error_status == MALLOC_FAILURE)
	{
		perror("ft_ls: malloc: ");
		exit(EXIT_FAILURE);
	}
	else if (error_status == LSTAT_FAILURE)
		print_errormsg(name);
	else if (error_status == READDIR_FAILURE)
		print_errormsg(name);
	else if (error_status == OPENDIR_FAILURE)
		print_errormsg(name);
	else if (error_status == CLOSEDIR_FAILURE)
		print_errormsg(name);
	else if (error_status == GETPWUID_FAILURE)
		perror("ft_ls: getpwuid");
	else if (error_status == GETGRGID_FAILURE)
		perror("ft_ls: getgrgid");
	else if (error_status == LISTXATTR_FAILURE)
		perror("ft_ls: listxattr");
	else if (error_status == GETXATTR_FAILURE)
		perror("ft_ls: getxattr");
	else if (error_status == READLINK_FAILURE)
		perror("ft_ls: readlink");
}
