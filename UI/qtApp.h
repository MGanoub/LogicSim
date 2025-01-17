#ifndef QTAPP_H
#define QTAPP_H

#include "UI/Models/componentModel.h"
#include <QApplication>
#include <QObject>
#include <memory>

namespace UI
{
    class MainGuiContainer;
    class QtApp : public QObject
    {
        Q_OBJECT
    public:
        QtApp(QtApp const &) = delete;
        QtApp &operator=(QtApp const &) = delete;
        QtApp(QtApp const &&) = delete;
        QtApp &operator=(QtApp const &&) = delete;

        static QtApp &getInstance();
        void startGuiApp();

    private:
        QtApp();
        std::unique_ptr<QApplication> m_app;
        int m_appArgcount;
        std::unique_ptr<MainGuiContainer> m_mainGuiContainer;
        ComponentModel m_componentModel;
    };
}

#endif // QTAPP_H
