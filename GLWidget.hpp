#ifndef GLWIDGET_HPP
#define GLWIDGET_HPP

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QLabel>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {
        // Constructor initialization code, if needed
    }

protected:
    void initializeGL() {
        initializeOpenGLFunctions();
        // Your OpenGL initialization code
    }

    void resizeGL(int w, int h) {
        // Your resize code
    }

    void paintGL() override {
        // Your paint code
    }

    void mousePressEvent(QMouseEvent *event) {
        // Your mouse press event code
    }

    void mouseMoveEvent(QMouseEvent *event) {
        // Your mouse move event code
    }

    void keyPressEvent(QKeyEvent *event) {
        // Your key press event code
    }
};

#endif // GLWIDGET_HPP
