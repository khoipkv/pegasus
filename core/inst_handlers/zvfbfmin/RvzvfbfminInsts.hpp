#pragma once

#include "core/InstHandlers.hpp"
#include "core/inst_handlers/v/RvvFloatInsts.hpp"

namespace pegasus
{
    class PegasusState;

    class RvzvfbfminInsts : public RvvFloatInsts
    {
      public:
        using base_type = RvzvfbfminInsts;

        template <typename XLEN> static void getInstHandlers(InstHandlers::InstHandlersMap &);
    };
} // namespace pegasus
