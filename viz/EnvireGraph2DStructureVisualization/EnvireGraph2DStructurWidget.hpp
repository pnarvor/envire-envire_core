//
// Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#pragma once

#include <QtGui>

#ifndef Q_MOC_RUN
//workaround for qt bug ( 4.7.3, 4.7.4, 4.8.0, 4.8.1 ) with boost 1.48
//https://bugreports.qt.io/browse/QTBUG-22829
#include <envire_core/graph/EnvireGraph.hpp>
#endif

#include <gvc.h>

class QSvgRenderer;
class QGraphicsSvgItem;
class QZoomableGraphicsView;

namespace envire { namespace viz {

class EnvireGraph2DStructurWidget : public QWidget
{
    Q_OBJECT
public:
    EnvireGraph2DStructurWidget(QWidget *parent = 0);
    ~EnvireGraph2DStructurWidget();
    
public slots:
    /** @param svgString The graph in svg format */
    void displayGraph(const QString& dotStr);
    
private:
    QGraphicsScene* scene; /**The scene displaying the current graph */
    QSvgRenderer* renderer;
    QGraphicsSvgItem* item;
    QZoomableGraphicsView* view;
    GVC_t* gvc;
};
}}
