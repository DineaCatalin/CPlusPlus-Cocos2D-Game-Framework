//
//  CommonMacros.h
//  MyGame
//
//  Created by Catalin Dinea on 9/30/19.
//

#ifndef CommonMacros_h
#define CommonMacros_h

#define CREATE_INSTANCE(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

#endif /* CommonMacros_h */
