/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

#ifndef TOOLKIT_H      
#define TOOLKIT_H

#include "nsIToolkit.h"
#include "LPeriodical.h"
struct PLEventQueue;
class nsWindow;

struct MethodInfo;

/**
 * Wrapper around the thread running the message pump.
 * The toolkit abstraction is necessary because the message pump must
 * execute within the same thread that created the widget under Win32.
 */ 

class nsToolkit : public nsIToolkit, public LPeriodical
{

public:
  nsToolkit();
  virtual			~nsToolkit();
  
  NS_DECL_ISUPPORTS
    
  NS_IMETHOD  		Init(PRThread *aThread);
  
public:
	void 			SetFocus(nsWindow *aFocusWidget);
	nsWindow*		GetFocus() {return(mFocusedWidget);}
	
	// Event Queue
	static PLEventQueue*	GetEventQueue(){ return sPLEventQueue; }
	// LPeriodical interface
	virtual	void	SpendTime(const EventRecord& inMacEvent);

private:
	static nsWindow*	mFocusedWidget;
	static PLEventQueue*	sPLEventQueue;
};



#endif  // TOOLKIT_H
