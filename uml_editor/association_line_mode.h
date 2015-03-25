#ifndef ASSOCIATION_LINE_MODE_H
#define ASSOCIATION_LINE_MODE_H

#include "mode.h"
#include "shape.h"
#include "canvas.h"
#include "association_line.h"

class AssociationLineMode : public Mode
{
    public :
        /**
         * @brief AssociationLineMode
         *
         * AssociationLineMode的預設建構子
         */
        AssociationLineMode( ) ;

        /**
         * @brief ~AssociationLineMode
         *
         * AssociationLineMode的解構子
         */
        virtual ~AssociationLineMode( ) ;

        /**
         * @brief mousePressEvent
         *
         * 處理Canvas上的mouse press event
         */
        virtual void mousePressEvent( QGraphicsSceneMouseEvent* ) ;

        /**
         * @brief mousePressEvent
         *
         * 處理Canvas上的mouse release event
         */
        virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* ) ;

        /**
         * @brief mousePressEvent
         *
         * 處理Canvas上的mouse drag event
         */
        virtual void mouseDragEvent(QGraphicsSceneMouseEvent* ) ;

        virtual void actionPerformed( ) ;
        virtual void actionPerformed( bool ) ;
        virtual void actionPerformed( QString ) ;

    private :
        Port *startPort ;       //line的起始點
        Port *endPort ;         //line的終點
} ;

#endif // ASSOCIATION_LINE_MODE_H
