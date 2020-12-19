/*
 * Event.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: OS1
 */

#include "event.h"

#include "kernelEv.h"
#include "thread.h"

Event::Event(IVTNo ivtNo) {
#ifndef BCC_BLOCK_IGNORE
	lock();
#endif

	myImpl=new KernelEv(ivtNo);

#ifndef BCC_BLOCK_IGNORE
	unlock();
#endif

}

Event::~Event() {
#ifndef BCC_BLOCK_IGNORE
	lock();
#endif

	delete myImpl;

#ifndef BCC_BLOCK_IGNORE
	unlock();
#endif

}

void Event::wait(){
#ifndef BCC_BLOCK_IGNORE
	lock();
#endif

	myImpl->wait();

#ifndef BCC_BLOCK_IGNORE
	unlock();
#endif


}


void Event::signal(){
#ifndef BCC_BLOCK_IGNORE
	lock();
#endif

	myImpl->signal();

#ifndef BCC_BLOCK_IGNORE
	unlock();
#endif
}












