#include "map_heat.h"
#include <iostream>

#include <QtDataVisualization/Q3DTheme>
#include <QtDataVisualization/QCustom3DItem>
#include <QtDataVisualization/QCustom3DLabel>
#include <QtGui/QImage>
#include <QtDataVisualization/QAbstract3DGraph>


#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>
#include <QtCore/QPropertyAnimation>

#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>

using namespace QtDataVisualization;

map_heat::map_heat(int pos_x, int pos_y, int size_x, int size_y, int size_map_x, int size_map_y)\
    : pos_x(pos_x), pos_y(pos_y), size_x(size_x), size_map_x(size_map_x), size_map_y(size_map_y)
{
    graph = new Q3DSurface();
    graph->setSelectionMode(QAbstract3DGraph::SelectionRowAndColumn);
    graph->axisY()->setRange(40.0f, 500.0f);
    container = QWidget::createWindowContainer(graph);
    container->setGeometry(pos_x, pos_y, size_x, size_y);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);
    //QVector3D positionOne = QVector3D(0, 0, 0);
    QImage color = QImage(2, 2, QImage::Format_RGB32);
    color.fill(Qt::red);
    QImage layerOneHMap(filename2);
    QHeightMapSurfaceDataProxy *layerOneProxy = new QHeightMapSurfaceDataProxy(layerOneHMap);
    layerOneSeries = new QSurface3DSeries(layerOneProxy);
    layerOneSeries->setItemLabelFormat(QStringLiteral("(@xLabel, @zLabel): @yLabel"));
    layerOneProxy->setValueRanges(0, size_map_x, 0, size_map_y);

    layerOneSeries->setDrawMode(QSurface3DSeries::DrawSurface);
    layerOneSeries->setFlatShadingEnabled(false);
    graph->addSeries(layerOneSeries);
}

QWidget *map_heat::get_container(){
    return container;
}

QSurface3DSeries *map_heat::get_QSurface3DSeries(){
    return layerOneSeries;
}
void map_heat::draw(char *file_texture){
    layerOneSeries->setTextureFile(file_texture);

}



