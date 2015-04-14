#ifndef SVGCANVAS_PLUGIN_H
#define SVGCANVAS_PLUGIN_H

#include <QQmlExtensionPlugin>

class SVGCanvasPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // SVGCANVAS_PLUGIN_H

