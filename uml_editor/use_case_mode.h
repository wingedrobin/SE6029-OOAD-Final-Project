#ifndef USE_CASE_MODE_H
#define USE_CASE_MODE_H

#include "mode.h"
#include "canvas.h"
#include "use_case_object.h"

class UseCaseMode : public Mode
{
    public :
        UseCaseMode( ) ;
        virtual ~UseCaseMode( ) ;
        virtual void mousePressEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) ;

        virtual void actionPerformed( ) ;
        virtual void actionPerformed( bool ) ;
        virtual void actionPerformed( QString ) ;
} ;

#endif // USE_CASE_MODE_H
