/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:12:14 by acetin            #+#    #+#             */
/*   Updated: 2022/10/29 14:58:11 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include "./libft/libft.h"

char	**g_environ;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*command;
}	t_cmd;

typedef struct s_func
{
	void	*(*func_name)(t_cmd);
}	t_func;

typedef struct s_functions
{
	t_func	func;
	char	*arg;
}	t_functions;

char		*to_lower_str(char *str);
char		**env_1(char **env);
char		*rl_gets(char *str, const char *prompt);
char		*ft_strjoin2(char *s1, char *s2);
char		*sequence(char **temp, char *en, char *ret);
char		**split2(char *str, char c);
char		*clear_char(char *str, char c);
char		*where(char *cmd);
char		*where_env_dolar(char *s2);
char		**redirect_split(char *str);
char		**join_redirect(char **cmd);
char		**redirect_delimiter(char *cmd);

int			ft_execve(t_cmd cmd);
int			check_syntax(char *str);
int			check_right_r(int pos, char *str);
int			check_right(int pos, char *str);
int			determine_syntax(char *str, int i);
int			ft_fork(void);
int			**ft_multiple_fd(int count);
int			ft_strstr(char *s1, char *s2);
int			char_count(char *str, char c);
int			first_quote(char *str);
int			dolar_sign(char *str, int i);
int			quote_state(char *str, int pos);
int			word_count(char *str, char c);
int			ft_strchr2(char *s, int c);
int			ft_double_strlen(char **str);
int			is_alnum(char *str);
int			exit_status(int status, int flag, char *message);
int			where_env(char *s2);
int			check_env_arg(t_cmd cmd);
int			redirect(char *cmd);
int			is_exist_file(char *path);
int			open_file(char *path);
int			red_count(char *str);
int			cut_red(char *dst, char **src);
int			right_redirect(char *file);
int			single_right_redirect(char *file);
int			double_right_redirect(char *file);
int			singel_left_redirect(char *file);
int			double_left_redirect(char *eof);
int			lst_find(t_list **lst, void *data);

void		loop(void);
void		env(t_cmd cmd);
void		exit_f(t_cmd cmd);
void		export(t_cmd cmd);
void		unset(t_cmd cmd);
void		cd(t_cmd cmd);
void		pwd(t_cmd cmd);
void		ft_echo(t_cmd cmd);
void		free_env(char *arg);
void		heredoc(char *cmd);
void		multiple_waitpid(int *pid, int count);
void		ft_multiple_close(int **fd, int len);
void		ft_pipe(char **cmd, int count);
void		ft_free_double(char **pointer);
void		print_all(char *str, int quote);
void		set_funcs(t_functions *func);
void		get_func(t_cmd cmd);
void		parse_string(char *str);
void		where_env_dolar_upgrade(char *s2);
void		ft_free_int(int **pointer, int count);
void		*ft_realloc(void *ptr, size_t size);
void		free_env(char *arg);
void		add_env(char *env, int env_index);
void		with_pipe(char *str);
void		heredoc(char *cmd);
void		clear_file(char *path);
void		run_heredoc(char **files, char **delimeter);
void		add_to_list(char **temp, t_list **cmd);
void		lstclear(t_list **lst);
void		file_process(void);
#endif
