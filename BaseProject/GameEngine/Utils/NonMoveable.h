//
//  NonMoveable.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 18/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef NonMoveable_h
#define NonMoveable_h

#pragma once

struct NonMovable
{
    NonMovable() = default;
    NonMovable& operator = (NonCopyable&&) = delete;
    NonMovable(NonCopyable&&) = delete;
};

#endif /* NonMoveable_h */
