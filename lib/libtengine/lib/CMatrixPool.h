#ifndef CMATRIXPOOL_LIB_H
#define CMATRIXPOOL_LIB_H

#include "types/CMatrixPool.h"

extern void CMatrixPool__Advance(CMatrixPool* pThis);
#ifdef GAME_TUROK3
#ifdef RELEASE_US
asm("CMatrixPool__Advance = 0x0026AA90");
#elif RELEASE_EU
#warning "This does not yet support EU!"
#elif RELEASE_N4TKER18
#warning "This does not yet support N4TKER18!"
#elif RELEASE_N4TKER15
#warning "This does not yet support N4TKER15!"
#elif RELEASE_N4TKER10
#warning "This does not yet support N4TKER10!"
#elif RELEASE_N4TKER09
#warning "This does not yet support N4TKER09!"
#endif
#endif

extern void CMatrixPool__Construct(CMatrixPool* pThis, Mtx* Matrices, int nTotal);
#ifdef GAME_TUROK3
#ifdef RELEASE_US
asm("CMatrixPool__Construct = 0x00448CC0");
#elif RELEASE_EU
#warning "This does not yet support EU!"
#elif RELEASE_N4TKER18
#warning "This does not yet support N4TKER18!"
#elif RELEASE_N4TKER15
#warning "This does not yet support N4TKER15!"
#elif RELEASE_N4TKER10
#warning "This does not yet support N4TKER10!"
#elif RELEASE_N4TKER09
#warning "This does not yet support N4TKER09!"
#endif
#endif

#endif

