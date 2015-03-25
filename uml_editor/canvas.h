#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <QGraphicsScene>

//自定義標頭檔
#include "mode.h"
#include "shape.h"
#include "composite.h"
#include "select_mode.h"
#include "association_line_mode.h"
#include "generalization_line_mode.h"
#include "composition_line_mode.h"
#include "class_mode.h"
#include "use_case_mode.h"

class Canvas : public QGraphicsScene
{
    Q_OBJECT

    public :
        virtual ~Canvas( ) ;
        static Canvas *getInstance( ) ;
        static Canvas *getInstance( qreal , qreal , qreal , qreal , QObject * ) ;
        Mode *getCurrentMode( ) ;
        //void draw( ) ;
        //void redraw( ) ;
        void addShape( Shape* ) ;
        void remove( Composite* ) ;
        void setSModeFlag( bool ) ;
        std :: vector< Shape* > *getShapes( ) ;

    //public slots :
        void setCurrentMode( Mode* ) ;

    //signals :

    protected :
        virtual void mousePressEvent( QGraphicsSceneMouseEvent * ) ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent * ) ;
        virtual void mouseMoveEvent( QGraphicsSceneMouseEvent * ) ;

    private :
        static Canvas *uniqueInstance ;     //唯一的Canvas instance
        Mode *currentMode ;                 //宣告畫布模式
        std :: vector< Shape* > shapes ;    //儲存畫布中的Shape
        bool sModeFlag ;

        Canvas( ) ;
        Canvas( qreal , qreal , qreal , qreal , QObject * ) ;
} ;

#endif // CANVAS_H
