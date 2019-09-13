//
//  Base.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>

class Base
{
public:
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Input() = 0;
    virtual void Exit() = 0;
};

#endif /* Base_hpp */
