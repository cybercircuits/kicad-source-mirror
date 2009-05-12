/********************************************/
/* Definitions for the EESchema program:	*/
/********************************************/

#ifndef CLASS_TEXT_LABEL_H
#define CLASS_TEXT_LABEL_H

#include "macros.h"
#include "base_struct.h"

/* Type of SCH_HIERLABEL and SCH_GLOBALLABEL
 * mainly used to handle the graphic associated shape
*/
typedef enum {
    NET_INPUT,
    NET_OUTPUT,
    NET_BIDI,
    NET_TRISTATE,
    NET_UNSPECIFIED,
    NET_TMAX        /* Last value */
} TypeSheetLabel;


extern const char* SheetLabelType[];    /* names of types of labels */

class SCH_TEXT : public SCH_ITEM,
    public EDA_TextStruct
{
public:
    int  m_Layer;
    int  m_Shape;
    bool m_IsDangling;          // true if not connected (used to draw the "not connected" symbol
protected:
    int  m_SchematicOrientation;    /* orientation of texts (comments) and labels in schematic
                                     *  0 = normal (horizontal, left justified).
                                     *  1 = up (vertical)
                                     *  2 =  (horizontal, rignt justified). This can be seen as the mirrored position of 0
                                     *  3 = bottom . This can be seen as the mirrored position of up
                                     *  this is perhaps a duplicate of m_Orient and m_HJustified or m_VJustified,
                                     *  but is more easy to handle that 3 parmeters in editions, Reading and Saving file
                                     */


public:
    SCH_TEXT( const wxPoint& pos = wxPoint( 0, 0 ), const wxString& text = wxEmptyString,
              KICAD_T aType = TYPE_SCH_TEXT );
    ~SCH_TEXT() { }

    virtual wxString GetClass() const
    {
        return wxT( "SCH_TEXT" );
    }


    /** function SetTextOrientAndJustifyParmeters
     * Set m_SchematicOrientation, and initialize
     * m_orient,m_HJustified and m_VJustified, according to the value of m_SchematicOrientation (for a text )
     * must be called after changing m_SchematicOrientation
     * @param aSchematicOrientation =
     *  0 = normal (horizontal, left justified).
     *  1 = up (vertical)
     *  2 =  (horizontal, rignt justified). This can be seen as the mirrored position of 0
     *  3 = bottom . This can be seen as the mirrored position of up
     */
    virtual void  SetSchematicTextOrientation( int aSchematicOrientation );

    int          GetSchematicTextOrientation() { return m_SchematicOrientation;}

    /** function GetSchematicTextOffset (virtual)
     * @return the offset between the SCH_TEXT position and the text itself position
     * This offset depend on orientation, and the type of text
     * (room to draw an associated graphic symbol, or put the text above a wire)
     */
    virtual wxPoint  GetSchematicTextOffset( );

    SCH_TEXT*    GenCopy();
    virtual void Draw( WinEDA_DrawPanel* panel, wxDC* DC, const wxPoint& offset, int draw_mode,
                       int Color = -1 );

    void         SwapData( SCH_TEXT* copyitem );

    void         Place( WinEDA_SchematicFrame* frame, wxDC* DC );

    /** Function HitTest
     * @return true if the point aPosRef is within item area
     * @param aPosRef = a wxPoint to test
     */
    bool         HitTest( const wxPoint& aPosRef );

    EDA_Rect     GetBoundingBox();

    /**
     * Function Save
     * writes the data structures for this object out to a FILE in "*.brd" format.
     * @param aFile The FILE to write to.
     * @return bool - true if success writing else false.
     */
    bool         Save( FILE* aFile ) const;

#if defined(DEBUG)
    void         Show( int nestLevel, std::ostream& os );

#endif
};


class SCH_LABEL : public SCH_TEXT
{
public:
    SCH_LABEL( const wxPoint& pos = wxPoint( 0, 0 ), const wxString& text = wxEmptyString );
    ~SCH_LABEL() { }
    virtual void Draw( WinEDA_DrawPanel* panel, wxDC* DC, const wxPoint& offset, int draw_mode,
                       int Color = -1 );

    virtual wxString GetClass() const
    {
        return wxT( "SCH_LABEL" );
    }


    /** function SetTextOrientAndJustifyParmeters
     * Set m_SchematicOrientation, and initialize
     * m_orient,m_HJustified and m_VJustified, according to the value of m_SchematicOrientation (for a label)
     * must be called after changing m_SchematicOrientation
     * @param aSchematicOrientation =
     *  0 = normal (horizontal, left justified).
     *  1 = up (vertical)
     *  2 =  (horizontal, rignt justified). This can be seen as the mirrored position of 0
     *  3 = bottom . This can be seen as the mirrored position of up
     */
    virtual void  SetSchematicTextOrientation( int aSchematicOrientation );

