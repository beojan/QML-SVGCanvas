#include "svgcanvas_plugin.h"
#include "svgcanvas.h"

#include <qqml.h>

void SVGCanvasPlugin::registerTypes(const char *uri)
{
    // @uri SvgCanvas
    qmlRegisterType<SVGCanvas>(uri, 1, 0, "SVGCanvas");
}


