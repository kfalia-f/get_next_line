#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int 	i;

	i = 0;
	fd = open("test", 'r');
	while (i < 55)
	{
		printf("%d\n%s\n\n", get_next_line(fd, &line), line);
	i++;
	}
	}
