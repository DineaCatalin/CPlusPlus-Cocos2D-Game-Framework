//
//  IDGenerator.h
//  CodePlayground
//
//  Created by Catalin Dinea on 9/16/19.
//  Copyright © 2019 Aeria Games. All rights reserved.
//

#ifndef IDGenerator_h
#define IDGenerator_h

class IDGenerator{
  
public:
    static int getNextID();
    
private:
    static int m_currentID;
};

#endif /* IDGenerator_h */
