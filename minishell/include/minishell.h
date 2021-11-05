#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_env
{
	char			**envp;
	int				env_len;
	struct termios	new_term;
}					t_env;
/*main.c*/
void			free_env(t_env *env);
/*ft_shlvl*/
int				copy_envp(t_env *env, char **envp);
void			set_shlvl(t_env *env, int index, int i);
int				extend_envp(t_env *env);
/*ft_signal*/
void			signal_setup(int signum);
void			setup_signal_handlers(void);
void			set_termios(t_env *env);
char			*get_readline(t_env *env);
/*builtin.c*/
int				run_command(char *line);
int				run_builtins(char **words);
#endif
