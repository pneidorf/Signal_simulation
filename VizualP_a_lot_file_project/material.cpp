#include "material.h"
#include <QPainter>

#include "Bresenham.h"

void add_material_to_map(int **map, int px, int py, int sx, int sy, int type){
    for(int y = py; y < py + sy; ++y){
        for(int x = px; x < px + sx; ++x){
            map[y][x] = type;
        }
    }
}


Material materials[] = {
    {QColor(0, 191, 255, 255), 0.6},  // Стеклопакет
    {QColor(135, 206, 236, 255), 0.7},  // IRR стекло
    {QColor(105, 105, 105, 255), 0.8},  // Бетон
    {QColor(139, 69, 19, 255), 0.9}  // Дерево\гипсокартон
};
