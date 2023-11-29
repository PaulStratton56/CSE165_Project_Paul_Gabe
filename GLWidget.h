#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMovie>
#include <QTimer>
#include <QDebug>
#include <QPushButton>
#include <random>

//abstract  class
class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {
        // Constructor initialization code, if needed
    }
protected:
    void initializeGL() override {
        initializeOpenGLFunctions();
        // Your OpenGL initialization code
        this->resize(1366, 768);
    }

    void resizeGL(int w, int h) override {
        // Your resize code
    }

    void mousePressEvent(QMouseEvent *event) override {
        // Your mouse press event code
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        // Your mouse move event code
    }

    void keyPressEvent(QKeyEvent *event) override {
        // Your key press event code
    }
    virtual QPixmap getDisplayPixmap() const = 0;
    //virtual QTimer getTime() const = 0;
    //virtual QMovie getAnimation() const = 0;
};

//main screen
class Maine : public GLWidget{
    Q_OBJECT
public:

    Maine(QWidget *parent = nullptr) : GLWidget(parent){
        this->resize(1366, 738);
        QLabel *mainer = new QLabel(this);
        QPushButton *button = new QPushButton("Start", this);
        QPixmap bImage(":/resource/testbg.png");
        QPixmap bI = bImage.scaled(this->size(), Qt::KeepAspectRatio);
        mainer->setPixmap(bI);
        mainer->setGeometry(370, 0, 1366, 738);
        button->setGeometry(590,650,200,60);
    }
    ~Maine(){
    }

    QPixmap getDisplayPixmap() const override {
        return QPixmap(":/resource/testbg.png");
    }
    QMovie getAnimation() const{
        return QMovie(":/resource/zoff.gif");
    }
private:
//    void OnButtonClick(){
//        int seed = distribution(0, 2);
//    }
};

//typer racer type minigame
class TypeOrder : public GLWidget{
    Q_OBJECT
public:
    QTimer* timer;
    TypeOrder(QWidget *parent = nullptr) : GLWidget(parent){
        this->resize(1366, 738);
        timer = new QTimer(this);
    }

    ~TypeOrder(){
        delete timer;
    }

    QPixmap getDisplayPixmap() const {
        return QPixmap(":/source/zessay.png");
    }
    QMovie getAnimation() const{
        return QMovie(":/resource/zoff.gif");
    }
};

//target avoider minigame
class TargetAvoid : public GLWidget{
    Q_OBJECT
public:
    TargetAvoid(QWidget *parent = nullptr) : GLWidget(parent){
        this->resize(1366, 738);
    }

    QPixmap getDisplayPixmap() const {
        return QPixmap(":/source/zavoider.png");
    }
};

//target clicker minigame
class TargetPractice : public GLWidget{
    Q_OBJECT
public:
    TargetPractice (QWidget *parent = nullptr) : GLWidget(parent){}

    QPixmap getDisplayPixmap() const {
        return QPixmap(":/source/zessay.png");
    }
};

#endif
