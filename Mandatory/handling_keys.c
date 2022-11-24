#include "include/cub3d.h"

int check_wall_1(double x, double y, t_cub *cub)
{
    int mapGrindIndexX;
    int mapGrindIndexY;
    mapGrindIndexX = x / 64;
    if (cub->player.walkDirection < 0)
        mapGrindIndexY = (y - 10) / 64;
    else
        mapGrindIndexY = (y + 10) / 64;

    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    if (cub->player.walkDirection < 0)
        mapGrindIndexX = (x + 10) / 64;
    else
        mapGrindIndexX = (x - 10) / 64;
    mapGrindIndexY = (y) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    return 0;
}

int check_wall_2(double x, double y, t_cub *cub)
{
    int mapGrindIndexX;
    int mapGrindIndexY;

    mapGrindIndexX = x / 64;
    if (cub->player.walkDirection < 0)
        mapGrindIndexY = (y + 10) / 64;
    else
        mapGrindIndexY = (y - 10) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    if (cub->player.walkDirection < 0)
        mapGrindIndexX = (x + 10) / 64;
    else
        mapGrindIndexX = (x - 10) / 64;
    mapGrindIndexY = (y) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    return 0;
}
int check_wall_3(double x, double y, t_cub *cub)
{
    int mapGrindIndexX;
    int mapGrindIndexY;
    if (cub->player.walkDirection < 0)
        mapGrindIndexX = (x - 10) / 64;
    else
        mapGrindIndexX = (x + 10) / 64;
    mapGrindIndexY = (y) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    mapGrindIndexX = (x) / 64;
    if (cub->player.walkDirection < 0)
        mapGrindIndexY = (y + 10) / 64;
    else
        mapGrindIndexY = (y - 10) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    return 0;
}
int check_wall_4(double x, double y, t_cub *cub)
{
    int mapGrindIndexX;
    int mapGrindIndexY;
    mapGrindIndexX = (x) / 64;
    if (cub->player.walkDirection < 0)
        mapGrindIndexY = (y - 10) / 64;
    else
        mapGrindIndexY = (y + 10) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    if (cub->player.walkDirection < 0)
        mapGrindIndexX = (x - 10) / 64;
    else
        mapGrindIndexX = (x + 10) / 64;
    mapGrindIndexY = (y) / 64;
    if (cub->map[mapGrindIndexY][mapGrindIndexX] == '1')
        return 1;
    return 0;
}

int check_all(double x, double y, t_cub *cub)
{
    if (cub->map[(int)y / 64][(int)x / 64] == 'D')
        return 1;
    if (cub->player.angle_of_player < M_PI && cub->player.angle_of_player >= M_PI_2)
    {
        if (check_wall_1(x, y, cub))
            return 1;
    }
    else if (cub->player.angle_of_player > M_PI && cub->player.angle_of_player <= 1.5 * M_PI)
    {
        if (check_wall_2(x, y, cub))
            return 1;
    }
    else if (cub->player.angle_of_player > 1.5 * M_PI)
    {
        if (check_wall_3(x, y, cub))
            return 1;
    }
    else if (cub->player.angle_of_player >= 0 && cub->player.angle_of_player < M_PI_2)
        if (check_wall_4(x, y, cub))
            return 1;
    return 0;
}
int hasWallat(double x, double y, t_cub *cub, int key)
{
    if (x < 0 || x > cub->win_width || y < 0 || y > cub->win_height)
        return 1;
    if (cub->map[(int)y / 64][(int)x / 64] != '1')
    {
        if(check_all(x, y, cub))
            return 1;
        return 0;
    }
    return (1);
}
