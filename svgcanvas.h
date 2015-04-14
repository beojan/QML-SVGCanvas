#ifndef SVGCANVAS_H
#define SVGCANVAS_H

#include <QQuickPaintedItem>
#include <QSvgRenderer>

class SVGCanvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(SVGCanvas)
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(bool animated READ animated)
    Q_PROPERTY(int fps READ fps WRITE setFps)
public:
    SVGCanvas(QQuickItem *parent = 0);
    ~SVGCanvas();

    QString content() const;
    void setContent(const QString& content);

    bool animated() const;

    int fps() const;
    void setFps(int fps);

    void paint(QPainter *painter);
public slots:
    void repaint();

signals:
    void contentChanged();


private:
    QByteArray m_content;
    QSvgRenderer *m_renderer;
};

#endif // SVGCANVAS_H

