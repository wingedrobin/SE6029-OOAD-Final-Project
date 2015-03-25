#ifndef SELECT_MODE_H
#define SELECT_MODE_H

#include <QInputDialog>
#include <QDrag>

#include "mode.h"
#include "shape.h"
#include "canvas.h"

class SelectMode : public Mode
{
    public :
        SelectMode( ) ;
        virtual ~SelectMode( ) ;
        virtual void mousePressEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseClickEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) ;

    private slots :
        virtual void actionPerformed( ) ;
        virtual void actionPerformed( bool ) ;
        virtual void actionPerformed( QString ) ;

    private :
        QPointF pressedPos ;
        QPointF releasedPos ;
} ;

#endif // SELECT_MODE_H
