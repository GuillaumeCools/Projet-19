/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:18:42 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 15:23:10 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> // a retirer !!!

int		ft_printf(const char *string, ...);
int		ft_putnbr_pos_return(unsigned int n, int fd);
int		ft_putnbr_hex_return(uintptr_t n, int fd);
int		ft_num_to_hex_return(unsigned int n, int fd);
int		ft_num_to_hex_up_return(unsigned int n, int fd);
int		ft_putchar_return(char c, int fd);
int		ft_putstr_return(char *s, int fd);
int		ft_putnbr_return(int n, int fd);
size_t	ft_strlen(const char *s);
int		ft_intlen_original(int n);
int		ft_intlen_hex(uintptr_t n);
int		ft_intlen_pos(unsigned int n);

#endif