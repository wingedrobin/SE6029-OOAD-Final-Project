#ifndef COMPOSITION_LINE_MODE_H
#define COMPOSITION_LINE_MODE_H

#include "mode.h"
#include "port.h"
#include "canvas.h"
#include "composition_line.h"

class CompositionLineMode : public Mode
{
    public :
        CompositionLineMode( ) ;
        virtual ~CompositionLineMode( ) ;
        virtual void mousePressEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* ) ;
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) ;

        virtual void actionPerformed( ) ;
        virtual void actionPerformed( bool ) ;
        virtual void actionPerformed( QString ) ;

    private :
        Port *startPort ;
        Port *endPort ;
} ;

#endif // COMPOSITION_LINE_MODE
