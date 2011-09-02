#pragma once
#include <QWidget>

class QPushButton;

class RenderThread;

class ControlWidget : public QWidget
{
   Q_OBJECT
   
   public:
      ControlWidget();

   private:
      QPushButton* p_btnRunPause;
      RenderThread* p_ptrThread;
      
   private slots:
      void runPause();
      void stop();
};
