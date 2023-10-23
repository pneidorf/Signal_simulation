#ifndef MATERIAL_H
#define MATERIAL_H

#include <QtWidgets>
#include <QGroupBox>
#include <QWidget>
#include <cmath>
struct Material;
void add_material_to_map(int **map, int px, int py, int sx, int sy, int type);

/*
struct Material {
    QColor color;   // Цвет материала
    double absorption;  // Сила поглощения
};
*/
/*
Material materials[] = {
    {QColor(0, 191, 255, 255), 0.6},  // Стеклопакет
    {QColor(135, 206, 236, 255), 0.7},  // IRR стекло
    {QColor(105, 105, 105, 255), 0.8},  // Бетон
    {QColor(139, 69, 19, 255), 0.9}  // Дерево\гипсокартон
};
*/
extern Material materials[];
#endif // MATERIAL_H
