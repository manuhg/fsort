#include "mappings.h"
#include "ui_mappings.h"

Mappings::Mappings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mappings)
{
    ui->setupUi(this);
    /* create a graphics view for adding images on x and y coordinates*/
}

Mappings::~Mappings()
{
    delete ui;
}
