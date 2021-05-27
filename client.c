#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *(str++) - '0';
	return (result);
}

void	send_bit(int pid, char bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(1);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < sizeof(char) * 8)
	{
		send_bit(pid, c & 1);
		c >>= 1;
		i++;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	send_char(pid, '\n');
}

int	main(int ac, char **av)
{
	int		spid;
	char	*msg;

	if (ac != 3)
		return (0);
	spid = ft_atoi(av[1]);
	msg = av[2];
	send_msg(spid, msg);
}
