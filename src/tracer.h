#ifndef _TRACER_H_INCLUDED_
#define _TRACER_H_INCLUDED_

/**
* The Tracer class is an interface used for
* traceing inside functions as svn_client_checkout, 
* svn_client_copy, svn_client_import etc, in general 
* for functions requiring a trace editor.
*/
class Tracer
{
public:
	virtual void Trace( const wxString& ) = 0;
};


/**
* A Tracer class for dumping information
* on a wxTextCtrl, locking the GUI in advance.
*/
class TextCtrlTracer
:	public Tracer
{
private:
	wxTextCtrl	*m_txtCtrl;
public:
				TextCtrlTracer( wxTextCtrl* ctrl );

	void		Trace( const wxString& );
};

/**
* A Tracer that sends events to a frame.
*/
class EventTracer
:	public Tracer
{

private:
	wxFrame		*frame;

public:
				EventTracer( wxFrame* fr );

	void		Trace( const wxString& );
};

/**
* A Tracer that put all the messages on a message box
*/

class ErrorTracer
:	public Tracer
{
private:
	wxString	msgs;
	wxWindow	*parent;

public:
				ErrorTracer( wxWindow *__parent );

	virtual		~ErrorTracer();

	void		Trace( const wxString& );
	void		ShowErrors();
};

class StringTracer
:	public Tracer
{
private:
	wxString	&msgs;

public:
				StringTracer( wxString& str );
	void		Trace( const wxString& );
};

#endif
