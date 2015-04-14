#ifndef SVGCANVAS_H
#define SVGCANVAS_H

#include <QQuickPaintedItem>
#include <QSvgRenderer>

class SVGCanvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(SVGCanvas)
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
public:
    SVGCanvas(QQuickItem *parent = 0);
    ~SVGCanvas();

    QString content() const;
    void setContent(const QString& content);

    void paint(QPainter *painter);
signals:
    void contentChanged();

private:
    QByteArray m_content;
    QSvgRenderer *m_renderer;
};

#endif // SVGCANVAS_H

