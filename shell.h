#ifndef _SHELL_H_
#define _SHELL_H_
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - A n
 * @dir: A 
 * @next: A po
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A n
 * @name: The n
 * @f: A fun
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A n
 * @name: The
 * @value: The va
 * @next: A p
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

alias_t *aliases;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *dir_path_get(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

void line_handle(char **line, ssize_t read);
void rep_var(char **args, int *exe_ret);
char *args_get(char *line, int *exe_ret);
int args_call(char **args, char **front, int *exe_ret);
int args_run(char **args, char **front, int *exe_ret);
int args_handle(int *exe_ret);
int args_check(char **args);
void args_free(char **args, char **front);
char **aliases_replace(char **args);

int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

int (*get_builtin(char *command))(char **args, char **front);
int exit_shellby(char **args, char **front);
int env_shellby(char **args, char __attribute__((__unused__)) **front);
int setenv_shellby(char **args, char __attribute__((__unused__)) **front);
int unsetenv_shellby(char **args, char __attribute__((__unused__)) **front);
int cd_shellby(char **args, char __attribute__((__unused__)) **front);
int alias_shellby(char **args, char __attribute__((__unused__)) **front);
int help_shellby(char **args, char __attribute__((__unused__)) **front);

char **_copyenv(void);
void env_free(void);
char **_getenv(const char *var);

int error_create(char **args, int err);
char *env_error(char **args);
char *error_1(char **args);
char *exit_2_error(char **args);
char *cd_2_error(char **args);
char *syntax_2_error(char **args);
char *error_126(char **args);
char *error_127(char **args);

alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void all_help(void);
void setenv_help(void);
void unsetenv_help(void);
void alias_help(void);
void env_help(void);
void history_help(void);
void cd_help(void);
void exit_help(void);
void help_help(void);

int commands_file_proc(char *file_path, int *exe_ret);
#endif /* _SHELL_H_ */
