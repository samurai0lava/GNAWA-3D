/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samurai0lava <samurai0lava@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:40:03 by iouhssei          #+#    #+#             */
/*   Updated: 2025/06/27 15:04:46 by samurai0lav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static t_wall	calculate_wall_draw_params(t_raycast *rc)
{
	t_wall	params;

	params.tex_step = (double)rc->selected_tex->height / rc->wall_height;
	params.start_y = (HEIGHT / 2) - (rc->wall_height / 2);
	params.end_y = (HEIGHT / 2) + (rc->wall_height / 2);
	if (params.start_y < 0)
		params.start_y = 0;
	if (params.end_y > HEIGHT)
		params.end_y = HEIGHT;
	return (params);
}

void	draw_textured_wall_segment(t_cube *cube, t_raycast *rc,
	t_wall params, int draw_start_y)
{
double	tex_pos;
int		tex_y;
int		y;
int		color;

tex_pos = (draw_start_y - (HEIGHT / 2.0 - rc->wall_height / 2.0))
	* params.tex_step;
y = draw_start_y;
while (y < params.end_y)
{
	tex_y = (int)tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= rc->selected_tex->height)
		tex_y = rc->selected_tex->height - 1;
	color = get_texture_pixel(rc->selected_tex, rc->tex_x, tex_y);
	my_mlx_pixel_put(cube->data, rc->x, y, color_shading(color,
			rc->perpwalldist));
	tex_pos += params.tex_step;
	y++;
}
}

static int	draw_textured_sky(t_cube *cube, int x, int start_y)
{
    int y;
    double sky_angle;
    int tex_x, tex_y;
    int color;

    // Calculate the horizontal angle for this column
    sky_angle = cube->start_angle + x * FOV / WIDTH;
    // Map angle to [0, 1] for texture X
    tex_x = (int)((fmod(sky_angle / (2 * PI), 1.0)) * cube->sky.sky_width);
    if (tex_x < 0)
        tex_x += cube->sky.sky_width;
    for (y = 0; y < start_y; y++)
    {
        // Map y to texture y
        tex_y = (int)(((double)y / (double)HEIGHT) * cube->sky.sky_height);
        color = cube->sky.sky_pixels[tex_y * cube->sky.sky_width + tex_x];
        my_mlx_pixel_put(cube->data, x, y, color);
    }
    return y;
}

// static void draw_ground(t_cube *cube, int start_y, int x)
// {
//     int y = start_y;
//     while (y < HEIGHT)
//     {
//         // Example distance factor; adapt to your engine math
//         double dist_factor = (double)(y - HEIGHT / 2) / (HEIGHT / 2);

//         // Compute “floor world” coordinates
//         double floor_x = cube->p_x + dist_factor * cos(cube->angle);
//         double floor_y = cube->p_y + dist_factor * sin(cube->angle);

//         // Wrap coords in texture boundaries
//         int tex_x = (int)(floor_x * cube->ground.ground_width)
//             % cube->ground.ground_width;
//         int tex_y = (int)(floor_y * cube->ground.ground_height)
//             % cube->ground.ground_height;

//         // Get pixel color and draw
//         int color = cube->ground.ground_pixels[tex_y
//             * cube->ground.ground_width + tex_x];
//         my_mlx_pixel_put(cube->data, x, y, color);
//         y++;
//     }
// }


void	draw_vertical_line_with_texture(t_cube *cube, int x, t_raycast *rc)
{
    t_wall	params;
    int		start_y;

    rc->x = x;
    if (rc->wall_height <= 0 || !rc->selected_tex || rc->tex_x < 0
        || rc->tex_x >= rc->selected_tex->width)
    {
        start_y = draw_textured_sky(cube, x, 0);
        draw_floor(cube, start_y, x);
        return ;
    }
    params = calculate_wall_draw_params(rc);
    start_y = draw_textured_sky(cube, x, params.start_y);
    draw_textured_wall_segment(cube, rc, params, start_y);
    draw_floor(cube, params.end_y, x);
}
