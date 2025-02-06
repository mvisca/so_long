/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:56:44 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/09/05 15:39:55 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_DEFINES_H
# define SL_DEFINES_H

// Tecla ESC
# define ESC 65307  // Correcto en X11

// Flechas de dirección
# define ARRL 65361  // Flecha izquierda
# define ARRR 65363  // Flecha derecha
# define ARRU 65362  // Flecha arriba
# define ARRD 65364  // Flecha abajo

// Teclas WASD
# define A 97   // 'A' en X11
# define W 119  // 'W' en X11
# define S 115  // 'S' en X11
# define D 100  // 'D' en X11

// Otras teclas (ajustar según necesidad)
# define KP 50  // Teclado numérico (ejemplo)
# define KR 114 // Otra tecla (ejemplo)

// Eliminar la duplicación de KPM
# define KPM 0

#endif