    /** function GetSchematicTextOffset (virtual)
     * @return the offset between the SCH_TEXT position and the text itself position
     * This offset depend on orientation, and the type of text
     * (room to draw an associated graphic symbol, or put the text above a wire)
     */
    virtual wxPoint  GetSchematicTextOffset( );

    /**
     * Function Save
     * writes the data structures for this object out to a FILE in "*.brd" format.
     * @param aFile The FILE to write to.
     * @return bool - true if success writing else false.
     */
    bool Save( FILE* aFile ) const;
};


class SCH_GLOBALLABEL : public SCH_TEXT
{
public:
    SCH_GLOBALLABEL( const wxPoint& pos = wxPoint( 0, 0 ),
                     const wxString& text = wxEmptyString );
    ~SCH_GLOBALLABEL() { }
    virtual void Draw( WinEDA_DrawPanel* panel, wxDC* DC, const wxPoint& offset, int draw_mode,
                       int Color = -1 );

    virtual wxString GetClass() const
    {
        return wxT( "SCH_GLOBALLABEL" );
    }


    /** function SetTextOrientAndJustifyParmeters
     * Set m_SchematicOrientation, and initialize
     * m_orient,m_HJustified and m_VJustified, according to the value of m_SchematicOrientation
     * must be called after changing m_SchematicOrientation
     * @param aSchematicOrientation =
     *  0 = normal (horizontal, left justified).
     *  1 = up (vertical)
     *  2 =  (horizontal, rignt justified). This can be seen as the mirrored position of 0
     *  3 = bottom . This can be seen as the mirrored position of up
     */
    virtual void  SetSchematicTextOrientation( int aSchematicOrientation );

    /** function GetSchematicTextOffset (virtual)
     * @return the offset between the SCH_TEXT position and the text itself position
     * This offset depend on orientation, and the type of text
     * (room to draw an associated graphic symbol, or put the text above a wire)
     */
    virtual wxPoint  GetSchematicTextOffset( );

    /**
     * Function Save
     * writes the data structures for this object out to a FILE in "*.brd" format.
     * @param aFile The FILE to write to.
     * @return bool - true if success writing else false.
     */
    bool     Save( FILE* aFile ) const;

    /** Function HitTest
     * @return true if the point aPosRef is within item area
     * @param aPosRef = a wxPoint to test
     */
    bool     HitTest( const wxPoint& aPosRef );

    EDA_Rect GetBoundingBox();

    /** function CreateGraphicShape
     * Calculates the graphic shape (a polygon) associated to the text
     * @param aCorner_list = a buffer to fill with polygon corners coordinates
     * @param Pos = Position of the shape
     */
    void     CreateGraphicShape( std::vector <wxPoint>& aCorner_list, const wxPoint& Pos );
};


class SCH_HIERLABEL : public SCH_TEXT
{
public:
    SCH_HIERLABEL( const wxPoint& pos = wxPoint( 0, 0 ),
                   const wxString& text = wxEmptyString );
    ~SCH_HIERLABEL() { }
    virtual void Draw( WinEDA_DrawPanel* panel, wxDC* DC, const wxPoint& offset, int draw_mode,
                       int Color = -1 );

    virtual wxString GetClass() const
    {
        return wxT( "SCH_HIERLABEL" );
    }


    /** function SetTextOrientAndJustifyParmeters
     * Set m_SchematicOrientation, and initialize
     * m_orient,m_HJustified and m_VJustified, according to the value of m_SchematicOrientation
     * must be called after changing m_SchematicOrientation
     * @param aSchematicOrientation =
     *  0 = normal (horizontal, left justified).
     *  1 = up (vertical)
     *  2 =  (horizontal, rignt justified). This can be seen as the mirrored position of 0
     *  3 = bottom . This can be seen as the mirrored position of up
     */
    virtual void  SetSchematicTextOrientation( int aSchematicOrientation );

    /** function GetSchematicTextOffset (virtual)
     * @return the offset between the SCH_TEXT position and the text itself position
     * This offset depend on orientation, and the type of text
     * (room to draw an associated graphic symbol, or put the text above a wire)
     */
    virtual wxPoint  GetSchematicTextOffset( );

    /** function CreateGraphicShape
     * Calculates the graphic shape (a polygon) associated to the text
     * @param aCorner_list = a buffer to fill with polygon corners coordinates
     * @param Pos = Postion of the shape
     */
    void     CreateGraphicShape( std::vector <wxPoint>& aCorner_list, const wxPoint& Pos );

    /**
     * Function Save
     * writes the data structures for this object out to a FILE in "*.brd" format.
     * @param aFile The FILE to write to.
     * @return bool - true if success writing else false.
     */
    bool     Save( FILE* aFile ) const;

    /** Function HitTest
     * @return true if the point aPosRef is within item area
     * @param aPosRef = a wxPoint to test
     */
    bool     HitTest( const wxPoint& aPosRef );

    EDA_Rect GetBoundingBox();
};

#endif /* CLASS_TEXT_LABEL_H */
