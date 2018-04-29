/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:20:50 by tjeanner          #+#    #+#             */
/*   Updated: 2018/04/28 19:11:26 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		get_vect_norm(t_v a)
{
	double	n;

	n = sqrt(vect_scal(a, a));
	return (n);
}

t_v			vect_norm(t_v a)
{
	t_v		b;

	b = vect_div(a, get_vect_norm(a));
	return (b);
}

t_v			vect_mult(t_v a, double n)
{
	t_v		b;

	b.x = a.x * n;
	b.y = a.y * n;
	b.z = a.z * n;
	return (b);
}

t_v			vect_div(t_v a, double n)
{
	t_v		b;
	double	o;

	o = 1.000000 / n;
	b.x = a.x * o;
	b.y = a.y * o;
	b.z = a.z * o;
	return (b);
}

t_v			vect_inv(t_v a)
{
	t_v		b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	return (b);
}

t_v			vect_add(t_v a, t_v b)
{
	t_v		c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_v			vect_sous(t_v a, t_v b)
{
	t_v		c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

double		vect_scal(t_v a, t_v b)
{
	double	n;

	n = a.x * b.x + a.y * b.y + a.z * b.z;
	return (n);
}

t_v			vect_prod(t_v a, t_v b)
{
	t_v		c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = -(a.x * b.z - a.z * b.x);
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_v			vect_reflect(t_v incident, t_v normal)
{
	t_v		r;

	r = vect_sous(incident, vect_mult(normal, 2.0 *
												vect_scal(incident, normal)));
	return (r);
}

t_v			vect_refract(t_v incident, t_v normal, double k)
{
	t_v		t;
	double	c;
	double	s2;

	if (k == 0 || k > 1.)
		return (incident);
	c = -vect_scal(vect_norm(incident), vect_norm(normal));
	s2 = k * k * (1.0 - c * c);
	t = vect_add(vect_mult(incident, k), vect_mult(normal,
													k * c - sqrt(1.0 - s2)));
	return (t);
}
