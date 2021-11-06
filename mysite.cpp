#include "mysite.h"
#include "ui_mysite.h"

MySite::MySite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MySite)
{
    ui->setupUi(this);

}

MySite::~MySite()
{
    delete ui;
}


