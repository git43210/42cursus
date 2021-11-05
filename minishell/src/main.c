#include "../include/minishell.h"

void	free_env(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->env_len)
		free(env->envp[i]);
	free(env->envp);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_env	env;

	(void)argc;
	(void)argv;
	if (!(copy_envp(&env, envp)))
		return (0);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while (1)
	{
		line = get_readline(&env);
	}
	return (0);
}
