#pragma once
#include "ui_mainwindow.h"
#include "TransformModel.hpp"
#include <QMainWindow>
#include <memory>


namespace envire { namespace core 
{
  class EnvireGraph;
}}

namespace envire { namespace viz 
{
  
class EnvireGraphVisualizer;
class Vizkit3dPluginInformation;

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(envire::core::EnvireGraph& graph, const std::string& rootNode);
  
private:
  /**selects the frame named @p name in the 2d listview and 3d window */
  void selectFrame(const QString& name);
  
public slots:
  void addFrame();
  /**Remove the currently selected frame (if any) */
  void removeFrame();
  
  void frameNameAdded(const QString& name);
  void frameNameRemoved(const QString& name);
  
private slots:
  void framePicked(const QString&);
  void listWidgetItemChanged(QListWidgetItem * current, QListWidgetItem * previous);
  /**Invoked if the user changes a transformation */
  void transformChanged(const base::TransformWithCovariance& newValue);
  
private:

  
  
  Ui::MainWindow window;
  envire::core::EnvireGraph& graph;
  std::shared_ptr<EnvireGraphVisualizer> visualzier;//is ptr for lazy instanziation
  std::shared_ptr<Vizkit3dPluginInformation> pluginInfos;//is ptr for lazy instanziation
  QString selectedFrame;//currently selected frame, empty if none
  TransformModel currentTransform;//model of the currently selected transform
};
  
  
  
}}