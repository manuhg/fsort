#include "mappings.h"
#include "ui_mappings.h"

Mappings::Mappings(QWidget *parent,QMap<QString,QVector<double>> *map) :   QDialog(parent),  ui(new Ui::Mappings)
{
    ui->setupUi(this);
    //set the scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //add  background image
    pixmap=new QPixmap(":/Images/Background_image.jpg");
    QGraphicsPixmapItem* BackGround=new QGraphicsPixmapItem(*pixmap);
    scene->addItem(BackGround);
    //add the images at respective x y coordinates
    for(i=map->begin();i!=map->end();i++)
    {
        pixmap=new QPixmap(i.key());
        *pixmap=pixmap->scaled(100,100);
        item=new QGraphicsPixmapItem(*pixmap);
        scene->addItem(item);
        item->setPos(i.value()[0],i.value()[1]);
    }

}

Mappings::~Mappings()
{
    delete ui;
}
