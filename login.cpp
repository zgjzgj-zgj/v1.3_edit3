#include "login.h"
#include<QMessageBox>
#include<QHBoxLayout>
#include<QVBoxLayout>

login::login(QDialog *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("登录界面"));

    username = new QLabel(this);
    username->setText("用户名");

    usernameed = new QLineEdit(this);
    usernameed->setPlaceholderText(tr("请输入用户名"));

    password = new QLabel(this);
    password->setText("密  码");

    passworded = new QLineEdit(this);
    passworded->setPlaceholderText("请输入密码");
    passworded->setEchoMode(QLineEdit::Password);

    loginbtn = new QPushButton(this);
    loginbtn->setText("登录");

    QHBoxLayout *layout1 = new QHBoxLayout;
    QHBoxLayout *layout2 = new QHBoxLayout;

    layout1->addWidget(username);
    layout1->addWidget(usernameed);
    layout2->addWidget(password);
    layout2->addWidget(passworded);

    QVBoxLayout *layout3 = new QVBoxLayout;
    layout3->addLayout(layout1);
    layout3->addLayout(layout2);
    layout3->addWidget(loginbtn);

    this->setLayout(layout3);
    this->setWindowIcon(QIcon("F:/class/practice/HEU.jpg"));


    connect(loginbtn,&QPushButton::clicked,this,&login::login1);
}
    void login::login1()
    {
        if(usernameed->text().trimmed() == tr("1") && passworded->text() == tr("1"))
        {
            accept();
        }
        else
        {
            QMessageBox::warning(this,tr("警告!"),tr("用户名或密码错误！"),QMessageBox::Yes);

            usernameed->clear();
            passworded->clear();

        }
    }

