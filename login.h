#ifndef LOGIN_H
#define LOGIN_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>


class login : public QDialog
{
    Q_OBJECT
public:
   explicit login(QDialog *parent = 0);

signals:
public slots:
    void login1();
private:
    QLabel *username;
    QLabel *password;
    QLineEdit *usernameed;
    QLineEdit *passworded;
    QPushButton *loginbtn;


};

#endif // LOGIN_H
