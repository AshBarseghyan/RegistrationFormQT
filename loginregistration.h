#ifndef LOGINREGISTRATION_H
#define LOGINREGISTRATION_H
#include "mysite.h"
#include <QList>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginRegistration; }
QT_END_NAMESPACE

class LoginRegistration : public QMainWindow
{
    Q_OBJECT

public:
    LoginRegistration(QWidget *parent = nullptr);
    ~LoginRegistration();

private slots:
    void RegistrationPushButton_clicked();

    void LoginPushButton_clicked();

    void LoginLink_clicked();

    void RegistrationLink_clicked();

private:
    Ui::LoginRegistration *ui;
    QList<QList<QString>> users_list;
    bool name_validation(QString name);
    bool email_validation(QString email);
    bool password_validation(QString password);
    void empty_registration_fields();
    void empty_login_fields();
    void add_user(QString firtsname,QString lastname,QString email,QString password);
    bool find_user_email(QString email);
};
#endif // LOGINREGISTRATION_H
