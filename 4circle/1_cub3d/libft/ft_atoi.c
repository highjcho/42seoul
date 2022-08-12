/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:11:36 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/01/18 15:18:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_e(long check_n)
{
	if (check_n == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char	*str)
{
	long	i;
	long	check_n;
	long	result;
	long	tmp;

	i = 0;
	check_n = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		check_n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = result;
		result = (result * 10) + (str[i] - '0');
		if (result / 10 != tmp)
			return (check_e(check_n));
		i++;
	}
	return (check_n * result);
}
