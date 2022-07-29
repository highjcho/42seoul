/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:41:16 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/06/09 15:41:16 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "init.h"
# include "signal.h"
# include "parse.h"
# include "redirect.h"
# include "builtins.h"
# include "execute.h"
# include "utils.h"
# include "../libft/libft.h"

# define SUCCESS 0
# define FAIL 1

# define TRUE 1
# define FALSE 0

# define COMMAND_FAIL 127

# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775808

#endif
