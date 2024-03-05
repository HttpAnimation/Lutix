#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("Lutix - Qt Demo");

    // Create a label widget
    QLabel *label = new QLabel("Hello, Qt!", &window);
    label->setAlignment(Qt::AlignCenter);

    // Add the label to the main window's central widget
    window.setCentralWidget(label);

    // Create a status bar and set some text
    window.setStatusBar(new QStatusBar(&window));
    window.statusBar()->showMessage("Ready");

    // Create a menu bar with a File menu and an Exit action
    QMenu *fileMenu = window.menuBar()->addMenu("&File");
    QAction *exitAction = fileMenu->addAction("&Exit");
    QObject::connect(exitAction, &QAction::triggered, &window, &QMainWindow::close);

    // Show the main window
    window.show();

    // Run the application event loop
    return app.exec();
}
