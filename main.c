#include "libft.h"
#include "ft_printf.h"
#include "get_next_var.h"
#include <unistd.h>
#include <stdio.h>

char	*get_name(char *line)
{

	int	start = 0, end = 0;
	while (line[start] != '\0' && line[start] != ':')
		start++;
	start += 1;
	end = start++;
	while (line[end] != '\0' && line[end] != '|')
		end++;
	return (ft_substr(line, start, ((end - start) -1)));
}

char	*get_time(char *line)
{
	char *tmp = ft_strstr(line, "Total");
	tmp = ft_strchr(tmp, ':');
	return (ft_substr(tmp + 1, 0, ((ft_strstr(tmp, "|") - tmp) - 1)));
}

void	open_files(char *name, char *time, char *line, int fd2)
{
	static int i = 0;
	char *tmp = NULL;
	char *str = NULL;
	int fd = open(str = ft_strjoin("data/", name), O_CREAT | O_TRUNC | O_RDWR, 0677);
	if (i == 0)
		ft_putstr_fd(line, fd);
	else
		ft_putstr_fd(line + 3, fd);
	ft_putstr_fd(tmp = ft_joinstrjoin(name, ":", time), fd2);
	free(tmp);
	free(name);
	free(str);
	free(time);
	close(fd);
	i++;
}

int	not_sorted(char **arr)
{
	int i = 0;
	while (arr[i + 1] != NULL)
	{
		if (ft_atoi(ft_strchr(arr[i], ':') + 1) < ft_atoi(ft_strchr(arr[i + 1], ':') + 1))
			return (1); 
		i++;
	}
	return (0); 
}
void	sort(void)
{
	char	**arr = malloc(sizeof(char *) * 2);
	arr[0] = NULL;
	int fd = open("sorter", O_RDONLY);
	char *line = NULL;
	while ((line = get_next_var(fd, '\n')) != NULL)
	{
		arr = ft_addarr(line, arr);
		free(line);
	}
	close(fd);
	int i = 0;
	while (not_sorted(arr))
	{
		if (arr[i + 1] != NULL && (ft_atoi(ft_strchr(arr[i], ':') + 1) < ft_atoi(ft_strchr(arr[i + 1], ':') + 1)))
		{
			char *tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		i++;
		if (arr[i + 1] == NULL)
			i = 0;
	}
	fd = open("sorted", O_CREAT | O_TRUNC | O_RDWR, 0644);
	for (int i = 0; arr[i]; i++)
	{
		dprintf(fd, "%d- %s\n", i + 1, arr[i]);
	}
	close(fd);
	ft_farray(arr);
}
int	main()
{
	int fd2 = open("sorter", O_CREAT | O_TRUNC | O_RDWR, 0644);
	int	fd = open("login_time", O_RDONLY);
	char	*line;
	while ((line = get_next_var(fd, ';')))
	{
		if (!ft_strchr(line, ';'))
		{
			free(line);
			break;
		}
		open_files(get_name(line), get_time(line), line, fd2);
		free(line);
	}
	close(fd);
	close (fd2);
	sort();
	return (0);
}
