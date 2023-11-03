/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:18:42 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 14:10:14 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *string, ...);
void	ft_putnbr_pos_fd(unsigned int n, int fd);
void	ft_putnbr_hex(uintptr_t n, int fd);
void	ft_num_to_hex(int n, int fd);
void	ft_num_to_hex_up(int n, int fd);

#endif