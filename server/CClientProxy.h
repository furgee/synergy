#ifndef CCLIENTPROXY_H
#define CCLIENTPROXY_H

#include "IClient.h"
#include "CString.h"

class IInputStream;
class IOutputStream;
class IServer;

//! Generic proxy for client
class CClientProxy : public IClient {
public:
	/*!
	\c name is the name of the client.
	*/
	CClientProxy(IServer* server, const CString& name,
							IInputStream* adoptedInput,
							IOutputStream* adoptedOutput);
	~CClientProxy();

	//! @name accessors
	//@{

	//! Get server
	/*!
	Returns the server passed to the c'tor.
	*/
	IServer*			getServer() const;

	//! Get input stream
	/*!
	Returns the input stream passed to the c'tor.
	*/
	IInputStream*		getInputStream() const;

	//! Get output stream
	/*!
	Returns the output stream passed to the c'tor.
	*/
	IOutputStream*		getOutputStream() const;

	//@}

	// IClient overrides
	virtual bool		open() = 0;
	virtual void		run() = 0;
	virtual void		close() = 0;
	virtual void		enter(SInt32 xAbs, SInt32 yAbs,
							UInt32 seqNum, KeyModifierMask mask,
							bool forScreensaver) = 0;
	virtual bool		leave() = 0;
	virtual void		setClipboard(ClipboardID, const CString&) = 0;
	virtual void		grabClipboard(ClipboardID) = 0;
	virtual void		setClipboardDirty(ClipboardID, bool) = 0;
	virtual void		keyDown(KeyID, KeyModifierMask) = 0;
	virtual void		keyRepeat(KeyID, KeyModifierMask, SInt32 count) = 0;
	virtual void		keyUp(KeyID, KeyModifierMask) = 0;
	virtual void		mouseDown(ButtonID) = 0;
	virtual void		mouseUp(ButtonID) = 0;
	virtual void		mouseMove(SInt32 xAbs, SInt32 yAbs) = 0;
	virtual void		mouseWheel(SInt32 delta) = 0;
	virtual void		screensaver(bool activate) = 0;
	virtual CString		getName() const;
	virtual SInt32		getJumpZoneSize() const = 0;
	virtual void		getShape(SInt32& x, SInt32& y,
							SInt32& width, SInt32& height) const = 0;
	virtual void		getCursorPos(SInt32& x, SInt32& y) const = 0;
	virtual void		getCursorCenter(SInt32& x, SInt32& y) const = 0;

private:
	IServer*			m_server;
	CString				m_name;
	IInputStream*		m_input;
	IOutputStream*		m_output;
};

#endif
