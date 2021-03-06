/*
 * Copyright (C) 2020 KylinSoft Co., Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPUBALLWIDGET_H
#define CPUBALLWIDGET_H

#include <QWidget>
#include <QTimer>
#include <qgsettings.h>
#include <QApplication>

#include "shell/customstyle.h"
#include "../shell/macro.h"

class QGraphicsDropShadowEffect;

class CpuBallWidget : public QWidget
{
    Q_OBJECT

public:
    CpuBallWidget(QWidget *parent = 0);
    ~CpuBallWidget();

    void loadWaveImage();
    void updateCpuPercent(double value);
    void startTimer();
    void stopTimer();
    void initThemeMode();

public slots:
    void onRepaintWaveImage();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QTimer *m_waveTimer = nullptr;
    QGraphicsDropShadowEffect *m_shadowEffect = nullptr;

    QString m_frontImagePath;
    QString m_backimagePath;

    QImage m_frontImage;
    QImage m_backImage;

    QString m_progressText;

    double m_prevPercentValue;
    double m_percentValue;
    double m_xFrontOffset;
    double m_xBackOffset;

    double m_animationCounts;
    int m_animationIndex;

    QGSettings * qtSettings;
    QString currentThemeMode;
};

#endif // CPUBALLWIDGET_H
