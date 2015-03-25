#ifndef GENERALIZATION_LINE_MODE_H
#define GENERALIZATION_LINE_MODE_H

#include "mode.h"
#include "port.h"
#include "canvas.h"
#include "generalization_line.h"

class GeneralizationLineMode : public Mode
{
    public :
        GeneralizationLineMode( ) ;
        virtual ~GeneralizationLineMode( ) ;
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

#endif // GENERALIZATION_LINE_MODE_H
