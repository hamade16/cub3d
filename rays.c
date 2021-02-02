/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:05:23 by houbeid           #+#    #+#             */
/*   Updated: 2020/12/24 15:05:25 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float       distancebetweenpoints(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float       normalized_angle(float angle)
{
	angle = remainder(angle , 2 * M_PI);
	while (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void castRay(t_rays *rays, int i)
{
    rayangle = normalized_angle(rayangle);
    
    int isRayFacingDown = rayangle > 0 && rayangle < M_PI;
    //printf("%d\n",isRayFacingDown);
    int isRayFacingUp = !isRayFacingDown;

    int isRayFacingRight = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
    int isRayFacingLeft = !isRayFacingRight;
    float xintercept, yintercept;
    float xstep, ystep;

    // rays[i].wallHitX = 0;
    // rays[i].wallHitY = 0;
    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundHorzWallHit = FALSE;
    float horzWallHitX = 0;
    float horzWallHitY = 0;
    int horzWallContent = 0;
    float xToCheck;
    float yToCheck;
    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(yplayer / CUB) * CUB;
    yintercept += isRayFacingDown ? CUB : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = xplayer + (yintercept - yplayer) / tan(rayangle);

    // Calculate the increment xstep and ystep
    ystep = CUB;
    ystep *= isRayFacingUp ? -1 : 1;

    xstep = CUB / tan(rayangle);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    //printf("a %f\n",nextHorzTouchX);
    while ((nextHorzTouchX >= 0) && (nextHorzTouchX < (map_clumns * CUB)) && (nextHorzTouchY >= 0) && (nextHorzTouchY < (map_rows * CUB))) {

        xToCheck = nextHorzTouchX;
        yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
        if (haswallat(xToCheck, yToCheck)) {
            // found a wall hit
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
           if (xToCheck >= 0 && xToCheck < map_clumns * CUB && yToCheck >= 0 && yToCheck < map_rows * CUB) {
                int index_x = (int)floor(xToCheck / CUB);
                int index_y = (int)floor(yToCheck / CUB);
                horzWallContent = map[index_y][index_x];
                foundHorzWallHit = TRUE;
                break;
           }
        }
        nextHorzTouchX += xstep;
        nextHorzTouchY += ystep;
    }

    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundVertWallHit = FALSE;
    float vertWallHitX = 0;
    float vertWallHitY = 0;
    int vertWallContent = 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = floor(xplayer / CUB) * CUB;
    xintercept += isRayFacingRight ? CUB : 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = yplayer + (xintercept - xplayer) * tan(rayangle);

    // Calculate the increment xstep and ystep
    xstep = CUB;
    xstep *= isRayFacingLeft ? -1 : 1;

    ystep = CUB * tan(rayangle);
    ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
    ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX < map_clumns * CUB && nextVertTouchY >= 0 && nextVertTouchY < map_rows * CUB) {
        xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
        yToCheck = nextVertTouchY;
        // printf("xtocheck = %f | ytocheck == %f\n", xToCheck, yToCheck);
        
        if (haswallat(xToCheck, yToCheck)) {
            // found a wall hit
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
        //    if (xToCheck < 0 || xToCheck > map_clumns * CUB || yToCheck < 0 || yToCheck > map_rows * CUB)
		//        return ;
           if (xToCheck >= 0 && xToCheck < map_clumns * CUB && yToCheck >= 0 && yToCheck < map_rows * CUB) {
                int index_x = (int)floor(xToCheck / CUB);
                int index_y = (int)floor(yToCheck / CUB);

                vertWallContent = map[index_y][index_x];
                foundVertWallHit = TRUE;
                break;
            }
        }
        nextVertTouchX += xstep;
        nextVertTouchY += ystep;
    }
    // Calculate both horizontal and vertical hit distances and choose the smallest one
    float horzHitDistance = foundHorzWallHit
        ? distancebetweenpoints(xplayer, yplayer, horzWallHitX, horzWallHitY)
        : INT_MAX;
    float vertHitDistance = foundVertWallHit
        ? distancebetweenpoints(xplayer, yplayer, vertWallHitX, vertWallHitY)
        : INT_MAX;
    // printf("dis %f %f\n", horzHitDistance, vertHitDistance);
    
    if (horzHitDistance < vertHitDistance) {
        rays[i].distance = horzHitDistance;
        rays[i].wallHitX = horzWallHitX;
        rays[i].wallHitY = horzWallHitY;
        rays[i].wallHitContent = horzWallContent;
        rays[i].wasHitVertical = FALSE;
    } else {
        rays[i].distance = vertHitDistance;
        rays[i].wallHitX = vertWallHitX;
        rays[i].wallHitY = vertWallHitY;
        rays[i].wallHitContent = vertWallContent;
        rays[i].wasHitVertical = TRUE;
    }
    rays[i].rayAngle = rayangle;
    rays[i].isRayFacingDown = isRayFacingDown;
    rays[i].isRayFacingUp = isRayFacingUp;
    rays[i].isRayFacingLeft = isRayFacingLeft;
    rays[i].isRayFacingRight = isRayFacingRight;
}

void castAllRays(t_rays *rays, int draw)
{
    //printf("hamade");
    rayangle = rotationangle - (FOV / 2);
    for (int i = 0; i < width; i++)
    {
        if (!draw)
            castRay(rays, i);
        else {
            draw_line(rays[i].wallHitX,rays[i].wallHitY,xplayer,yplayer);
        }
        rayangle += FOV / (width);
    }
    write(1, "\n", 1);
}
