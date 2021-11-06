#include "loginregistration.h"
#include "ui_loginregistration.h"
#include "mysite.h"
#include "ui_mysite.h"
#include <QRegularExpression>
#include<QString>
LoginRegistration::LoginRegistration(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginRegistration)
{
    ui->setupUi(this);
    connect(ui->LoginPushButton, SIGNAL(clicked()),
            this, SLOT(LoginPushButton_clicked()));

    connect(ui->RegistrationPushButton, SIGNAL(clicked()),
            this, SLOT(RegistrationPushButton_clicked()));

    connect(ui->LoginLink, SIGNAL(clicked()),
            this, SLOT(LoginLink_clicked()));

    connect(ui->RegistrationLink, SIGNAL(clicked()),
            this, SLOT(RegistrationLink_clicked()));
}

LoginRegistration::~LoginRegistration()
{
    delete ui;
}

bool LoginRegistration::name_validation(QString firstname){
    QRegularExpression rx("\\b[A-Z0-9._%+-]{3,}\\b", QRegularExpression::CaseInsensitiveOption);
    if(!rx.match(firstname).hasMatch()){
        return false;
    }
        return true;
}

bool LoginRegistration::email_validation(QString email){
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
    if(!rx.match(email).hasMatch()){
        return false;
    }
        return true;
}

bool LoginRegistration::password_validation(QString password){
    QRegularExpression rx("\\b(?=.*[A-Z])(?=.*[0-9])(?=.*[._%+-])[A-Z0-9._%+-]{8,}\\b", QRegularExpression::CaseInsensitiveOption);
    if(!rx.match(password).hasMatch()){
        return false;
    }
        return true;
}

void LoginRegistration::add_user(QString firstname,QString lastname,QString email,QString password){
    QList<QString> data;
    data<< firstname << lastname << email << password;
    users_list.push_front(data);
}

bool LoginRegistration::find_user_email(QString email){
    int size=users_list.size();
       for(int i=0; i<size; i++){
           if(users_list[i][2] == email){
               return true;
           }
       }
           return false;
}

void LoginRegistration::empty_registration_fields(){
    ui->FirstNameLineEdit->    setText("");
    ui->LastNameLineEdit->     setText("");
    ui->EmailLineEdit->        setText("");
    ui->PasswordLineEdit->     setText("");
    ui->ConfPasswordLineEdit-> setText("");
}

void LoginRegistration::empty_login_fields(){
    ui->LoginEmailLineEdit->    setText("");
    ui->LoginPasswordLineEdit-> setText("");
}

void LoginRegistration::RegistrationPushButton_clicked()
{
    QString first_name =    ui->FirstNameLineEdit->text();
    QString last_name =     ui->LastNameLineEdit->text();
    QString email =         ui->EmailLineEdit->text();
    QString password =      ui->PasswordLineEdit->text();
    QString conf_password = ui->ConfPasswordLineEdit->text();

    ui->RegistrationErrorList->setStyleSheet("color:red;background:none;");

    if(first_name.isEmpty() || last_name.isEmpty() || email.isEmpty() || password.isEmpty()){
        return;
    }

    if(find_user_email(email)){
        ui->RegistrationErrorList->setText("User with this email exist!!!");
        return;
    }

    if(!(password == conf_password)){
        ui->RegistrationErrorList->setText("Passwords doesn't match!!!");
        return;
    }

    if(!name_validation(first_name)){
         ui->RegistrationErrorList->setText("Invalid name!!!");
         return;
    }

    if(!name_validation(last_name)){
          ui->RegistrationErrorList->setText("Invalid last name!!!");
          return;
    }

    if(!email_validation(email)){
          ui->RegistrationErrorList->setText("Invalid email!!!");
          return;
    }

    if(!password_validation(password)){
          ui->RegistrationErrorList->setText("Invalid password!!!");
          return;
    }

        add_user(first_name,last_name,email,password);
        empty_registration_fields();
        ui->RegistrationErrorList->setStyleSheet("color:#4CAF50;background:none;");
        ui->RegistrationErrorList->setText("Success!!!");
        //qDebug()<<LoginRegistration::users_list[0][0];
}

void LoginRegistration::LoginPushButton_clicked()
{
    QString login    = ui->LoginEmailLineEdit    ->text();
    QString password = ui->LoginPasswordLineEdit ->text();

    ui->LoginErrorList->setStyleSheet("color:rgb(135, 0, 0);background:white ;");
    if(login.isEmpty() || password.isEmpty()){
        return;
    }
    if(!email_validation(login)){
          ui->LoginErrorList->setText("Please enter valid email!");
          return;
    }

    int size = LoginRegistration::users_list.size();
    for(int i=0; i<size; i++){
        if(LoginRegistration::users_list[i][2] == login  &&  LoginRegistration::users_list[i][3] == password )
        {
             MySite site;
             site.setModal(true);
             site.exec();
             empty_login_fields();
             ui->LoginErrorList->setText("Fill in all fields");
             ui->LoginErrorList->setStyleSheet("color:white; background:rgb(135, 0, 0);");
             return;
        }
    }
    ui->LoginErrorList->setText("Wrong login or password!");
}

void LoginRegistration::LoginLink_clicked()
{
    ui->RegistrationErrorList->setStyleSheet("color:white;background:#4CAF50;");
    ui->RegistrationErrorList->setText("Fill in all fields");
    empty_registration_fields();
    ui->RegistrationFrame->hide();
    ui->LoginFrame->show();
}

void LoginRegistration::RegistrationLink_clicked()
{
    ui->LoginErrorList->setStyleSheet("color:white;background: rgb(135, 0, 0);");
    ui->LoginErrorList->setText("Please fill in all fields");
    empty_login_fields();
    ui->LoginFrame->hide();
    ui->RegistrationFrame->show();
}




