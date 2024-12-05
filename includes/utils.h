/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:48 by mbaypara          #+#    #+#             */
/*   Updated: 2024/12/05 16:49:45 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// Basic Structures

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
}	t_ray;

typedef struct s_impact
{
	char		*object;
	double		distance;
	t_vector3	point;
	t_vector3	normal;
}	t_impact;

// Elements

typedef struct s_camera
{
	t_vector3	position;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector3	position;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector3	position;
	double		radius;
	t_color		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector3	position;
	t_vector3	position2;
	double		radius;
	double		height;
	t_color		color;
	int			is_closed;
}	t_cylinder;

typedef struct s_plane
{
	t_vector3	position;
	t_vector3	normal;
	t_color		color;
}	t_plane;

#endif