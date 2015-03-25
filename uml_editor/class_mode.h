#ifndef CLASS_MODE_H
#define CLASS_MODE_H

#include <QGraphicsSceneMouseEvent>

#include "mode.h"
#include "canvas.h"
#include "class_object.h"

class ClassMode : public Mode
{
    public :
        ClassMode( ) ;
        virtual ~ClassMode( ) ;
        virtual void mousePressEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) ;

        virtual void actionPerformed( ) ;
        virtual void actionPerformed( bool ) ;
        virtual void actionPerformed( QString ) ;
} ;

#endif // CLASS_MODE_H
