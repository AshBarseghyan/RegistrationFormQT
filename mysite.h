#ifndef MYSITE_H
#define MYSITE_H

#include <QDialog>

namespace Ui {
class MySite;
}

class MySite : public QDialog
{
    Q_OBJECT

public:
    explicit MySite(QWidget *parent = nullptr);
    ~MySite();

private slots:


private:
    Ui::MySite *ui;
};

#endif // MYSITE_H
