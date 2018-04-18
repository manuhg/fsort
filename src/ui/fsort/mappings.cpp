#include "mappings.h"
#include "ui_mappings.h"

Mappings::Mappings(QWidget *parent,QMap<QString,QVector<double>> *map) :   QDialog(parent),  ui(new Ui::Mappings)
{
    ui->setupUi(this);
    //set the scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //add  background image
    QImage b_image("/home/sensei/Pictures/error.png");
    QGraphicsPixmapItem* BackGround=new QGraphicsPixmapItem(QPixmap::fromImage(b_image));
    scene->addItem(BackGround);
    //add the images at respective x y coordinates
    for(i=map->begin();i!=map->end();i++)
    {
        QImage image(i.key());
        item=new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        item->setPos(i.value()[0],i.value()[1]);
    }

}

Mappings::~Mappings()
{
    delete ui;
}
