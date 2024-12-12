/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:58:56 by mbaypara          #+#    #+#             */
/*   Updated: 2024/12/11 15:34:20 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector3	new_vec3(double x, double y, double z)
{
	t_vector3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	distance(t_vector3 a, t_vector3 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

t_vector3	vec3_op(t_vector3 v1, t_vector3 v2, double scalar, char op)
{
	double	length;

	if (op == 'n')
	{
		length = distance(new_vec3(0, 0, 0), v1);
		return (new_vec3(v1.x / length, v1.y / length, v1.z / length));
	}
	else if (op == 'a')
		return (new_vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
	else if (op == 's')
		return (new_vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
	else if (op == 'm')
		return (new_vec3(v1.x * scalar, v1.y * scalar, v1.z * scalar));
	return (new_vec3(0, 0, 0));
}

double	dot_product(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector3	cross_product(t_vector3 v1, t_vector3 v2)
{
	t_vector3	cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}