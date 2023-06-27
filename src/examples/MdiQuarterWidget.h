#ifndef MDI_QUARTER_WIDGET_H
#define MDI_QUARTER_WIDGET_H

/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#include <QSize>
#include <QMdiSubWindow>

namespace SIM { namespace Coin3D { namespace Quarter {
  class QuarterWidget;
}}}

class QString;
#if QT_VERSION >= 0x060000
class QOpenGLWidget;
#else
#if defined(QUARTER_USE_QOPENGLWIDGET)
class QOpenGLWidget;
#else
class QGLWidget;
#endif
#endif
using namespace SIM::Coin3D::Quarter;

class MdiQuarterWidget : public QMdiSubWindow {
  typedef QMdiSubWindow inherited;
public:
#if QT_VERSION >= 0x060000
  MdiQuarterWidget(QWidget * parent = 0, const QOpenGLWidget * sharewidget = 0);
#else
#if defined(QUARTER_USE_QOPENGLWIDGET)
  MdiQuarterWidget(QWidget * parent = 0, const QOpenGLWidget * sharewidget = 0);
#else
  MdiQuarterWidget(QWidget* parent = 0, const QGLWidget* sharewidget = 0);
#endif
#endif
  ~MdiQuarterWidget();

  bool loadFile(const QString & filename);
  const QString & currentFile(void) const;
  const QuarterWidget * quarterWidget(void) const;

  virtual QSize minimumSizeHint(void) const;

protected:
  virtual void closeEvent(QCloseEvent * event);

private:
  QString currentfile;
  QuarterWidget * quarterwidget;
};

#endif // MDI_QUARTER_WIDGET_H
