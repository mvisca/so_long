/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:56:44 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/08/28 17:14:41 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_DEFINES_H
# define SL_DEFINES_H

// Selecciona el header de minilib para MacOS o Linux
# ifdef __APPLE__
#  define ESC 53
#  define ARRL 123
#  define ARRR 124
#  define ARRU 126
#  define ARRD 125
#  define A 0
#  define W 13
#  define S 1
#  define D 2
#  define KP 2
#  define KR 17
#  define KPM 0
#  define KPM 0
# elif __linux__
#  include <X11/keysym.h>
#  define ESC XK_w
#  define ARRU XK_Up
#  define ARRD XK_Down
#  define ARRL XK_Left
#  define ARRR XK_Right
#  define A XK_a
#  define W XK_w
#  define S XK_s
#  define D XK_d
#  define KP KeyPress
#  define KR KeyRelease
#  define KPM KeyPressMask
#  define KPM KeyReleseMask
# else
#  error "Sistema opeartivo no compatible"
# endif

#endif
