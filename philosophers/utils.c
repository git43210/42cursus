/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:36:52 by daypark           #+#    #+#             */
/*   Updated: 2021/10/17 17:06:16 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	if (!(ft_strcmp(str, "-2147483648")))
		return (-2147483648);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || \
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (sign * result);
		else
			result = result * 10 + str[i++] - '0';
	}
	return (result * sign);
}

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL); //실패시(if (gettimeofday() != 0))
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	left(t_phil *phil, int type)
{
	if (type == FORK)
		return (phil->number - 1);
	else
		return ((phil->number) % phil->data->phil_num);
}

int	right(t_phil *phil, int type)
{
	type = 0;
	return ((phil->number + phil->data->phil_num) % phil->data->phil_num);
}

void	msleep(int ms)
{
	long long	endtime;

	endtime = ms + timestamp();
	while (timestamp() < endtime)
		usleep(100);
}
