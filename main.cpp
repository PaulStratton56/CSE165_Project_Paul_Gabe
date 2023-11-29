#include "GLWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maine window;
    QLabel* centralWidget = new QLabel(&window);
    QVBoxLayout layout(&window);
    QPixmap backgroundImage(window.getDisplayPixmap());
    QMovie mov(window.getAnimation());
    //QPixmap sbI = backgroundImage.scaled(window.size(), Qt::KeepAspectRatio);

    //centralWidget->setPixmap(sbI);
    //centralWidget->setMovie(&mov);
    //centralWidget->setScaledContents(true);
//    MainWindow w;
//    w.show();
    layout.addWidget(centralWidget, 0, Qt::AlignCenter);
    //centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //mov.start();
    window.show();

    return a.exec();
}
