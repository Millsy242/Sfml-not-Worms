//
//  NonCopyable.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 18/02/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef NonCopyable_h
#define NonCopyable_h

#pragma once

struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
};

#endif /* NonCopyable_h */
