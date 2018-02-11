#include "../includes/ft_lib.h"

static char	ft_dir_or_link(struct stat info)
{
	if (S_ISDIR(info.st_mode))
		return ('d');
	else if (S_ISCHR(info.st_mode))
		return ('c');
	else if (S_ISSOCK(info.st_mode))
		return ('s');
	else if (S_ISFIFO(info.st_mode))
		return ('p');
	else if (S_ISBLK(info.st_mode))
		return ('b');
	else if (S_ISLNK(info.st_mode))
		return ('l');
	return ('-');
}

static void	ft_chmod_sticky(struct stat info, char *tmp)
{
	if (info.st_mode & S_ISUID && tmp[3] != 'x')
		tmp[3] = 'S';
	else if (info.st_mode & S_ISUID && tmp[3] == 'x')
		tmp[3] = 's';
	if (info.st_mode & S_ISGID && tmp[6] != 'x')
		tmp[6] = 'S';
	else if (info.st_mode & S_ISGID && tmp[6] == 'x')
		tmp[6] = 's';
	if (info.st_mode & S_ISVTX && tmp[9] != 'x')
		tmp[9] = 'T';
	else if (info.st_mode & S_ISVTX && tmp[9] == 'x')
		tmp[9] = 't';
}

char		*ft_chmod(struct stat info)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strnew(10);
	tmp[0] = ft_dir_or_link(info);
	str = "-rwxrwxrwx";
	i = 1;
	j = (1 << 8);
	while (i < 10)
	{
		tmp[i] = (info.st_mode & j) ? str[i] : '-';
		i++;
		j >>= 1;
	}
	ft_chmod_sticky(info, tmp);
	return (tmp);
}

int			ft_check_rights(char *str)
{
	if (str[0] != 'd')
		return (0);
	if (str[2] == 'w' && str[5] == 'w' && str[8] == 'w')
		return (1);
	return (0);
}
