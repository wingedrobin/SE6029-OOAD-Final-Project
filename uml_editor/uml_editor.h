#ifndef UML_EDITOR_H
#define UML_EDITOR_H

#include <cstdlib>
#include <iostream>

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QGraphicsView>
#include <QLayout>
#include <QInputDialog>
#include <QPushButton>
#include <QButtonGroup>
#include <QActionGroup>

//自定義標頭檔
#include "canvas.h"
#include "class_mode.h"
#include "select_mode.h"
#include "use_case_mode.h"
#include "association_line_mode.h"
#include "composition_line_mode.h"
#include "generalization_line_mode.h"

class UMLEditor : public QWidget
{
    Q_OBJECT

    public :
        //Constructor
        UMLEditor( QWidget * , Qt :: WindowFlags ) ;
        ~UMLEditor( ) ;

    signals :

    private slots :
        void buttonClickedAction( int ) ;
        void actionPerformed( QAction * ) ;

    private :
        Mode *mode ;

        //宣告選單欄
        QMenuBar *menuBar ;

        //宣告選單
        QMenu *fileMenu ;
        QMenu *editMenu ;

        //宣告Edit選單內的功能action
        QAction *groupAction ;
        QAction *ungroupAction ;
        QAction *changeObjectNameAction ;

        //宣告按鈕
        QPushButton *selectButton ;
        QPushButton *associationLineButton ;
        QPushButton *generalizationLineButton ;
        QPushButton *compositionLineButton ;
        QPushButton *classButton ;
        QPushButton *useCaseButton ;

        //宣告按鈕群
        QButtonGroup *buttonGroup ;

        //宣告action群
        QActionGroup *actionGroup ;

        //宣告view區域
        QGraphicsView *graphicsViewArea ;

        //宣告畫布
        Canvas *canvas ;

        //宣告排版
        QVBoxLayout *leftLayout ;
        QHBoxLayout *middleLayout ;
        QVBoxLayout *mainLayout ;

        //Functions
        void createMenus( ) ;
        void createActions( ) ;
        void createButtons( ) ;
        void groupingButtons( ) ;
        void groupingActions( ) ;
        void createViewArea( ) ;
        void setLayouts( ) ;
} ;

#endif // UML_EDITOR_H
