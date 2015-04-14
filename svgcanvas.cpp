#include "svgcanvas.h"
#include <QPainter>

SVGCanvas::SVGCanvas(QQuickItem *parent):
    QQuickPaintedItem(parent)
{
    this->m_renderer = new QSvgRenderer(m_content, this);
}

QString SVGCanvas::content() const
{
    return this->m_content;
}

void SVGCanvas::setContent(const QString& content)
{
    this->m_content = content.toLatin1();
    this->m_renderer->load(m_content);
    this->update();
    emit contentChanged();
}

void SVGCanvas::paint(QPainter *painter)
{
    painter->setRenderHints(QPainter::Antialiasing, true);
    m_renderer->render(painter);
}

SVGCanvas::~SVGCanvas()
{
    delete m_renderer;
}

