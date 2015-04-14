#include "svgcanvas.h"
#include <QPainter>

SVGCanvas::SVGCanvas(QQuickItem *parent):
    QQuickPaintedItem(parent)
{
    this->m_renderer = new QSvgRenderer(m_content, this);
    this->m_renderer->setFramesPerSecond(60);
    connect(m_renderer, SIGNAL(repaintNeeded()), this, SLOT(repaint()));
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

bool SVGCanvas::animated() const
{
    return m_renderer->animated();
}

int SVGCanvas::fps() const
{
    return m_renderer->framesPerSecond();
}

void SVGCanvas::setFps(int fps)
{
    m_renderer->setFramesPerSecond(fps);
}

void SVGCanvas::repaint()
{
    this->update();
}

void SVGCanvas::paint(QPainter *painter)
{
    painter->setRenderHints(QPainter::Antialiasing, true);
    //Fix aspect ratio issue
    QSize defSize = m_renderer->defaultSize();
    QSizeF mySize = this->boundingRect().size();
    qreal widthRatio = mySize.width() / defSize.width();
    qreal heightRatio = mySize.height() / defSize.height();
    if(widthRatio > heightRatio) {
        mySize.rwidth() = defSize.width() * heightRatio;
    }
    else if(widthRatio < heightRatio) {
        mySize.rheight() = defSize.height() * widthRatio;
    }
    QPointF newTopLeft = this->boundingRect().topLeft();
    newTopLeft.rx() += (this->boundingRect().size().width() - mySize.width()) / 2;
    newTopLeft.ry() += (this->boundingRect().size().height() - mySize.height()) / 2;
    QRectF boundingBox(newTopLeft, mySize);
    this->setImplicitWidth(mySize.width());
    this->setImplicitHeight(mySize.height());
    m_renderer->render(painter, boundingBox);
}

SVGCanvas::~SVGCanvas()
{
    delete m_renderer;
}

