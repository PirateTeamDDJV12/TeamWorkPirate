/*
Created by Sun-lay Gagneux
*/
#include "Triangle.h"

#include <algorithm>

using namespace FieldConverter;


std::string Triangle::toString() const noexcept
{
    std::string intermediary("");

    std::for_each(begin(), 
                  end(), 
                  [&intermediary, this](unsigned int iter) {
                    intermediary += std::to_string(iter) + " "; 
                  }
    );

    return (intermediary + "\n");
}
