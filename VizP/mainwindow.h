#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#define SIZE_MAP_X 1000
#define SIZE_MAP_Y 1000


enum class type_material : int{
    NO_MATERIAL = 0,
    GLASS,
    IRR_GLASS,
    CONCRETE,
    WOOD,
    DRYWALL,
    COUNT_MATERIAL
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int **map_obj;


    void drawSignalStrength(QPixmap *map);
    void setupMap();
    void createColorMap();
private:
    QLabel *label_;
    QGroupBox *gradientGroupBox_;

};
//void add_material_to_map(int **map, int px, int py, int sx, int sy, int type);
#endif // MAINWINDOW_H
