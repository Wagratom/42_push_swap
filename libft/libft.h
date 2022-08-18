/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:49:36 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/16 16:58:15 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 4096
# define FD_MAX 1024

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//function converts the initial portion of the string
//pointed to by nptr to int.  The behavior is the same as
int		ft_atoi(const char *nptr);

//function erases the data in the n bytes of the memory
//starting at the location pointed to by s, by writing zeros (bytes
//containing '\0') to that area.
void	ft_bzero(void *b, size_t len);

//The calloc() function allocates memory for an array of nmemb
//elements of size bytes each and returns a pointer to the allocated
//memory. The memory is set to zero. If nmemb or size is 0, then
//calloc() returns either NULL, or a unique pointer value
//that can later be successfully passed to free().
void	*ft_calloc(size_t nitems, size_t size);

//checks for an alphanumeric characte
int		ft_isalnum(int c);

//checks for an alphabetic character
int		ft_isalpha(int value);

//checks whether c is a 7-bit unsigned char value that fits.
//into the ASCII character set.
int		ft_isascii(int c);

//checks for a digit (0 through 9).
int		ft_isdigit(int c);

//checks for any printable character including space.
int		ft_isprint(int c);

//Allocates (with malloc(3)) and returns a string
//representing the integer received as an argument.
//Negative numbers must be handled.
char	*ft_itoa(int n);

//Adds the node ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new);

//lst: The address of a pointer to the first link of
//a list.
//new: The address of a pointer to the node to be
//added to the list.
void	ft_lstadd_front(t_list **lst, t_list *new);

//Deletes and frees the given node and every
//successor of that node, using the function ’del’
//and free(3).
//Finally, the pointer to the list must be set to
//NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*));

//takes as a parameter a node and frees the memory of
//the node’s content using the function ’del’ given
//as a parameter and free the node. The memory of
//’next’ must not be freed
void	ft_lstdelone(t_list *lst, void (*del)(void*));

//Iterates the list ’lst’ and applies the function
//’f’ on the content of each node
void	ft_lstiter(t_list *lst, void (*f)(void *));

//Returns the last node of the list.
t_list	*ft_lstlast(t_list *lst);

//terates the list ’lst’ and applies the function
//’f’ on the content of each node. Creates a new
//list resulting of the successive applications of
//the function ’f’. The ’del’ function is used to
//delete the content of a node if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Allocates (with malloc(3)) and returns a new node.
//The member variable ’content’ is initialized with
//the value of the parameter ’content’. The variable
//’next’ is initialized to NULL.
t_list	*ft_lstnew(void *content);

//Counts the number of nodes in a list.
int		ft_lstsize(t_list *lst);

//The memchr() function scans the initial n bytes of the memory
//area pointed to by s for the first instance of c.  Both c and the
//bytes of the memory area pointed to by s are interpreted as
//unsigned char.
void	*ft_memchr(const void *str, int c, size_t n);

//The memcmp() function compares the first n bytes (each
//interpreted as unsigned char) of the memory areas s1 and s2.
int		ft_memcmp(const void *str1, const void *str2, size_t n);

//The memcpy() function copies n bytes from memory area src to
//memory area dest.  The memory areas must not overlap.  Use
//memmove(3) if the memory areas do overlap.
void	*ft_memcpy(void *dst, const void *src, size_t len);

// The memmove() function copies n bytes from memory area src to
//memory area dest.  The memory areas may overlap: copying takes
//place as though the bytes in src are first copied into a
//temporary array that does not overlap src or dest, and the bytes
//are then copied from the temporary array to dest.
void	*ft_memmove(void *dest, const void *src, size_t n);

//The memset() function fills the first n bytes of the memory area
//pointed to by s with the constant byte c.
void	*ft_memset(void *str, int c, size_t n);

//Outputs the character ’c’ to the given file
//descriptor
void	ft_putchar_fd(char c, int fd);

//Outputs the string ’s’ to the given file descriptor
//followed by a newline.
void	ft_putendl_fd(char *s, int fd);

//Outputs the integer ’n’ to the given file
//descriptor.
void	ft_putnbr_fd(int n, int fd);

//Outputs the string ’s’ to the given file
//descriptor
void	ft_putstr_fd(char *s, int fd);

//Allocates (with malloc(3)) and returns an array
//of strings obtained by splitting ’s’ using the
//character ’c’ as a delimiter. The array must end
//with a NULL pointer.
char	**ft_split(char const *s, char c);

//The strchr() function returns a pointer to the first occurrence
//of the character c in the string s.
char	*ft_strchr(const char *str, int c);

//The strdup() function returns a pointer to a new string which is
//a duplicate of the string s.  Memory for the new string is
//obtained with malloc(3), and can be freed with free(3).
char	*ft_strdup(const char *s);

//Applies the function ’f’ on each character of
//the string passed as argument, passing its index
//as first argument. Each character is passed by
//address to ’f’ to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//Allocates (with malloc(3)) and returns a new
//string, which is the result of the concatenation
//of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2);

//A strlcat () anexa a string src ao final de dst.
//Ele anexará no máximo tamanho - strlen(dst) - 1
//bytes,terminando com NUL o resultado.
size_t	ft_strlcat(char *dst, const char *src, size_t size);

//A strlcpy () copia até tamanho - 1 caracteres da string terminada
//em NUL src para dst , terminando com NUL o resultado.
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

//The strlen() function calculates the length of the string pointed
//to by s, excluding the terminating null byte ('\0').
size_t	ft_strlen(const char *s);

//Applies the function ’f’ to each character of the
//string ’s’, and passing its index as first argument
//to create a new string (with malloc(3)) resulting
//from successive applications of ’f’.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//The strcmp() function compares the two strings s1 and s2.  The
//locale is not taken into account (for a locale-aware comparison,
//see strcoll(3)).  The comparison is done using unsigned
//characters.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//The strnstr() function locates the	first occurrence of the
//null-termi-nated string little in the	string big, where not
//more than	len characters are searched.  Characters that appear
//after a `\0'	character are not searched.
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

//The strrchr() function returns a pointer to the last occurrence
//of the character c in the string s.
char	*ft_strrchr(const char *str, int c);

//Allocates (with malloc(3)) and returns a copy of
//’s1’ with the characters specified in ’set’ removed
//from the beginning and the end of the string
char	*ft_strtrim(char const *s1, char const *set);

//Allocates (with malloc(3)) and returns a substring
//from the string ’s’.
//The substring begins at index ’start’ and is of
//maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len);

//If c is an uppercase letter, tolower() returns its lowercase
//equivalent, if a lowercase representation exists in the current
//locale.  Otherwise, it returns c.
int		ft_tolower(int c);

//If c is a lowercase letter, toupper() returns its uppercase
//equivalent, if an uppercase representation exists in the current
//locale.  Otherwise, it returns c.
int		ft_toupper(int c);

//*************************************************************
//						new functions						  *
//*************************************************************

//give free in the pointers passed as a parameter
char	*free_ptr(char **bloco1, char **bloco2);

//read a file line by line
char	*get_next_line(int fd);

//count the number of houses in a number
int		numb_house(unsigned long int nbr, int base);

#endif
